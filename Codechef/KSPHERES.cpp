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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

  ull DP[1002][100002]; 
int main() {
  ull upper[100002];
  ull lower[100002];
 
  FORN(i,1002)
    FORN(j,100002)
      DP[i][j]=0;

  int N,M,C;
  int X;
  int count=0;

  scanf("%d %d %d",&N,&M,&C);
  FORN(i,N) {
    scanf("%d",&X);
    upper[X]++;
  }
  FORN(i,M) {
    scanf("%d",&X);
    lower[X]++;
  }

  FORN(i,100002) {
    if(upper[i] != 0 &&  lower[i] != 0) {
   //   printf("MATCH %d\n",i);
    
      count++;
      upper[i]*=lower[i];
      DP[0][count]=upper[i];
      DP[1][count]=DP[1][count-1]+upper[i];
    }
  }

  for(int i=2;i<=C+1;i++) {
    for(int j=i;j<=count;j++) {
      DP[i][j]=((DP[i-1][j-1]%MOD*DP[0][j]%MOD)%MOD+DP[i][j-1]%MOD)%MOD;
    }
  }

  /*FORN(i,count+1) {
    FORN(j,count+1)
      printf("%llu ",DP[i][j]);
    printf("\n");
  }*/
  for(int i=1;i<=C;i++) {
    printf("%llu ",DP[i+1][count]);
  }
  printf("\n");
  
  return 0;
}
