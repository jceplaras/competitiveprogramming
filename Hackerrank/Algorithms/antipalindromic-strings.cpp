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
#define MOD 1000000009

ull mod_power(ull base, ull n) {
  ull result = 1;
  base = base%MOD;

  while(n > 0) {
    if(n&1)
      result = (result *base)%MOD;
    n = n >> 1;
    base = (base * base)%MOD;
  }
  return result;
}
ull mod_perm(ull n, ull k) {
  ull result = 1;
  ull limit = n-k;
  while(n > limit) {
    result = (result%MOD * n%MOD)%MOD;
    n--;
  }
  return result;
} 
int main() {
  int T,N,M;

  scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&N,&M);
    ull all = mod_power(M,N);
    ull palin = 0;
    ull temp = 1;

    FOR(i,2,N) {
      temp = (temp%MOD * mod_power(M,i/2+i%2)%MOD)%MOD;
      temp = (temp%MOD * mod_power(M,N-i)%MOD)%MOD;
      temp = (temp%MOD * (N-i+1)%MOD)%MOD;

      palin = (palin%MOD + temp%MOD)%MOD;
    }
    printf("%llu\n",all);
    printf("%llu\n",palin);

    ull antipalin = (all%MOD - palin%MOD)%MOD;
    printf("%llu\n",antipalin);
  }
  return 0;
}
