#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

char board[8][8];

int main() {
  char FEN[100];

  FORN(i,8)
    FORN(j,8)
      board[i][j] = 'X';
  scanf("%s",FEN);
  int row=0,col=0;
  FORN(i,strlen(FEN)) {
    if(isdigit(FEN[i])) {
    col+=FEN[i]-'0'; 
    }
    else if(FEN[i] == '/') {
      col=0;
      row++;
    }
    else {
      board[row][col]=FEN[i];
      col++;
    }
  }

  FORN(i,8) {
    FORN(j,8)
      printf("%c ",board[i][j]);
    printf("\n");
  }
  
  return 0;
}
