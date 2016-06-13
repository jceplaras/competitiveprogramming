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

#define MAX_N 100001
#define MOD 1000000007


ull f[MAX_N];
ull modPow(ull b, ull e) {
  ull res = 1;
  while(e > 0) {
   if(e%2 == 1) res = (res*b)%MOD;
   b = (b*b)%MOD;
   e/=2;
  }
  return res%MOD;
}
ull modInv(ull n) {
  return modPow(n,MOD-2);
}
ull comb(int n, int k) {
  return ((f[n] * modInv(f[k]))%MOD * modInv(f[n-k]))%MOD;
}
void precompute() {
  f[0] = 1;
  FOR(i,1,MAX_N-1)
    f[i]  = (f[i-1] * i)%MOD;

}
int main() {
  precompute();
  

  int T;
  cin >> T;
  while(T--) {
    int N, K;

    scanf("%d %d",&N,&K);
    int cZ = 0;
    int cNZ = 0;

    FORN(i,N) {
      int a;
      scanf("%d",&a);
      if(a != 0) cNZ++;
      else cZ++;
    }
    

    ull inc;
    if(cZ != 0)
      inc = 1;
    else
      inc = 2;

    ull start;
    if(inc == 1 || K%2 == 0)
      start = 0;
    else 
      start = 1;

    ull limit = min(cNZ,K);
    ull ans = 0;    
    while(start <= limit) {
      //cout << "C(" << cNZ << "," << start << ")=" << comb(cNZ,start) << endl;
      ans = (ans + comb(cNZ,start))%MOD;
      start += inc;
    }
    printf("%llu\n",ans);
  }
  
  return 0;
}
