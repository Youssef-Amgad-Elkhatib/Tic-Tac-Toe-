// Program: Tic-Tac-Toe is a game played by two players, one takes odd numbers and the other takes even numbers,
// each player tries to connect a line of numbers that equals 15 (odd only or even only) diagonally, vertically or horizontally.
// Author: Youssef Amgad Abd Al Halim Ahmed

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <set>
using namespace std;
string checker1(string x);

int main() {
    //display game status and welcome players
    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "Player 1 will take odd numbers and player 2 will take even numbers" << endl;
    cout << "Whoever gets three numbers (odd only or even only) in a row whose sum is equal to 15 wins" << endl;
    string player1, player2;
    cout << "Player 1, please enter your name: " << endl;
    cin >> player1;
    cout << "Player 2, please enter your name: " << endl;
    cin >> player2;

    // make array to display tic-tac-toe board
    string arr[3][3];

    // make two vectors to make sure user doesn't choose the same number more than once
    vector <int> list_1= {1,3,5,7,9};
    vector <int> list_2={0,2,4,6,8};

    // display tic-tac-toe board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = " ";
        }
    }
    for (int i = 0; i < 3; i++) {
        cout<<i<<"   ";
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                cout << arr[i][j];
                continue;
            }
            cout << arr[i][j] << " | ";
        }
        cout << endl;
        cout << "    --|---|--";
        cout << endl;
    }
    cout<<"      |"<<"   |"<<endl;
    cout<<endl;
    cout<<"    "<<0<<"   "<<1<<"   "<<2<<endl;
    cout<<endl;

    // set counter to see if the game reaches a draw if nine numbers were entered
    int counter = 0;

    // player 1 turn
    // enter an odd number from 1 to 9 which wasn't chosen before

    while (true) {
        cout << player1 << ", It is your turn choose an odd number from 1 to 9 that wasn't chosen before: " << endl;
        string num;
        cin >> num;
        num = checker1(num);
        int num1 = stoi(num);
        bool exist=find(begin(list_1),end(list_1),num1)!=end(list_1);

        // checking validity of number
        while ((num1 % 2 == 0 || !exist))  {

                cout << "Please enter an odd number from 1 to 9 that wasn't chosen before: " << endl;
                cin >> num;
                num = checker1(num);
                num1 = stoi(num);
                exist=find(begin(list_1),end(list_1),num1)!=end(list_1);


        }

        // remove chosen number from vector
        list_1.erase(remove(list_1.begin(),list_1.end(),num1),list_1.end());

        // enter the box which the player wants to put his number
        cout << "Please enter two numbers from 0 to 2, the indexes where you want to put your number: " << endl;
        string i, j;
        cin >> i;
        i = checker1(i);
        int x = stoi(i);

        // check validity of index i
        while (x < 0 || x > 2) {
            cout << "Please enter a number from 0 to 2" << endl;
            cin >> i;
            i = checker1(i);
            x = stoi(i);
        }

        // input second index
        cout << "Enter the second number: " << endl;
        cin >> j;
        j = checker1(j);
        int y = stoi(j);

        // check validity of index j
        while (y < 0 || y > 2) {
            cout << "Please enter a number from 0 to 2" << endl;
            cin >> j;
            j = checker1(j);
            y = stoi(j);
        }

        // make sure that the box that the player chose wasn't chosen before
        while(arr[x][y]!=" "){
            cout<<"Please enter a non chosen box"<<endl;
            cout<<"Please enter the first number"<<endl;
            cin >> i;
            i = checker1(i);
            x = stoi(i);
            while (x < 0 || x > 2) {
                cout << "Please enter a number from 0 to 2" << endl;
                cin >> i;
                i = checker1(i);
                x = stoi(i);
            }
            cout << "Enter the second number: " << endl;
            cin >> j;
            j = checker1(j);
            y = stoi(j);
            while (y < 0 || y > 2) {
                cout << "Please enter a number from 0 to 2" << endl;
                cin >> j;
                j = checker1(j);
                y = stoi(j);
            }
        }

        // change array index to number
        arr[x][y] = num;

        // increment counter

        counter++;

        // display new status
        for (int i = 0; i < 3; i++) {
            cout<<i<<"   ";
            for (int j = 0; j < 3; j++) {
                if (j == 2) {
                    cout << arr[i][j];
                    continue;
                }
                cout << arr[i][j] << " | ";
            }
            cout << endl;
            cout << "    --|---|--";
            cout << endl;
        }
        cout<<"      |"<<"   |"<<endl;
        cout<<endl;
        cout<<"    "<<0<<"   "<<1<<"   "<<2<<endl;
        cout<<endl;

        // check if any player won
        if ((arr[0][0]) != " " && (arr[0][1]) != " " && (arr[0][2]) != " ") {
            if (stoi(arr[0][0]) + stoi(arr[0][1]) + stoi(arr[0][2]) == 15) {
                if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[0][1]) % 2 == 0 && stoi(arr[0][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[0][1]) % 2 != 0 && stoi(arr[0][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[1][0]) != " " && (arr[1][1]) != " " && (arr[1][2]) != " ") {
            if (stoi(arr[1][0]) + stoi(arr[1][1]) + stoi(arr[1][2]) == 15) {
                if (stoi(arr[1][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[1][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[1][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[1][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[2][0]) != " " && (arr[2][1]) != " " && (arr[2][2]) != " ") {
            if (stoi(arr[2][0]) + stoi(arr[2][1]) + stoi(arr[2][2]) == 15) {
                if (stoi(arr[2][0]) % 2 == 0 && stoi(arr[2][1]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[2][0]) % 2 != 0 && stoi(arr[2][1]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][0]) != " " && (arr[1][0]) != " " && (arr[2][0]) != " ") {
            if (stoi(arr[0][0]) + stoi(arr[1][0]) + stoi(arr[2][0]) == 15) {
                if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[1][0]) % 2 == 0 && stoi(arr[2][0]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[1][0]) % 2 != 0 && stoi(arr[2][0]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][1]) != " " && (arr[1][1]) != " " && (arr[2][1]) != " ") {
            if (stoi(arr[0][1]) + stoi(arr[1][1]) + stoi(arr[2][1]) == 15) {
                if (stoi(arr[0][1]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[2][1]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][1]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[2][1]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
            if ((arr[0][2]) != " " && (arr[1][2]) != " " && (arr[2][2]) != " ") {
                if (stoi(arr[0][2]) + stoi(arr[1][2]) + stoi(arr[2][2]) == 15) {
                    if (stoi(arr[0][2]) % 2 == 0 && stoi(arr[1][2]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                        cout << player2 << ", You win" << endl;
                        break;
                    } else if (stoi(arr[0][2]) % 2 != 0 && stoi(arr[1][2]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                        cout << player1 << ", You win" << endl;
                        break;
                    }
                }
            }
            if ((arr[0][0]) != " " && (arr[1][1]) != " " && (arr[2][2]) != " ") {
                if (stoi(arr[0][0]) + stoi(arr[1][1]) + stoi(arr[2][2]) == 15) {
                    if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                        cout << player2 << ", You win" << endl;
                        break;
                    } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                        cout << player1 << ", You win" << endl;
                        break;
                    }
                }
            }
            if ((arr[2][0]) != " " && (arr[1][1]) != " " && (arr[0][2]) != " ") {
                if (stoi(arr[2][0]) + stoi(arr[1][1]) + stoi(arr[0][2]) == 15) {
                    if (stoi(arr[2][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[0][2]) % 2 == 0) {
                        cout << player2 << ", You win" << endl;
                        break;
                    } else if (stoi(arr[2][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[0][2]) % 2 != 0) {
                        cout << player1 << ", You win" << endl;
                        break;
                    }
                }
            }

            // checking draw condition
            if (counter == 9) {
                cout << "It is a Draw" << endl;
                break;
            }

            // player 2 turn
            cout << player2 << ", It is your turn choose an even number from 0 to 8 that wasn't chosen before: " << endl;

            // inputting even number and checking its validity
            cin >> num;
            num = checker1(num);
            num1 = stoi(num);
            bool exist2=find(begin(list_2),end(list_2),num1)!=end(list_2);
            while (num1 % 2 != 0 || !exist2) {
                cout << "Please enter an even number from 0 to 8 that wasn't chosen before: " << endl;
                cin >> num;
                num = checker1(num);
                num1 = stoi(num);
                exist2=find(begin(list_2),end(list_2),num1)!=end(list_2);
            }

            // removing number from even list to prevent repetition
            list_2.erase(remove(list_2.begin(),list_2.end(),num1),list_2.end());

            // inputting index i
            cout << "Please enter two numbers from 0 to 2, the indexes where you want to put your number: " << endl;

            cin >> i;
            i = checker1(i);
            x = stoi(i);

            // checking its validity
            while (x < 0 || x > 2) {
                cout << "Please enter a number from 0 to 2" << endl;
                cin >> i;
                i = checker1(i);
                x = stoi(i);
            }

            // inputting index j and checking its validity
            cout << "Enter the second number: " << endl;
            cin >> j;
            j = checker1(j);
            y = stoi(j);
            while (y < 0 || y > 2) {
                cout << "Please enter a number from 0 to 2" << endl;
                cin >> j;
                j = checker1(j);
                y = stoi(j);
            }
            // preventing use of an already chosen box
            while(arr[x][y]!=" "){
                cout<<"Please enter a non chosen box"<<endl;
                cout<<"Please enter the first number"<<endl;
                cin >> i;
                i = checker1(i);
                x = stoi(i);
                while (x < 0 || x > 2) {
                    cout << "Please enter a number from 0 to 2" << endl;
                    cin >> i;
                    i = checker1(i);
                    x = stoi(i);
            }
                cout << "Enter the second number: " << endl;
                cin >> j;
                j = checker1(j);
                y = stoi(j);
                while (y < 0 || y > 2) {
                    cout << "Please enter a number from 0 to 2" << endl;
                    cin >> j;
                    j = checker1(j);
                    y = stoi(j);
            }
        }
            // changing array index to chosen number
            arr[x][y] = num;

            // increment counter
            counter++;

            // display new status
        for (int i = 0; i < 3; i++) {
            cout<<i<<"   ";
            for (int j = 0; j < 3; j++) {
                if (j == 2) {
                    cout << arr[i][j];
                    continue;
                }
                cout << arr[i][j] << " | ";
            }
            cout << endl;
            cout << "    --|---|--";
            cout << endl;
        }
        cout<<"      |"<<"   |"<<endl;
        cout<<endl;
        cout<<"    "<<0<<"   "<<1<<"   "<<2<<endl;
        cout<<endl;

        // checking winning condition
        if ((arr[0][0]) != " " && (arr[0][1]) != " " && (arr[0][2]) != " ") {
            if (stoi(arr[0][0]) + stoi(arr[0][1]) + stoi(arr[0][2]) == 15) {
                if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[0][1]) % 2 == 0 && stoi(arr[0][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[0][1]) % 2 != 0 && stoi(arr[0][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[1][0]) != " " && (arr[1][1]) != " " && (arr[1][2]) != " ") {
            if (stoi(arr[1][0]) + stoi(arr[1][1]) + stoi(arr[1][2]) == 15) {
                if (stoi(arr[1][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[1][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[1][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[1][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[2][0]) != " " && (arr[2][1]) != " " && (arr[2][2]) != " ") {
            if (stoi(arr[2][0]) + stoi(arr[2][1]) + stoi(arr[2][2]) == 15) {
                if (stoi(arr[2][0]) % 2 == 0 && stoi(arr[2][1]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[2][0]) % 2 != 0 && stoi(arr[2][1]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][0]) != " " && (arr[1][0]) != " " && (arr[2][0]) != " ") {
            if (stoi(arr[0][0]) + stoi(arr[1][0]) + stoi(arr[2][0]) == 15) {
                if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[1][0]) % 2 == 0 && stoi(arr[2][0]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[1][0]) % 2 != 0 && stoi(arr[2][0]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][1]) != " " && (arr[1][1]) != " " && (arr[2][1]) != " ") {
            if (stoi(arr[0][1]) + stoi(arr[1][1]) + stoi(arr[2][1]) == 15) {
                if (stoi(arr[0][1]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[2][1]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][1]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[2][1]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][2]) != " " && (arr[1][2]) != " " && (arr[2][2]) != " ") {
            if (stoi(arr[0][2]) + stoi(arr[1][2]) + stoi(arr[2][2]) == 15) {
                if (stoi(arr[0][2]) % 2 == 0 && stoi(arr[1][2]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][2]) % 2 != 0 && stoi(arr[1][2]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[0][0]) != " " && (arr[1][1]) != " " && (arr[2][2]) != " ") {
            if (stoi(arr[0][0]) + stoi(arr[1][1]) + stoi(arr[2][2]) == 15) {
                if (stoi(arr[0][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[2][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[0][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[2][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }
        if ((arr[2][0]) != " " && (arr[1][1]) != " " && (arr[0][2]) != " ") {
            if (stoi(arr[2][0]) + stoi(arr[1][1]) + stoi(arr[0][2]) == 15) {
                if (stoi(arr[2][0]) % 2 == 0 && stoi(arr[1][1]) % 2 == 0 && stoi(arr[0][2]) % 2 == 0) {
                    cout << player2 << ", You win" << endl;
                    break;
                } else if (stoi(arr[2][0]) % 2 != 0 && stoi(arr[1][1]) % 2 != 0 && stoi(arr[0][2]) % 2 != 0) {
                    cout << player1 << ", You win" << endl;
                    break;
                }
            }
        }

        // checking draw condition
        if (counter == 9) {
            cout << "It is a Draw" << endl;
            break;
        }

        }

    }

// function that checks that the input is an integer and not string or double etc....
string checker1(string x){
    while(true){
        bool is_digit=true;

        for(int i=0; i<x.length(); i++){
            if(isdigit(x[i])==0){
                is_digit= false;
                break;
            }
        }

        if(is_digit){return x;}
        else{
            cout<<"Please enter a valid number"<<endl;
            cin>>x;

        }
    }
}
