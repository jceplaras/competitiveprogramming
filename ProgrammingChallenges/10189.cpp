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

int OUT[105][105];
void incrementNeighbor(int i, int j) {
  FOR(x,i-1,i+1)
    FOR(y,j-1,j+1)
      if(OUT[x][y] != -1)
        OUT[x][y]++;
  OUT[i][j]=-1;
}

int main() {
  int R, C;
  char x[101];
  int num = 1;

  while(true) {


    //input phase
    scanf("%d %d",&R,&C);
    if(R==C && R==0) break;

    //solving phase
    FOR(i,1,R) {
      scanf("%s",x);
      FOR(j,1,C) {
        if(x[j-1]=='*') 
          incrementNeighbor(i,j);
      }
    }

    //output phase
    printf("Field #%d:\n",num++);
    FOR(i,1,R) {
      FOR(j,1,C) {
        if(OUT[i][j] == -1)
          printf("*");
        else
          printf("%d",OUT[i][j]);
      }
      printf("\n");
    }
    printf("\n");

  }
  return 0;
}
