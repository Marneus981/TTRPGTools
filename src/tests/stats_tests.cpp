#include "C:\CodeProjects\TTRPGTools\src\stats\stats_class.h"
#include "C:\CodeProjects\TTRPGTools\src\globalest_vars.h"
using namespace std;
//VERBOSE MODE
bool verbose_mode = false;

int main(){
    //Ask the user if they want to turn on Verbose Mode
    bool pass;
    cout << "Do you want to turn on Verbose Mode? (y/n)" << endl;
    char input;
    cin >> input;
    if (input == 'y'){
        cout << "Verbose Mode Activated!" << endl;
        verbose_mode = true;
    }
    cout << "Stats Tests Initiating!" << endl;
    cout << "Test 1: Constructor" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 1 Skipped!" << endl;
    }else{
        //Test 1.1: Constructor
        cout << "Test 1.1: Constructor, correct input" << endl;
        string correct_path = "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt";
        string wrong_path = "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\wrong_game_DnD5e.txt";
        //stats test1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
        pass = true;
        try {
            list<int> test1_stats = {8,10,12,13,14,15};
            stats test1(test1_stats, wrong_path); 
        //const char* msg
        } catch (...) {
            pass = false;
            cout << "Test 1.1 Failed!" << endl;
            //cout << msg << endl;
            //cerr << msg << endl;
        }
        //Ask if Test 1.1 passed
        if (pass){
            cout << "Test 1.1 Passed!" << endl;
        }
        //Test 1.2: Invalid _path_to_game
        cout << "Test 1.2: Invalid _path_to_game" << endl;
        //##Destructor SHOULD be called here
        //stats test1_1(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\wrong_game_DnD5e.txt");
        pass = false;
        try {
            list<int> test1_1_stats = {8,10,12,13,14,15};
            stats test1_1(test1_1_stats, wrong_path);
        } catch (...) {
            pass = true;
            cout << "Test 1.2 Passed!" << endl;
            //cout << msg << endl;
            //cerr << msg << endl;
        }
        if (!pass){
            cout << "Test 1.2 Failed!" << endl;
        }
        
        //Test 1.2: Invalid size of _stats
        cout << "Test 1.3: Invalid size of _stats" << endl;
        //##Destructor SHOULD be called here
        //stats test1_2(list<int> {8,10,12,13,14}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
        pass = false;
        try {
            list<int> test1_2_stats = {8,10,12,13,14};
            stats test1_2(test1_2_stats, correct_path);
        } catch (...) {
            pass = true;
            cout << "Test 1.3 Passed!" << endl;
            //cout << msg << endl;
            //cerr << msg << endl;
        }
        if (!pass){
            cout << "Test 1.3 Failed!" << endl;
        }

        //REMEMBER TO TEST FOR INVALID UPDATE_MOD
        //Test 1.5: Destructor
        cout << "Test 1.5: Destructor" << endl;
        //auto dest_test = new stats(list<int> {8,10,12,13,14,15}, "C:\\CodeProjects\\TTRPGTools\\src\\tabletop_games\\DnD\\game_DnD5e.txt");
        //delete dest_test;  
        list<int> test1_5_stats = {8,10,12,13,14,15};
        stats* dest_test =NULL;
        dest_test = new stats(test1_5_stats, correct_path);
        delete dest_test;
        dest_test = NULL;  

        //Memory Check for Destructor
        cout << "Did the Destructor work (according to variable tracking/output)? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 1.5 Passed!" << endl;
        } else {
            cout << "Test 1.5 Failed!" << endl;
        }
            //cerr << msg << endl;
        cout << "Test 1 Finished!" << endl;
        ////End of Test 1
    }
    //Test 2: Update Modifiers
    cout << "Test 2: Update Modifiers" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 2 Skipped!" << endl;
    }else{
        cout << "Test 2 Finished" << endl;
    }
    //Test 3: Get Stat
    cout << "Test 3: Get Stat" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 3 Skipped!" << endl;
    }else{
        cout << "Test 3 Finished" << endl;
    }
    //Test 4: Set Stat
    cout << "Test 4: Set Stat" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 4 Skipped!" << endl;
    }else{
        cout << "Test 4 Finished" << endl;
    }
    //Test 5: Change Stat
    cout << "Test 5: Change Stat" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 5 Skipped!" << endl;
    }else{
        cout << "Test 5 Finished" << endl;
    }
    //Test 6: Allocation Types Helpers
    cout << "Test 6: Allocation Types Helpers" << endl;
    //Ask if user wants to skip this test
    cout << "Do you want to skip this test? (y/n)" << endl;
    cin >> input;
    if (input == 'y'){
        cout << "Test 6: Allocation Types Helpers Skipped!" << endl;
    }else{

        //Test 6.1: Standard Array
        cout << "Test 6.1: Allocation Types Helpers, Standard Array" << endl;
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 6.1 Skipped!" << endl;
        }else{
        }
        //Test 6.2: Point Buy
        cout << "Test 6.2: Allocation Types Helpers, Point Buy!" << endl;
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 6.2 Skipped!" << endl;
        }else{
        }
        //Test 6.3: Random Allocation
        cout << "Test 6.3: Allocation Types Helpers, Random Stats" << endl;
        cout << "Do you want to skip this test? (y/n)" << endl;
        cin >> input;
        if (input == 'y'){
            cout << "Test 6.3 Skipped!" << endl;
        }else{
        }

        cout << "Test 6 Finished" << endl;
    }


    cout << "Master Tests Finished" << endl;
    
    //Wait on user input to continue
    cout << "Press any key to continue..." << endl;
    getch();
    return 0;
};
