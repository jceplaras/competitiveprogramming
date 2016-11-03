#include <algorithm>
#include <bitset>
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

bitset<1001> graphComp[1001];
bitset<1001> visited;
bitset<1001> mark;

int N, M;
bool valid;
bool dfs(int i,int m) {
  visited[i] = 1;
  mark[i] = m;
  
  FOR(x,1,N)
    if(graphComp[i][x]) {
      if(!visited[x])
        dfs(x,1-m);
      else if(mark[i] == mark[x]) {
        valid = false;
      }
    }
}




int main() {

  int T;
  scanf("%d",&T);

  while(T--) {
    scanf("%d %d",&N,&M);

    FOR(i,1,N) {
      graphComp[i].set();
      graphComp[i][i] = 0;
    }

    FOR(j,1,M) {
      int a,b;
      scanf("%d %d",&a,&b);

      graphComp[a][b] = graphComp[b][a] = 0;
    }



    visited.reset();
    mark.reset();

    valid = true; 
    FOR(i,1,N) {
      if(!visited[i]) {
        dfs(i,0);
      }
    }

    if(valid)
      printf("YES\n");
    else
      printf("NO\n");
    

    
  }

  
  return 0;
}
