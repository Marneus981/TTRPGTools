#pragma once
//STATS_CLASS.H/.CPP
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <conio.h>

namespace std{
    //Below is a legacy function, probably getting rid of it
    vector<pair<string, vector<string>>> get_settings(string setting, string path_to_game);
    
    class setting{
        friend setting parse_settings(string path_to_game);
        public:
            setting(string settings, vector<string> sub_settings, vector<int> sub_setting_types);
            ~setting();
            int refresh_sub_settings();
            //Set function?
            //Get function?
        protected:
        private:
            map<string, vector<string>> _Sub_Settings;
            map<string,int> _Types;
            //Types: {0: int, 1: float, 2: string, 3: bool}

    };
    class game_config {
        friend setting parse_settings(string path_to_game);
        public:
            game_config(string path_to_game);
            ~game_config();
            int refresh_settings();
            //Set function?
            //Get function?
        protected:
        private:
            string _Path_To_Game;
            map<string, vector<setting>> _Settings;
    };
    //Setting parser
    setting parse_settings(string path_to_game);
}




