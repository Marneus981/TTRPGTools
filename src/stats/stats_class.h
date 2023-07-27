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


        protected:

           

            //Number of Stats
            int _Stats_Num;

            //Vector of Stats (StatName,(Value,Modifier))
            map<string, pair<int, int>> _Stats;
            //vector<string> _Stats;
            //vector<pair<int,int>>  _Stats_Vals;

            //Set Value
            int set_stat_val(string stat, int val);

            //Update Modifier according to Modifier Table
            //In:StatName
            int update_mod(string stat);

            //Allocation Types
            void std_array(list<int> values);
            void point_buy(list<int> values);
            void random_alloc();
            void manual_alloc(list<int> values);

    }; 
}