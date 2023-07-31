#pragma once
//STATS_CLASS.H/.CPP
#include <vector>
#include <string>-
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <conio.h>

namespace std{
    vector<pair<string, vector<string>>> get_settings(string setting, string path_to_game);

    class setting{
        public:
            setting();
            ~setting();
            int refresh_sub_settings();
        protected:
        private:
            map<string, vector<string>> _sub_settings;
            map<string,int> _setting_types;

    };
    class game_config {
        public:
            game_config(string path_to_game);
            ~game_config();
            int refresh_settings();
        protected:
        private:
            string _path_to_game;
            map<string, vector<setting>> _settings;
    };
}




