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

char big[1000][1000];
char small[1000][1000];
char temp[1000][1000];
bool check(int I, int J, int N) {
  FOR(i,0,N-1)
    FOR(j,0,N-1)
      if(small[i][j] != big[i+I][j+J]) return false;

  return true;
}

void rotate(int N) {
  for(int r = 0; r < N; r++) {
    for(int c = 0; c < N; c++) {
      temp[r][c] = small[N-1-c][r];
    }
  }

  FORN(i,N) FORN(j,N) small[i][j] = temp[i][j];
}
int main() {

  
  int N, n;

  int val[4];
  while(true) {
    scanf("%d %d",&N,&n);

    if(N == 0 && n == 0) break;

    FORN(i,N) 
      scanf("%s",big[i]);
    FORN(i,n) {
      scanf("%s",small[i]);
      small[i][n] = 0;
    }

    FORN(x,4) {
      int count = 0;
      FORN(i,N-n+1)
        FORN(j,N-n+1)
          if(check(i,j,n)) count++;
      val[x] = count;
      rotate(n);
    }
    FORN(i,3)
      printf("%d ",val[i]);

    printf("%d\n",val[3]);
  }
  
  return 0;
}
