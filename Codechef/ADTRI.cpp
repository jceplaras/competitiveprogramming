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

int gcd(int a, int b) {
    int tmp;
    while(b){a%=b; tmp=a; a=b; b=tmp;}
    return a;
}

int main() {
  int c;
  ull M,N;
  bool sumsq[5000001] = {false};
  FOR(m,1,7071) {
    FOR(n,1,m-1) {
      if(gcd(m,n) == 1 && (m-n)%2==1) {
        c = m*m + n*n;
        if(c > 5000000)   
          break;
          sumsq[c] = true;
          FOR(k,2,5000001) {
            if(c*k > 5000000)
              break;
            sumsq[c*k] = true;
          }
        
      }
    }
  }
  

  int T;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&c);
    if(sumsq[c]) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
