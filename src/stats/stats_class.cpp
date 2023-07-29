/* Stat class DnD 5e*/
#include "stats_class.h"
#include "C:\CodeProjects\TTRPGTools\src\globalest_vars.h"  

//TO DO
/*
*/
using namespace std;
// CLASS METHODS DEFINED
//Get
pair<int, int> stats::get_stat(string stat){

    auto found = _Stats.find(stat);
    //Error:Stat name not found!
    if(found == _Stats.end()){ 
        if (verbose_mode) cout << "Error in get_stat, stat not found" << endl;
        return make_pair(-1,-1);
    };
    pair<int, int> return_stat = found->second;
    if (verbose_mode) cout << "Found stat: " << stat << " with value: " << return_stat.first << " and modifier: " << return_stat.second << endl;
    return return_stat;

    /*//Lambda function to find stat in vector
    string wanted(stat);
    auto it = find_if( _Stats.begin(), _Stats.end(),
        [&wanted](const pair<string, pair<int, int>>& element){
             return element.first == wanted; 
        });
    //Error:Stat name not found!
    if(it ==_Stats.end()) return make_pair(-1,-1);
    pair<int, int> return_stat = it->second;
    return return_stat;*/

};

//Constructor
stats::stats(list<int> _stats, string _path_to_game){
    if (verbose_mode) cout << "Stats Constructor Called" << endl;
    //Check if stats is empty,beacuse that would be stupid (aka an error, because that would only be implemented in the case of another constructor)
    if (_stats.size() == 0){ 
        throw invalid_argument("Error in stats constructor, _stats is empty");
    };
    //Might need to initialize _Stats_Num and _Stats
    //Extract stats from _path_to_game
    string setting = "[Stat Data]";
    if (verbose_mode) cout << "Getting settings from " << _path_to_game << endl;
    vector<pair<string, vector<string>>> stats_settings = get_settings(setting, _path_to_game);
    //Error if _path_to_game is not valid
    if(stats_settings.size() == 0){ 
        if (verbose_mode) cout << "Error in stats constructor, invalid path to game" << endl;
        throw invalid_argument("Invalid path to game");
    };
    _Game_Path = _path_to_game;
    //Get number of stats at _path_to_game
    if (verbose_mode) cout << "Getting number of stats" << endl;
    _Stats_Num = stats_settings[0].second.size();
    if (verbose_mode) cout << "Number of stats: " << _Stats_Num << endl;
     //If _stats.size() != number of stats, error
    if(_Stats_Num != _stats.size()){
        if (verbose_mode) cout << "Error in stats constructor, invalid number of stats (Destructor SHOULD be called)" << endl;
        throw invalid_argument("Invalid number of stats");
    };
        //Maybe throw error if the stats are TOO rediculous
    //Initizalize vector of stats in the form (StatName(Value,Modifier))
    //Initialize _Stats by setting each stat to  those in _stats
    if (verbose_mode) cout << "Initializing _Stats" << endl;
    for(int i = 0; i < _Stats_Num; i++){
        string stat_name = stats_settings[0].second[i];
        pair<int,int> stat_val = make_pair(_stats.front(),0);
        if (verbose_mode) cout << "Adding stat: " << stat_name << " with value: " << stat_val.first << " and modifier: " << stat_val.second << endl;
        _stats.pop_front();
        _Stats[stat_name] = stat_val;
        //_Stats.push_back(stat_name);
        //_Stats_Vals.push_back(stat_val);
    }
    //Sanity check
    //if(_Stats.size() != _Stats_Vals.size()) throw invalid_argument("Error in stats constructor, _Stats and _Stats_Vals are not the same size");
    //Update modifiers
    if (verbose_mode) cout << "Updating modifiers" << endl;
    int update_return = update_mod("all");
    //Error if update_mod returns -1
    if(update_return == -1){
        if (verbose_mode) cout << "Error in stats constructor, update_mod returned -1 (Destructor SHOULD be called bc of THROW)" << endl;
        throw invalid_argument("Error in stats constructor, update_mod returned -1");
    };
    //Return?
};

