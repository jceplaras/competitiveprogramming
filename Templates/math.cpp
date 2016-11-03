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

#define MAXN 100
#define MOD 1007

bool prime[MAXN]; 

void sieve(int N) {
  FORN(i,N)
    sieve[i]=[i];
  sieve[0] = 1;
  sieve[1] = 1;

  FORN(i,2,sqrt(N))
    if(sieve[i] == i)
      for(int j=i*i; j<N; j+=i)
        if(sieve[j] == j)
          sieve[j] = i;
} 

int gcd(int a, int b) {
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp}
  return a;
}

int mod_pow(int b, int e) {
  int r = 1;
  b %= MOD;
  while(e>0) {
    if(e%2 == 1)
      r = (r * b)%MOD;
    e/=2;
    b = (b * b)%MOD;
  }
  return r;
}

int main() {
  
  return 0;
}
