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

int T[250][250];

int main() {
  int N,M;
  int S,G,D;
  int ans;
  int res;
  
  scanf("%d",&N);
  FORN(i,N)FORN(j,N) scanf("%d",&T[i][j]);
  FORN(k,N)FORN(i,N)FORN(j,N)T[i][j] = min(T[i][j],T[i][k]+T[k][j]);
  scanf("%d",&M);
  while(M--) {
  scanf("%d %d %d",&S,&G,&D);
  ans = T[S][G]+T[G][D];
  res =  ans - T[S][D];
  printf("%d %d\n",ans,res);
  }
  return 0;
}
