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
#define N 10000000
ull prime[N+1];
void sieve() {
  FORN(i,N) prime[i] = 0;
  prime[0] = prime[1] = 1;

  for(ull i=2;i<=N;i++) {
    if(!prime[i]) {
      prime[i] = i;
      for(ull j=i;j*i<=N;j++) {
        prime[j*i] = i;
      }
    }
  }
}

ull fexp(ull b,ull e) {
  ull r = 1;
  while(true) {
    if(e%2 == 1) {
      r *= b;
    }
    e/=2;
    if(e == 0) break;
      b*=b;
  }

  return r;
}

ull phi(ull n) {
  ull ret = 1;
  while(n>1) {
    ull p = prime[n];
    ull e = 0;
    while(n%p == 0) {
      n/=p;
      e++;
    }
    printf("%llu %llu ",p,e);
    printf("%llu %llu %llu\n",fexp(p,2*e + 1)+1,p+1,(fexp(p,2*e + 1)+1)/(p+1));
    ret *= (fexp(p,2*e + 1)+1)/(p+1); 
  }
  return ret;
}

int main() {
  sieve();
  int T;
  int n;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    printf("%llu\n",phi(n));
  }
  return 0;
}
