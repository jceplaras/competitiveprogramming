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

int main() {
  int T;
  char M[102][102];

  scanf("%d",&T);

  FORN(i,102)
    FORN(j,102)
      M[i][j]=64;

  char str[101];

  FOR(i,1,T) {
    scanf("%s",str);
    FOR(j,1,T) {
      M[i][j] = str[j-1];
    }
  }

  FOR(i,1,T)
    FOR(j,1,T)
      if(M[i][j] > M[i-1][j] && 
          M[i][j] > M[i+1][j] && 
          M[i][j] > M[i][j-1] && 
          M[i][j] > M[i][j+1])
        M[i][j] = 'X';

  FOR(i,1,T) {
    FOR(j,1,T)
      printf("%c",M[i][j]);
    printf("\n");   
  }
  
  return 0;
}
