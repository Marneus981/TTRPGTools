#include "C:\CodeProjects\TTRPGTools\src\stats\stats_class.h"
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
    cout << "Stats Tests Initiating!" << endl;
    //Test 1: Constructor
    cout << "Test 1: Constructor" << endl;
    //stats test1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
    try {
        stats test1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt"); 
    } catch (const char* msg) {
        cout << "Test 1 Failed!" << endl;
        cerr << msg << endl;
    }
    //Ask if Test 1 passed
    cout << "Did Test 1 pass? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 1 Passed!" << endl;
    } else {
        cout << "Test 1 Failed!" << endl;
    }
    //Test 1.1: Invalid _path_to_game
    cout << "Test 1.1: Invalid _path_to_game" << endl;
    //##Destructor SHOULD be called here
    //stats test1_1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\wrong_game_DnD5e.txt");
    try {
        stats test1_1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\wrong_game_DnD5e.txt");
    } catch (const char* msg) {
        cout << "Test 1.1 Passed!" << endl;
        cerr << msg << endl;
    }
    //Figure out if Test 1.1 passed?
    cout << "If no Test 1.1 Passed! text is  found above, Test Failed!" << endl;
    
    //Test 1.2: Invalid size of _stats
    cout << "Test 1.2: Invalid size of _stats" << endl;
    //##Destructor SHOULD be called here
    //stats test1_2(list<int> {8,10,12,13,14}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
    try {
        stats test1_2(list<int> {8,10,12,13,14}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
    } catch (const char* msg) {
        cout << "Test 1.2 Passed!" << endl;
        cerr << msg << endl;
    }
    //Figure out if Test 1.2 passed?
    cout << "If no Test 1.2 Passed! text is  found above, Test Failed!" << endl;
    //REMEMBER TO TEST FOR INVALID UPDATE_MOD
    //Test 1.5: Destructor
    cout << "Test 1.5: Destructor" << endl;
    //auto dest_test = new stats(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
    //delete dest_test;  
    try {
        auto dest_test = new stats(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
        delete dest_test;  
    } catch (const char* msg) {
        cout << "Test 1.5 Failed!" << endl;
        cerr << msg << endl;
    }
    //Figure out if Test 1.1 passed?
    cout << "If no Test 1.1 Failed! text is  found above, Test Passed!" << endl;

    cout << "Test 1 Finished" << endl;
    //Test 2: Update Modifiers
    cout << "Test 2: Update Modifiers" << endl;
    //Test 2.1: Invalid stat name or not "all"
    cout << "Test 2 Finished" << endl;
    //Test 3: Get Stat
    cout << "Test 3: Get Stat" << endl;
    //Test 3.1: Invalid stat name
    cout << "Test 3 Finished" << endl;
    //Test 4: Set Stat
    cout << "Test 4: Set Stat" << endl;
    //Test 4.1: Invalid stat name
    cout << "Test 4 Finished" << endl;
    cout << "Master Tests Finished" << endl;
    return 0;
};
