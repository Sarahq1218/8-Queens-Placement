#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


void printBoard(int q[]) {
  
  int i, j, k, l;
  typedef char box[5][7];
  box bb, wb, *board[8][8];

  static int solution = 0;
  cout << "Solution # " << ++solution << ":" << endl;
  
  static box bq = {   // draw out chessboard manually black square, not sure if this is right?
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
        {char(219),' ',char(219),' ',char(219),' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
  };
               
   static box wq = { // draw out chessboard manually white square
        {' ' ,' ',' ' ,' ',' ',' ',' '},
        {' ',char(241),' ',char(241),' ',char(241),' '},
        {' ',char(241),char(241),char(241),char(241),char(241),' '},
        {' ',char(241),char(241),char(241),char(241),char(241),' '},
        {' ',' ',' ',' ',' ',' ' ,' '  } 
  };
  
  for ( i = 0; i < 5; i++)
    for (j = 0; j < 7; j++) 
    {
      wb[i][j] = ' ';
      bb[i][j] = char(219);
    }
    
   //print board
  for (i = 0; i < 8; i++)
    for ( j = 0; j < 8; j++)
      if ((i + j) % 2 == 0) {
        if (q[i] == j) {
          board[i][j] = &wq;
        } else {
          board[i][j] = &wb;
        }
      } else {
        if (q[i] == j) {
          board[i][j] = &bq; // adress of operator
        } else {
          board[i][j] = &bb;
        }
      }
       
    for ( i = 0; i < 7 * 8; i++)
      cout << "_";
  cout << endl;
  
  // now print the board
  for ( i = 0; i < 8; i++)
    for ( k = 0; k < 5; k++)
    {
      cout << "|"; // print the left boarder
      for ( j = 0; j < 8; j++)
        for ( l = 0; l < 7; l++)
          cout << (*board[i][j])[k][l]; //dereference
        cout << "|" << endl; // at end of line print bar and then newline  
    }
    
  for ( i = 0; i < 7 * 8; i++)
    cout << "_"; // lower boarder
  cout << endl;
  
}
//bactrack
void backTrack(int q[], int &c) {
  c--;
  if (c == -1) {
    exit(0);
  q[c]++;  
  }
}
//generic okay function for checking queens
bool Okay(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
      return false;
  }
      return true;  
}
int main() {
  // Main Program
  int q[8] = {};
  int c = 0;
  q[0] = 0;
  
    while (c >= 0) { 
      c++; //iterate through board
      if (c == 8) {
        printBoard(q); 
        backTrack(q, c); //but if not good then backtrack
    } else {
        q[c] = -1;
    } 
      while (c >= 0) {
      q[c]++; //iterate through array
        if (q[c] == 8) {
          backTrack(q, c);
        } else {
          if (Okay(q, c))
            break;
        } 
    } 
   }  
  return 0;
}