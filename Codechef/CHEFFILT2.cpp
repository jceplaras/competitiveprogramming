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

#define MOD 1000000007
#define L 4 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
  ull DP[100001][1024];
  int store[100001];

int main() {
  int T,N;
  char temp[11];


  scanf("%d",&T);

  while(T--) {
    int target = 0;
    scanf("%s",temp);

    FORN(i,L)
      if(temp[i] == 'w')
        target = target + (1 << i);


    scanf("%d",&N);
    //printf("t: %d\n",target);
    FORN(x,N) {
      scanf("%s",temp);
      int val = 0; 
      FORN(i,L)
        if(temp[i] == '+')
          val = val + ( 1 << i);

      store[x+1] = val;

    }
    DP[0][0] = 1;
    for(int i=1;i<=N;i++) {
      for(int j=0;j<=1023;j++) {
        DP[i][j] = (DP[i-1][j]%MOD + DP[i-1][j ^ store[i]]%MOD)%MOD;
      }
    }

    printf("%llu\n",DP[N][target]);

    FORN(i,N+1) {
      FORN(j,16) {
        printf("%3d ",DP[i][j]);
      }
      printf("\n");
    }

      FORN(j,1024)
        DP[0][j] = 0;
  

  }
  
  return 0;
}
