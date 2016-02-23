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
  int G;
  
  int I,N,Q;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&G);
    while(G--) {
        scanf("%d %d %d",&I,&N,&Q);
        printf("%d\n",N/2+((I!=Q)?N%2:0));
    }
  }
  
  return 0;
}
