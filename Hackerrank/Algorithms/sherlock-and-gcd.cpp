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

unsigned int gcd(unsigned int u, unsigned int v) {
  if(u==v) return u;
  if(u==0) return v;
  if(v==0) return u;

  if(~u&1) 
    if(v&1)
      return gcd(u>>1,v);
    else
      return gcd(u>>1,v>>1)<<1;

  if(~v&1)
    return gcd(u,v>>1);
  if(u>v)
    return gcd((u-v)>>1,v);

  return gcd((v-u)>>1,u);

}
int main() {
  int T;
  int N;
  int values[101];

  scanf("%d",&T);

  while(T--) {
    scanf("%d",&N);
    FORN(i,N)
      scanf("%d",&values[i]);
    if(N >= 2) {
      int gcd_val = gcd(values[0],values[1]);
      FOR(i,2,N-1)
        gcd_val = gcd(gcd_val,values[i]);
      if(gcd_val == 1)
        printf("YES\n");
      else
        printf("NO\n");
    }
    else
      printf("NO\n");   
  }
  return 0;
}
