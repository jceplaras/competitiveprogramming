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
#define SWAP(a,b) { temp = a; a =b; b = temp; }
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main() {
  ll a,b,c;  
  ll temp;
  ll ans = 1;
  int T;
  
  scanf("%d",&T);
  while(T--) {
    scanf("%lld %lld %lld",&a,&b,&c);
    ans = 1;
    if(a > b)
      SWAP(a,b)
    if(b > c)
      SWAP(b,c)
    if(a > b)
      SWAP(a,b)
    
    ans = (ans * (a%MOD))%MOD;
     //printf("%lld\n",ans);
    b-=1;
    ans = (ans * (b%MOD))%MOD;
     //printf("%lld\n",ans);
    c-=2;
    ans = (ans * (c%MOD))%MOD;
    
    
    
    
    //printf("%d %d %d\n",a,b,c);
    printf("%lld\n",ans);
  }
  
  
  return 0;
}
