#include "C:\CodeProjects\TTRPGTools\src\master.h"
#include "C:\CodeProjects\TTRPGTools\src\globalest_vars.h"
using namespace std;
//VERBOSE MODE
bool verbose_mode = false;

int main(){
    //Ask the user if they want to turn on Verbose Mode
    cout << "Do you want to turn on Verbose Mode? (y/n)" << endl;
    char input;
    cin >> input;
    if (input == 'y'){
        cout << "Verbose Mode Activated!" << endl;
        verbose_mode = true;
    }
    cout << "Master Tests Initiating!" << endl;
    
    string path_to_game = "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt";
    string setting;
    vector< pair<string,vector<string>>> test1; 
    
    //Test 1: get_settings
    cout << "Test 1: get_settings" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 1: get_settings Skipped!" << endl;
    }else{
        cout << "Test 1.1: get_settings, correct input" << endl;
        //Ask if user wants to skip this test
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 1.1 Skipped!" << endl;
        }else{
            setting = "[Stat Data]";
            test1 = get_settings(setting, path_to_game);
            if (test1.size() == 0){
                cout << "Test 1.1 Failed! Setting not Found" << endl;
            }else{
                cout << "Settings Found!" << endl;
                cout << "Printing Settings:" << endl;
                for (auto it = test1.begin(); it != test1.end(); it++){
                    cout << it->first << ": ";
                    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
                        cout << *it2 << " ";
                    }
                    cout << endl;
                }  
                cout << "Settings Printed!" << endl;
                //Ask if output is correct
                cout << "Is the output correct? (y/n)" << endl;
                char input;
                cin >> input;
                if (input == 'y'){
                    cout << "Test 1.1 Passed!" << endl;
                }else{  
                    cout << "Test 1.1 Failed! Output does not Match Expected Output" << endl;
                }
            }
        }
        cout << "Test 1.2: get_settings, incorrect setting" << endl;
        //Ask if user wants to skip this test
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 1.2 Skipped!" << endl;
        }else{
            setting = "[Wrong Setting]";
            test1 = get_settings(setting, path_to_game);
            if (test1.size() == 0){
                cout << "Test 1.2 Passed! Setting Not Found" << endl;
            }else{
                cout << "Test 1.2 Failed! Setting Found" << endl;
            }
        }
        cout << "Test 1.3: get_settings, incorrect path" << endl;
        //Ask if user wants to skip this test
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 1.3 Skipped!" << endl;
        }else{
            setting = "[Stat Data]";
            path_to_game = "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e_wrong.txt";
            test1 = get_settings(setting, path_to_game);
            if (test1.size() == 0){
                cout << "Test 1.3 Passed! Incorrect Path Detected" << endl;
            }else{
                cout << "Test 1.3 Failed! Incorrect Path Not Detected" << endl;
            }
        }
        cout << "Test 1.4: get_settings, setting not starting with [" << endl;
        //Ask if user wants to skip this test
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 1.4 Skipped!" << endl;
        }else{
        setting = "Stat Data]";
        path_to_game = "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt";
        test1 = get_settings(setting, path_to_game);
        if (test1.size() == 0){
            cout << "Test 1.4 Passed! Setting not starting with [ Detected" << endl;
        }else{
            cout << "Test 1.4 Failed! Setting not starting with [ Not Detected" << endl;
        }
        }
        cout << "Test 1 Finished!" << endl;
    }
    cout << "Master Tests Complete!" << endl;
    
    //Wait on user input to continue
    cout << "Press any key to continue..." << endl;
    getch();
    return 0;
};
