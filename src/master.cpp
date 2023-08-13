#include "master.h"
#include "C:\CodeProjects\TTRPGTools\src\globalest_vars.h"
using namespace std;
vector<pair<string, vector<string>>> std::get_settings(string setting, string path_to_game){
    vector<pair<string, vector<string>>> return_settings;
    if (setting[0] != '['){
        if(verbose_mode) cout << "Error: Setting must start with [" << endl;//Verbose
        return vector<pair<string, vector<string>>>();
    }

    //Open file at _path_to_game
    if(verbose_mode) cout << "Opening file at " << path_to_game << endl;//Verbose
    ifstream file;
    file.open(path_to_game);
    //If no file at _path_to_game, return empty vector
    if (file.fail()){ 
        if(verbose_mode) cout << "Error: No file at " << path_to_game << endl;//Verbose
        return vector<pair<string, vector<string>>>();
    };
    //Search for string setting
    string line;
    bool found_it = false;
    if(verbose_mode) cout << "Searching for " << setting << endl;//Verbose
    while(getline(file, line)){
        if(verbose_mode) cout << "Searching line: " << line << endl;//Verbose
        //Ignore lines starting with "#"
        if (line[0] == '#'){
            if(verbose_mode) cout << "Line starts with #, ignoring" << endl;//Verbose
            continue;
        }
        //While it hasnt been found, keep searching
        if (!found_it){

            if (line.find(setting) != string::npos){
                if(verbose_mode) cout << "Setting found!" << endl;//Verbose
                found_it = true;
                continue;
            }
        }
        
        //It has been found!
        
        //Once found, for each line of text until  the next string starting with "[" is found, split the line into vector of strings separated by "=" and ","//

        //Check if next line starts with "["
        //Break in the case we already found the setting we want but the next line is another setting
        if ((line.find("[") != string::npos)&&(found_it)){
            if(verbose_mode) cout << "Next line is another setting, breaking" << endl;//Verbose
            break;
        }
        //Continue if next line starts with "[" and does not contain setting
        if ((line.find("[") != string::npos)&&(line.find(setting) == string::npos)){
            if(verbose_mode) cout << "Next line is another setting (wanted setting not found yet), continuing" << endl;//Verbose
            continue;
        }
        //Continue if next line does not start with "[" and we have not found setting yet
        if ((line.find("[") == string::npos)&&(!found_it)){
            //Redundant?
            if(verbose_mode) cout << "Next line is not another setting (wanted setting not found yet), continuing" << endl;//Verbose
            continue;
        }

        //Split line into vector of strings separated by "="
        vector<string> split_line_equal;

        stringstream ss(line);
        string str;

        while (getline(ss, str, '=')){
            split_line_equal.push_back(str);
        }

        //First string is the setting name
        string setting_name = split_line_equal[0];
        //Delete first 3 characters of setting name (the "{", the int, and the "}")
        setting_name.erase(0,3);
        string setting_values = split_line_equal[1];

        //Split line into vector of strings separated by ","
        //Remaining strings are the values and stored in a vector
        vector<string> split_line_comma;

        stringstream ss1(setting_values);
        string str1;

        while (getline(ss1, str1, ',')){
            split_line_comma.push_back(str1);
        }

        vector<string> setting_values_vector = split_line_comma;

        //One more setting complete!
        pair<string, vector<string>> setting_pair = make_pair(setting_name, setting_values_vector);

        return_settings.push_back(setting_pair);


    }
    if(verbose_mode) cout << "Closing file" << endl;//Verbose
    file.close();
    //If found, return the settings
    if (found_it){
        if(verbose_mode) cout << "Returning settings..." << endl;//Verbose
        return return_settings;
    }
    //If not found, return empty vector
    if(verbose_mode) cout << "Error: Setting not found, returning empty vector" << endl;//Verbose
    return vector<pair<string, vector<string>>>();

};