//Destructor
std::stats::~stats(){
    if (verbose_mode) cout << "Stats Destructor Called" << endl;
    //Delete _Stats
    if(verbose_mode) cout << "Deleting _Stats" << endl;
    if(_Stats.size() > 0){
        /*for(map<string,pair<int,int>>::iterator it=_Stats.begin() ; it!=_Stats.end() ; it++){
            delete &((it->second).first);
            delete &((it->second).second);
            delete &(it->second);
            delete &(it->first);
        }*/
        _Stats.clear();
    }
    //Sanity Check
    //Not my problem if it fails
    if(_Stats.size() != 0) cout << "Error in stats destructor, _Stats not empty" << endl;
    //Delete _Num_Stats
    if(verbose_mode) cout << "Deleting _Stats_Num" << endl;
    _Stats_Num = 0;
    //delete _Stats_Num;
    //Delete Pointer?
    //"Delete" _Game_Path
    if(verbose_mode) cout << "Deleting _Game_Path" << endl;
    _Game_Path = "";
    //Return?
};


//Set
int std::stats::set_stat_val(string stat, int val){
    //Check if stat is in _Stats
    if(_Stats.find(stat) != _Stats.end()){
        _Stats[stat].first = val;
        int update_return = update_mod(stat);
        //Error if update_mod returns -1?
        return 0;
    }else{
        cout << "Error in set_stat_val, stat not found" << endl;
        return -1;
    };

};

//Update Modifiers
int std::stats::update_mod(string stat){
    if(stat == "all"){
        /*for(int i = 0; i < _Stats_Num; i++){
            //Get stat
            //pair<int,int> stat_pair = _Stats_Vals[i];
            //Get value
            int val = stat_pair.first;
            //Get modifier
            int mod = stat_pair.second;
            //Update modifier
            //Rounded down
            mod = (val - 10)/2;
            //Update stat
            stat_pair.second = mod;
            //Update _Stats
            _Stats_Vals[i].second = stat_pair.second;
        }*/
        for(map<string,pair<int,int>>::iterator iter = _Stats.begin(); iter != _Stats.end(); ++iter){
            if (verbose_mode) cout << "Updating stat: " << iter->first << endl;
            if (verbose_mode) cout << "With Value " << iter->second.first << endl;
            int val = iter->second.first;
            //Update modifier
            //Rounded down
            int mod = (val - 10)/2;
            iter->second.second = mod;
            if (verbose_mode) cout << "And Modifier " << iter->second.second << endl;
        }
        return 0;
    //Check if stat is in _Stats
    }else if(_Stats.find(stat) != _Stats.end()){
    //}else if(find(_Stats.begin(), _Stats.end(), stat) != _Stats.end()){
        //Get stat
        pair<int,int> stat_pair = _Stats[stat];
        //pair<int,int> stat_pair = _Stats_Vals[somethingsomehow];
        //Get value
        int val = stat_pair.first;
        //Get modifier
        int mod = stat_pair.second;
        //Update modifier
        //Rounded down
        mod = (val - 10)/2;
        //Update stat
        stat_pair.second = mod;
        //Update _Stats
        //_Stats_Vals[somethingsomehow] = stat_pair;
        _Stats[stat] = stat_pair;
        return 0;
    }else{
        cout << "Error in update_mod, stat not found or all keyword not input" << endl;
        return -1;
    };
};

int std::stats::change_stat_val(string stat, int amount){
    //Check if stat is in _Stats
    if(_Stats.find(stat) != _Stats.end()){
        _Stats[stat].first += amount;
        int update_return = update_mod(stat);
        //Error if update_mod returns -1?
        if(update_return == -1){
            cout << "Error in change_stat_val, update_mod returned -1" << endl;
            return -1;
        };
        return 0;
    }else{
        cout << "Error in change_stat_val, stat not found" << endl;
        return -1;
    };
};

//Allocation Types Helpers
    //Not allocators, just helpers

