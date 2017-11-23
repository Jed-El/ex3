/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#include "Human.h"
#include <stdio.h>
Human::Human(Side s):Player(s){};

Point *Human::doMove(const vector<Point *> &options) {
    int r;
    int c;
    char dummy;
    int flag = 0;
    Point *choice;
    if (options.size() == 0) {
        cout << "You have no possible moves, turn pass" << endl;
        return NULL;
    }
    cout << "Your Possible Moves are :";
    for (int i = 0; i < options.size(); i++) {
        options[i]->pPrint();
    }
    cout << endl;
    while (flag == 0) {
        cout <<  "Please enter your move row, col:" << endl;
        while (true) {
            cin >> r;
            dummy = getchar();
            cin >> c;
            if (!cin.fail()) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                break;
            }
            // user didn't input a number
            cout << "Please enter numbers only." << endl;
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        }
        choice = new Point(r - 1, c - 1);
        for (int k = 0; k < options.size(); k++) {
            if (choice->isEqual(options[k]))
                flag = 1;
        }
        if (!flag) {
            cout << "invalid Choice" << endl;
            delete choice;
        }
    }
    return choice;
}
