#include "master.h"
#include "C:\CodeProjects\TTRPGTools\src\globalest_vars.h"
using namespace std;
vector<pair<string, vector<string>>> std::get_settings(string setting, string _path_to_game){
    vector<pair<string, vector<string>>> return_settings;
    if (setting[0] != '['){
        if(verbose_mode) cout << "Error: Setting must start with [" << endl;//Verbose
        return vector<pair<string, vector<string>>>();
    }

    //Open file at _path_to_game
    if(verbose_mode) cout << "Opening file at " << _path_to_game << endl;//Verbose
    ifstream file;
    file.open(_path_to_game);
    //If no file at _path_to_game, return empty vector
    if (file.fail()){ 
        if(verbose_mode) cout << "Error: No file at " << _path_to_game << endl;//Verbose
        return vector<pair<string, vector<string>>>();
    };
    //Search for string setting
    string line;
    bool found_it = false;
    if(verbose_mode) cout << "Searching for " << setting << endl;//Verbose
    while(getline(file, line)){
        if(verbose_mode) cout << "Searching line: " << line << endl;//Verbose
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
        if(verbose_mode) cout << "Returning settings" << endl;//Verbose
        return return_settings;
    }
    //If not found, return empty vector
    if(verbose_mode) cout << "Error: Setting not found, returning empty vector" << endl;//Verbose
    return vector<pair<string, vector<string>>>();

};
//Setting parser
setting parse_settings(string path_to_game);
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