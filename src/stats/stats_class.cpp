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
    if(found == _Stats.end()) return make_pair(-1,-1);
    pair<int, int> return_stat = found->second;
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
    cout << "Stats Constructor Called" << endl;
    //Might need to initialize _Stats_Num and _Stats
    //Extract stats from _path_to_game
    string setting = "[Stat Data]";
    vector<pair<string, vector<string>>> stats_settings = get_settings(setting, _path_to_game);
    //Error if _path_to_game is not valid
    if(stats_settings.size() == 0) throw invalid_argument("Invalid path to game");
    //Get number of stats at _path_to_game
    _Stats_Num = stats_settings[0].second.size();
     //If _stats.size() != number of stats, error
    if(_Stats_Num != _stats.size()) throw invalid_argument("Invalid number of stats");
        //Maybe throw error if the stats are TOO rediculous
    //Initizalize vector of stats in the form (StatName(Value,Modifier))
    //Initialize _Stats by setting each stat to  those in _stats
    for(int i = 0; i < _Stats_Num; i++){
        string stat_name = stats_settings[0].second[i];
        pair<int,int> stat_val = make_pair(_stats.front(),0);
        _stats.pop_front();
        _Stats[stat_name] = stat_val;
        //_Stats.push_back(stat_name);
        //_Stats_Vals.push_back(stat_val);
    }
    //Sanity check
    //if(_Stats.size() != _Stats_Vals.size()) throw invalid_argument("Error in stats constructor, _Stats and _Stats_Vals are not the same size");
    //Update modifiers
    int update_return = update_mod("all");
    //Error if update_mod returns -1
    if(update_return == -1) throw invalid_argument("Error in stats constructor, update_mod returned -1");
    //Return?
};

//Destructor
std::stats::~stats(){
    cout << "Stats Destructor Called" << endl;
    //Delete _Stats
    if(_Stats.size() > 0){
        /*for(map<string,pair<int,int>>::iterator it=_Stats.begin() ; it!=_Stats.end() ; it++){
            delete &((it->second).first);
            delete &((it->second).second);
            delete &(it->second);
            delete &(it->first);
        }*/
        _Stats.clear();
    }
    //Delete _Num_Stats
    _Stats_Num = 0;
    delete &_Stats_Num;
    //Delete Pointer?
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
            int val = iter->second.first;
            //Update modifier
            //Rounded down
            int mod = (val - 10)/2;
            iter->second.second = mod;
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

//Allocation Types

//Standard Array
void std::stats::std_array(list<int> values){
};

//Point Buy
void std::stats::point_buy(list<int> values){
};

//Random
void std::stats::random_alloc(){
};

//Manual
void std::stats::manual_alloc(list<int> values){
};