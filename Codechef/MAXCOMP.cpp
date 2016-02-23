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
#define truN 48
int path[49][49];

int main() {
  int T;
  int N;
  
  int s, e, c;
  
  scanf("%d", &T);
  
  while(T--) {
    scanf("%d", &N);
    
    while(N--) {
      scanf("%d %d %d",&s,&e,&c);
      path[s][e] = (path[s][e]<c)?c:(path[s][e]);
      if(s == 0) path[e][e] = path[s][e];
    }
     
    
    for(int s=1;s<=48;s++)
      for(int e=s+1;e<=48;e++) {
     
        path[s][e] = path[s][e]+path[s][s];
        path[e][e] = max(path[s][e],path[e][e]);
    }
    
  
    
    printf("%d\n", path[truN][truN]);
    
    FORN(i,truN+1)
      FORN(j,truN+1)
        path[i][j]=0;
   
  }
  
  return 0;
}
