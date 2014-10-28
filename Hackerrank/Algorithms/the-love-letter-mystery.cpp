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
  char str[10005];
  int cost = 0;
  int len = 0;
  scanf("%d",&T);

  FORN(i,T) {
    scanf("%s",str);
    cost = 0;
    len = strlen(str);

    for(int i=0,j=len-1;i<len/2;i++,j--) {
      cost+=abs(str[i]-str[j]);
    }
    printf("%d\n",cost);

  }
  
  return 0;
}