map<string,map<string,vector<string>>> get_all_settings(string path_to_game){
    map<string,map<string,vector<string>>> return_settings;

    //Open file at _path_to_game
    if(verbose_mode) cout << "Opening file at " << path_to_game << endl;//Verbose
    ifstream file;
    file.open(path_to_game);
    //If no file at _path_to_game, return empty vector
    if (file.fail()){ 
        if(verbose_mode) cout << "Error: No file at " << path_to_game << endl;//Verbose
        return map<string,map<string,vector<string>>>();
    };
 
    string line;
    //Flag to check for orphan settings
    bool orphan_setting = true; //AKA setting before a category

    while(getline(file, line)){

        //Handling setting robustness, one line at a time

        if(verbose_mode) cout << "Parsing line: " << line << endl;//Verbose
        //Ignore lines starting with "#"
        if ((line[0] == '#') or (line[0] != '[') ){
            if(verbose_mode) cout << "Line starts with #  or is empty, ignoring" << endl;//Verbose
            continue;
        }
        //Enforce format

        //0 is setting, 1 is subsetting, 2 is error
        int setting_sub_error = 2;

        //We consider a setting to start with "[" and end with "]", NOT mattering what is in between
        if (line[0] == '['){
            orphan_setting = false;
            //Is setting
            string subline = line.substr(1,line.size());
            if (subline.back() == ']'){
                //Is setting
                setting_sub_error = 0;
            }else{
                //Is subsetting
                if (verbose_mode) cout << "Error: A setting must start with [ and end with ]" << endl;//Verbose
                return map<string,map<string,vector<string>>>();
            }

        }
        //Handling subsetting robustness
        if (line[0] == '{'){
            if (orphan_setting){
                if(verbose_mode) cout << "Error: Subsetting before setting" << endl;//Verbose
                return map<string,map<string,vector<string>>>();
            }
            //Check if next char is a number between 0 and 3

            if ((int)line[1] >= 0 &&  (int)line[1] <= 3){
                if(line[2] == '}'){
                    //So far, we know it starts with format {int}, need to corroborate that the next part follows format:thing=thing1,thing2,thing3
                    string subline = line.substr(3,line.size());
                    //Process subline to have no spaces
                    subline.erase(remove(subline.begin(), subline.end(), ' '), subline.end());
                    //See if we can split the subline into 2 parts, separated by "="
                    auto equal_pos = subline.find('=');
                    if(equal_pos != string::npos){
                        //Check if subsetting is unasigned, AKA no value after "="
                        if (subline.size() == equal_pos+1){
                            if(verbose_mode) cout << "Error: Subsetting must be initialized, AKA have value after =" << endl;//Verbose
                            return map<string,map<string,vector<string>>>();
                        }
                        setting_sub_error = 1;
                    }else{
                        if(verbose_mode) cout << "Error: Subsetting missing assignment delimiter =" << endl;//Verbose
                        return map<string,map<string,vector<string>>>();
                    }
                }else{
                    if(verbose_mode) cout << "Error: Third letter in subsetting line is not }" << endl;//Verbose
                    return map<string,map<string,vector<string>>>();
                }
            }


        }
        if (setting_sub_error == 2){
            if(verbose_mode) cout << "Error: Invalid line type or does not follow format" << endl;//Verbose
            return map<string,map<string,vector<string>>>();
        }
        
        //map<string,map<string,vector<string>>> return_settings;
        //return_settings[setting_name][subsetting_name] = vector<string> subsetting_values;
        //Settings start with "["
        //Subsettings start with "{int}" and have the format: subsetting_name=subsetting_value1,subsetting_value2,subsetting_value3
        
        if (setting_sub_error == 0){
            if(verbose_mode) cout << "Next line is a setting" << endl;//Verbose
        }
    
        //Subsettings start with "{int}" and have the format: subsetting_name=subsetting_value1,subsetting_value2,subsetting_value3
        if (setting_sub_error == 1){
            if(verbose_mode) cout << "Next line is a sub-setting" << endl;//Verbose
        }

        //Split line into vector of strings separated by "="
        vector<string> split_line_equal;

        stringstream ss(line);
        string str;

        while (getline(ss, str, '=')){
            split_line_equal.push_back(str);
        }

        //First string is the setting name
        string setting_name = split_line_equal[0];
        //Delete first 3 characters of setting name (the "{", the int, and the "}")
        setting_name.erase(0,3);
        string setting_values = split_line_equal[1];

        //Split line into vector of strings separated by ","
        //Remaining strings are the values and stored in a vector
        vector<string> split_line_comma;

        stringstream ss1(setting_values);
        string str1;

        while (getline(ss1, str1, ',')){
            split_line_comma.push_back(str1);
        }

        vector<string> setting_values_vector = split_line_comma;

        //One more setting complete!
        pair<string, vector<string>> setting_pair = make_pair(setting_name, setting_values_vector);

        return_settings.push_back(setting_pair);


    }
    if(verbose_mode) cout << "Closing file" << endl;//Verbose
    file.close();
    //If found, return the settings
    if (found_it){
        if(verbose_mode) cout << "Returning settings..." << endl;//Verbose
        return return_settings;
    }
    //If not found, return empty object
    if(verbose_mode) cout << "Error: Setting not found, returning empty vector" << endl;//Verbose
    return map<string,map<string,vector<string>>>();
};

//Return normal type complex object, then reconstruct it in the pertaining class(es)

//Game Config Class

game_config::game_config(string path_to_game){

};
game_config::~game_config(){
    
};
int game_config::refresh_settings(){
    
};

//Setting Class
setting::setting(string settings, vector<string> sub_settings, vector<int> sub_setting_types){
    
};
setting::~setting(){
    
};
int setting::refresh_sub_settings(){
    
};