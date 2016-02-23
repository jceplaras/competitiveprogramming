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

ull arr[100001];

ull fastExpMod(ull b, ull e, ull p) {
  ull r = 1;
  while(e > 0) {
    if(e %2 == 1) r = (r*b)%p;
    b=(b*b)%p;
    e >>= 1;
  }
  return r;
}

ull modInvPrime(ull a, ull p) {
  return fastExpMod(a,p-2,p);
}

ull modComb(ull n, ull k) {
  if(n==k || k==0) return 1;
  ull num = 1;
  ull den = 1;
  for(ull i=0;i<k;i++)
    num = (num%MOD * (n-i)%MOD)%MOD;
  for(ull i=1;i<=k;i++)
    den = (den%MOD * i%MOD)%MOD;


  den = modInvPrime(den,MOD);
  ull r = (num%MOD * den%MOD)%MOD;

  return r;
    
}

ull modComb2(ull n, ull k, ull den) {
  if(n==k || k==0) return 1;
  if(k==1) return n%MOD;
  ull num = 1;
  for(ull i=0;i<k;i++)
    num = (num%MOD * (n-i)%MOD)%MOD;

  ull r = (num%MOD * den%MOD)%MOD;

  return r;
}


ull modFact(ull n) {
  ull r = 1;

  for(;n>1;n--)
    r = (n*r)%MOD;

  return r;

}

int main() {
  int T;

  scanf("%d",&T);
  ull N, X, M;
  ull temp;
  while(T--) {
   scanf("%llu %llu %llu",&N, &X, &M);
   for(int i=1;i<=N;i++) {
     scanf("%llu",&temp);
     arr[i] = temp%MOD;
   }


   ull den = modFact(M-1);
   ull denMod = modInvPrime(den,MOD);

   ull res = 0;
   ull temp = 0;
   for(int i=X,up=M-1;i>0;i--,up++) {
     temp = (arr[i] * modComb2(up,M-1,denMod))%MOD;
     res = (res%MOD + temp%MOD)%MOD;
   }
   printf("%llu\n",res);
  }
  
  return 0;
}
