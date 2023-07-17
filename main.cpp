#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tictactoe.h"
using namespace std;

int main(){
    char arr[3][3]={ '1','2','3',
                     '4','5','6',
                     '7','8','9',
                    };
    printArr(arr);
    clearArr(arr);
    int result = 0;
    int move1,move2,valid=0,moveCount=0,track[10]={0};
    while(result!=1){
        cout<<endl<<"------------"<<endl<<endl;
        move1 = getValidMove(1, track);
        valid =0;
        playMoveX(move1,arr);
        track[move1]=1;
        moveCount++;
        printArr(arr);
        if(checkWin(arr,move1,moveCount)==1){
            result=1;
            cout<<endl<<"PLAYER 1 WINS"<<endl;
            break;
        }
        else if(checkWin(arr,move1,moveCount)==0){
            cout<<endl<<"GAME IS A TIE"<<endl;
            result=1;
            break;
        }

        cout<<endl<<"------------"<<endl<<endl;

        move2 = getValidMove(2, track);
        playMoveO(move2,arr);
        moveCount++;
        track[move2]=1;
        printArr(arr);
        if(checkWin(arr,move2,moveCount)==1){
            result=1;
            cout<<endl<<"PLAYER 2 WINS"<<endl;
            break;
        }
        
    }
    return 0;
}
// ◯ | X | ◯
// __|___|___
// ◯ | X | ◯
// __|___|___
// ◯ | X | ◯