//Standard Array
//Returns remaining values to be allocated
//If return is empty, then all values have been allocated
//Values: 15,14,13,12,10,8
//Error return: list of 6 -1's
list<int> std::stats::std_array(){
    //Get std array values using get_settings from _Game_Path
    if (verbose_mode) cout << "Getting std array values" << endl;
    string setting = "[Standard Array]";
    vector<pair<string, vector<string>>> std_array_settings = get_settings(setting, _Game_Path);
    if (std_array_settings.size() == 0){
        cout << "Error in std_array, get_settings failed" << endl;
        return list<int> {-1,-1,-1,-1,-1,-1};
    };
    //Get values from std_array_settings
    if (verbose_mode) cout << "Getting values from std_array_settings" << endl;
    vector<string> std_array_values = std_array_settings[0].second;
    //Transform values from string to int
    if (verbose_mode) cout << "Transforming values from string to int" << endl;
    list<int> std_array_values_int;
    for(int i = 0; i < std_array_values.size(); i++){
        std_array_values_int.push_back(stoi(std_array_values[i]));
    };
    //Not responsible for checking if existing values are different from std_array_values
    //Check for existing std_array_values_int values in _Stats
    if (verbose_mode) cout << "Checking for existing std_array_values_int values in _Stats" << endl;    
    //If size of _Stats != std_array_values_int, return error
    if(_Stats.size() != std_array_values_int.size()){
        cout << "Error in std_array, _Stats size != std_array_values_int size" << endl;
        return list<int> {-1,-1,-1,-1,-1,-1};
    };
    if (verbose_mode) cout << "Checking for existing std_array values in assignment" << endl;
    for(auto iter = _Stats.begin(); iter != _Stats.end(); ++iter){
        auto val_mod_pair = iter->second;
        int val = val_mod_pair.first;
        if(find(std_array_values_int.begin(), std_array_values_int.end(), val) != std_array_values_int.end()){
            if (verbose_mode) cout << "Found existing std_array value: " << val << endl;
            std_array_values_int.remove(val);
        };

    };

    //Return std_array_values_int not found in _Stats
    if (verbose_mode) cout << "Returning std_array_values_int not found in _Stats" << endl;
    return std_array_values_int;
};

