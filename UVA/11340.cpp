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
  scanf("%d",&T);
  int K,M;
  int cost[300];
  char c;
  char temp[20000];
  ull sum=0;
  FORN(i,300)
    cost[i] =0;
  while(T--) {
    scanf("%d",&K);
    while(K--) {
      scanf("%s ",temp);
      scanf("%d",&cost[temp[0]]);
    }
    scanf("%d",&M);

    printf("TEST %d\n",M);
    while(M--) {
      scanf("%[^\n]",temp);
      FORN(i,strlen(temp)) {
        sum+=cost[temp[i]];
      }
    }
    printf("%llu.%llu\n",sum/100,sum%100);
  } 
  
  return 0;
}
