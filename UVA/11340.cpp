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
  int K;
  int M;
  int cost[256];
  char c;
  int val;

  char line[20000];
  scanf("%d",&T);
  while(T--) {

    FORN(i,256)
      cost[i] = 0;

    scanf("%d",&K);
    FORN(i,K) {
      scanf("%s",line);
      scanf("%d",&val);
      c = line[0];
      cost[c] = val;
    }

    /*FORN(i,256) {
      printf("%c = %d\n",i,cost[i]);
    }*/
    scanf("%d\n",&M);
    ull finalVal = 0;
    FORN(i,M) {
    fgets(line,20000,stdin);
      //printf("%s\n",line);
      FORN(j,strlen(line)) {
        if(line[j] >= 0 && line[j] <= 255)
        finalVal += cost[line[j]];
      }
    }
    printf("%llu.%02llu$\n",finalVal/100,finalVal%100);


  }
  return 0;
}
