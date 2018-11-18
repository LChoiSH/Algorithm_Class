#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void grade(int row, int col, int last, int nownum, int board[][17]){
  //cout << row << " " << col << " " << board[row][col] << " " << nownum << endl;

  if(row<0 || col<0 || row>16 || col>16){
    return ;
  }else if(nownum == last && board[row][col] == last){
    cout << "correct" << endl;
  }else if(board[row][col] == nownum++ ){
    cout << " go to " << row << "," << col << " " << "nownum : " << nownum-1 << endl;
    grade(row-1,col-1,last, nownum, board);
    grade(row-1,col,last, nownum, board);
    grade(row-1,col+1,last, nownum, board);
    grade(row,col+1,last, nownum, board);
    grade(row+1,col+1,last, nownum, board);
    grade(row+1,col,last, nownum, board);
    grade(row+1,col-1,last, nownum, board);
    grade(row,col-1,last, nownum, board);
  }
}



int main(){

  ifstream inStream;
  inStream.open("hidatopuzzle.txt");

  int Testcases;
  inStream >> Testcases;

  for(int i=0;i<Testcases;i++){

    int row, col;
    inStream >> row >> col;

    int last = 0;
    int startrow, startcol;

    int board[17][17] = {0};
    for(int j=0;j<row;j++){
      for(int k=0;k<col;k++){
        inStream >> board[j][k];
        if(board[j][k] != -1){
          last++;
          if(board[j][k] == 1){
            startrow=j;
            startcol=k;
          }
        }
      }
    }

    cout << startrow << " " << startcol << " 1 " << last << " " << endl;

    for(int j=0;j<row;j++){
      for(int k=0;k<col;k++){
        cout << board[j][k] << " ";
      }
      cout << endl;
    }
    grade(startrow, startcol, last, 1, board);


  }


  return 0;
}
