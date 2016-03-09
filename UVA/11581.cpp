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
int grid[5][5];

void performF() {
  int tempGrid[5][5];
  FOR(i,1,3)
    FOR(j,1,3) {
     tempGrid[i][j] = grid[i+1][j] + grid[i-1][j] + grid[i][j-1] + grid[i][j+1];
     tempGrid[i][j]%=2;
    }

  FOR(i,1,3)
    FOR(j,1,3)
      grid[i][j] = tempGrid[i][j];
}

void printGrid() {
  FOR(i,1,3) {
    FOR(j,1,3) 
      printf("%d",grid[i][j]);
    printf("\n");
  }
}

bool isGridZero() {
  FOR(i,1,3) 
    FOR(j,1,3) 
      if(grid[i][j]!=0) return false;
  return true;
}

int main() {
  int T;

  scanf("%d",&T);

  while(T--) {
    FOR(i,1,3) {
      int x;
      scanf("%d",&x);
      grid[i][1] = x/100;
      grid[i][3] = x%10;
      grid[i][2] = (x/10)%10;
    }
    FORN(x,512) {
      if(isGridZero()) {
        printf("%d\n",x-1);
        break;
      }
      performF();
      
    }
  }
  
  
  return 0;
}
