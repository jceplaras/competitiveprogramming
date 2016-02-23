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

int m[101];

int main() {
  int T;
  
  int N, M;
  int C, L;
  long S;
  bool hasAlive;
  scanf("%d",&T);
  
  while(T--) {
    FORN(i,101) 
      m[i] = 0;
    S = 0;
    hasAlive = false;
    scanf("%d %d",&N,&M);
    
    while(N--) {
      scanf("%d %d",&C,&L);
      
      m[L]+=C;
    }
    
    while(M--) {
      scanf("%d %d",&C,&L);
      
      m[L]-=C;
    }
    
    FORN(i,101) {
      //if(m[i] > 0) hasAlive = true;
      if(m[i] < 0) S += -m[i];
    }
    //if(!hasAlive) S++;
    
    printf("%ld\n",S);
  }
  
  
  return 0;
}
