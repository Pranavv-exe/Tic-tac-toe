#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
using namespace std;
int checkWin(char arr[][3], int move, int count);
void printArr(char arr[][3]);
void clearArr(char arr[][3]);
void playMoveX(int move, char arr[][3]);
void playMoveO(int move, char arr[][3]);

// Function implementations

int checkWin(char arr[][3], int move, int count) {
    if (count < 3) {
        return -1;
    }
    if (count == 9) {
        return 0;
    }
    if (move == 1 || move == 5 || move == 9) {
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
            return 1;
        }
    }
    if (move == 3 || move == 5 || move == 7) {
        if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
            return 1;
        }
    }
    bool flag = true;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    for (int j = 1; j < 3; j++) {
        if (arr[row][j] != arr[row][j - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        return 1;
    }
    else {
        flag = true;
        for (int j = 1; j < 3; j++) {
            if (arr[j][col] != arr[j - 1][col]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return 1;
        }
    }
    return -1;
}

void printArr(char arr[][3]) {
    std::cout << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << std::endl;
    std::cout << "__|___|___" << std::endl;
    std::cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << std::endl;
    std::cout << "__|___|___" << std::endl;
    std::cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << std::endl;
}

void clearArr(char arr[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = ' ';
        }
    }
}

void playMoveX(int move, char arr[][3]) {
    move--;
    int row = move / 3;
    int col = move % 3;
    arr[row][col] = 'X';
}

void playMoveO(int move, char arr[][3]) {
    move--;
    int row = move / 3;
    int col = move % 3;
    arr[row][col] = 'O';
}
int getValidMove(int player, int track[]) {
    int move;
    bool valid = false;

    cout << "Player " << player << "'s turn" << endl;
    cout << "Enter square number: ";
    cin >> move;

    while (!valid) {
        if (move < 1 || move > 9 || track[move] != 0) {
            cout << "Invalid move!" << endl;
            cout << "Enter again: ";
            cin >> move;
        } else {
            valid = true;
        }
    }

    return move;
}

#endif // TICTACTOE_H
