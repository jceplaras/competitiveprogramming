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

ll val[100];

int main() { 
  val[0] = 1;
  FOR(i,1,61){
    if(i%2 == 0)
      val[i] = val[i-1]+1;
    else
      val[i] = val[i-1]*2;
  }
  
  int T;
  scanf("%d",&T);
  int x;
  FORN(i,T) {
    scanf("%d",&x);

    printf("%lld\n",val[x]);

  }


  return 0;
}
