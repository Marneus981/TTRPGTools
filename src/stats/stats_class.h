#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "C:\CodeProjects\TTRPGTools\src\master.h"

namespace std{
    class stats{
        private:
        public:

            //Get
            pair<int,int> get_stat(string stat);

            //Constructor
            stats(list<int> _stats, string _path_to_game);
            //Destructor
            ~stats();

            //MIGHT need to move this to protected

            //Set Value
            int set_stat_val(string stat, int val);

            //Change Value by amount
            int change_stat_val(string stat, int amount);

            //Update Modifier according to Modifier Table
            //In:StatName
            int update_mod(string stat);

            //Allocation Type Helpers
            list<int> std_array();
            pair<int,list<int>> point_buy(list<int> values);
            list<int> random_stats(int min, int max);
            //void manual_alloc(list<int> values); Basically just standard constructor



        protected:

           
            //Path to Game
                //Should only be asigned in constructor
            string _Game_Path;
            //Number of Stats
            int _Stats_Num;

            //Vector of Stats (StatName,(Value,Modifier))
            map<string, pair<int, int>> _Stats;
            //vector<string> _Stats;
            //vector<pair<int,int>>  _Stats_Vals;


    }; 
}