#include<bits/stdc++.h>
using namespace std;
void print_board(char board[][3]){
    cout << "The Board is : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
char check_board(char board[][3]){
    //horizontal
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '_')
                return board[i][0];
    }
    // Vertical
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i]  != '_')
                return board[0][i];
    }
    // Left Diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '_')
            return board[0][0];
    // Right Diagonal
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != '_')
            return board[2][0];
    return '_';
}
int main(){
    // srand() function should only be seeded once
    // This should not be repeatedly seeded or reseeded everytime you wish to generate a new batch of pseudo-random numbers
    srand(time(0));
    char board[3][3] = {{'_','_','_'}, {'_','_','_'}, {'_','_','_'}};
    char players[2] = {'X','O'};
    cout << "Welcome to Tick Tack Toe Game" << endl;
    cout << "Initially the Board was : " << endl;
    print_board(board);
    // Randomly choose any 1 player from 'X' or 'O'
    // If the random number is even, player[0] i.e.'X' will start the game
    // If it is odd, player[1] i.e.'O' will start the game
    int choice = players[rand() % 2];
    // Totally 9 moves - 5 for player who starts first and 4 for player who starts then
    // For 1st 4 moves no player will be announced as winner
    for(int i = 0; i < 4; i++){
        int row, col;
        cout << "Its " << (choice == 0 ? "X" : "O") << " turn" << endl;
        cout << "Enter the row number from 0 to 2 : ";
        cin >> row;
        cout << "Enter the column number from 0 to 2 : ";
        cin >> col;
        if(choice == 0){
            board[row][col] = 'X';
            choice = 1;
        }
        else{
            board[row][col] = 'O';
            choice = 0;
        }
        print_board(board);
    }
    // From 5th move board will be checked at every move
    char winner = '_';
    for(int i = 4; i < 9; i++){ // 4 5 6 7 8 - Winning Moves
        int row, col;
        cout << "Its " << (choice == 0 ? "X" : "O") << " turn" << endl;
        cout << "Enter the row number from 0 to 2 :";
        cin >> row;
        cout << "Enter the column number from 0 to 2 :";
        cin >> col;
        if(choice == 0){
            board[row][col] = 'X';
            choice = 1;
        }
        else{
            board[row][col] = 'O';
            choice = 0;
        }
        print_board(board);
        winner = check_board(board);
        cout << "Winner Variable is : " << winner << endl;
        if(winner == 'X' || winner == 'O'){
            break;
        }
        else{
            continue;
        }
    }
    if(winner == '_'){
        cout << "The Game Tied" << endl;
        cout << "Both of you Well Played" << endl;
    }
    else{
        cout << "The winner is : " << (winner == 'X' ? "X" : "O") << endl;
    }
    cout << "The Game Ends" << endl;
    return 0;
}
