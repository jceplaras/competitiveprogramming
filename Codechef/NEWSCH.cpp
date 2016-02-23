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

#define MOD 1000000007

long modpow(int exponent) {
    long result = 1;
    ll base = 3;
    while(exponent>0) {
        if (exponent%2==1)
           result=(result*base)%MOD;
        exponent = exponent >> 1;
        base = (base * base)%MOD;
       // printf("-%lld\n",base);
        }
    //printf("=%ld\n",result);
    return result;
}

int main() {
  int T;
  int N;
  
  long res;
  scanf("%d",&T);
  while(T--) {
  scanf("%d",&N);
    
    res = modpow(N);
  
    if(N&1)
      res = (res-3)%MOD;
    else
       res = (res+3)%MOD;
    printf("%ld\n",res);
  }
  
  return 0;
}
