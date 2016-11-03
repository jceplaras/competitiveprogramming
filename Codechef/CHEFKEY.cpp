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
  scanf("%d", &T);

  while(T--) {
    int n, m;
    int c;
    scanf("%d %d %d",&n,&m,&c);
  
    int count = 0;
    FOR(i,1,n) {
      if(c%i == 0 && c/i <= m) {
        count++; 
      }
    }

    printf("%d\n",count);
  }
  
  return 0;
}
