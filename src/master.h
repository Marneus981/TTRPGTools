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
        public:
            setting(string settings, vector<string> sub_settings, vector<int> sub_setting_types);
            ~setting();
            int refresh_sub_settings();
        protected:
        private:
            map<string, vector<string>> _Sub_Settings;
            map<string,int> _Types;

    };
    class game_config {
        public:
            game_config(string path_to_game);
            ~game_config();
            int refresh_settings();
        protected:
        private:
            string _Path_To_Game;
            map<string, vector<setting>> _Settings;
    };
}