//Point Buy
//Returns remaining points to buy stats
//If return is empty, then all points have been used
//Can return negative values
//Negative values indicate that the value is too high
//Error return is pair<int,list<int>> {-1,{-1,-1,-1,-1,-1,-1}}
pair<int,list<int>> std::stats::point_buy(list<int> values){
    //Error return
    pair<int,list<int>> error_return = make_pair(-1,list<int> {-1,-1,-1,-1,-1,-1});
    //Get point buy settings using get_settings from _Game_Path
    if (verbose_mode) cout << "Getting point buy settings" << endl;
    string setting = "[Point Buy]";
    vector<pair<string, vector<string>>> point_buy_settings = get_settings(setting, _Game_Path);
    if (point_buy_settings.size() == 0){
        cout << "Error in point_buy, get_settings failed" << endl;
        return error_return;
    };
    //Get individual setting values from point_buy_settings
    if (verbose_mode) cout << "Getting individual setting values from point_buy_settings" << endl;
    int PtBuyPts = stoi(point_buy_settings[0].second[0]);
    int PtBuyMin = stoi(point_buy_settings[0].second[1]);
    int PtBuyMax = stoi(point_buy_settings[0].second[2]);
    int CostMin = stoi(point_buy_settings[0].second[3]);
    int CostScal = stoi(point_buy_settings[0].second[4]);
    
    //Create array of values ranging from PtBuyMin to PtBuyMax
    int PtBuyRange = PtBuyMax - PtBuyMin + 1;
    int PtBuyValues[PtBuyRange];
    for(int i = 0; i < PtBuyRange; i++){
        PtBuyValues[i] = PtBuyMin + i;
    };
    if (verbose_mode){ 
        cout << "PtBuyValues: ";
        for(int i = 0; i < PtBuyRange; i++){
            cout << PtBuyValues[i] << " ";
        };
        cout << endl;
    };
    //Create array of costs with size previous array, starting at CostMin and increasing by CostScal
    int CostValues[PtBuyRange];
    for(int i = 0; i < PtBuyRange; i++){
        CostValues[i] = CostMin + i*CostScal;
    };
    if (verbose_mode){ 
        cout << "CostValues: ";
        for(int i = 0; i < PtBuyRange; i++){
            cout << CostValues[i] << " ";
        };
        cout << endl;
    };
    //Create point buy table
    if (verbose_mode) cout << "Creating point buy table" << endl;
    map<int,int> PtBuyTable;
    for(int i = 0; i < PtBuyRange; i++){
        PtBuyTable[PtBuyValues[i]] = CostValues[i];
    };
    if (verbose_mode){ 
        cout << "PtBuyTable: ";
        for(map<int,int>::iterator iter = PtBuyTable.begin(); iter != PtBuyTable.end(); ++iter){
            cout << iter->first << ":" << iter->second << " ";
        };
        cout << endl;
    };
    //Check if theres a value in _Stat values that is not in PtBuyTable
    //Create list with values not in PtBuyTable
    //Also create list with values in PtBuyTable
    if (verbose_mode) cout << "Checking if theres a value in _Stat values that is not in PtBuyTable" << endl;
    list<int> PtBuyValuesNotInTable;
    list<int> PtBuyValuesInTable;
    for(int i = 0; i < values.size(); i++){
        auto found = PtBuyTable.find(values.front());
        if(found == PtBuyTable.end()){
            PtBuyValuesNotInTable.push_back(values.front());
        }else{
            PtBuyValuesInTable.push_back(values.front());
        };
        values.pop_front();
    };
    //Make sum of values in PtBuyValuesInTable
    if (verbose_mode) cout << "Making sum of values in PtBuyValuesInTable" << endl;
    int CostSum = 0;
    for(int i = 0; i < PtBuyValuesInTable.size(); i++){
        CostSum += PtBuyTable[PtBuyValuesInTable.front()];
        PtBuyValuesInTable.pop_front();
    };
    //Subtract sum from PtBuyPts
    if (verbose_mode) cout << "Subtracting sum from PtBuyPts: " << PtBuyPts << endl;
    PtBuyPts -= CostSum;
    //Create return object
    pair<int,list<int>> return_pair = make_pair(PtBuyPts,PtBuyValuesNotInTable);
    //Return return_pair
    if (verbose_mode) cout << "Returning return_pair" << endl; 
    return return_pair;
};

//Random
//Randomly allocates values to stats
//Error is list<int> {-1,-1,-1,-1,-1,-1}
list<int> std::stats::random_stats(int min, int max){
    //Sanity check min vs max
    if (verbose_mode) cout << "Sanity check min vs max" << endl;
    if(min > max){
        cout << "Error in random_stats, min > max" << endl;
        return list<int> {-1,-1,-1,-1,-1,-1};
    };
    //Get size of list of stats from _Game_Path
    if (verbose_mode) cout << "Getting size of list of stats from _Game_Path" << endl;
    string setting = "[Stat Data]";
    vector<pair<string, vector<string>>> stats_settings = get_settings(setting, _Game_Path);
    if (stats_settings.size() == 0){
        cout << "Error in random_stats, get_settings failed" << endl;
        return list<int> {-1,-1,-1,-1,-1,-1};
    };
    int stats_size = stats_settings[0].second.size();
    //Generate list random values from specified range
    if (verbose_mode) cout << "Generating list random values from specified range" << endl;
    list<int> random_values;
    for(int i = 0; i < stats_size; i++){
        random_values.push_back(rand() % (max - min + 1) + min);
    };
    //Return list
    if (verbose_mode){ 
        cout << "Returning list with values: ";
        for(int i = 0; i < stats_size; i++){
            cout << random_values.front() << " ";
            random_values.pop_front();
        };
        cout << endl;
    };    
    return random_values;
};

//Manual
//void std::stats::manual_alloc(list<int> values){
//}; Basically just standard constructor
