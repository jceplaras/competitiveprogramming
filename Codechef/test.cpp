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
int prime[N+1];
int phiC[N+1];
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

ull phi(ull n) {
    ull ret = 1;
      while(n>1) {
            int p = prime[n];
                int e = 0;
                    while(n%p == 0) {
                            n/=p;
                                  e++;
                                      }

                        ret *= (p-1)*pow((double)p,e-1);
                          }
        return ret;
}

ull resr(ull n) {
    ull result = 0;
      for(ull d=1;d<=n;d++) {
            if(n%d == 0) {
                    result += d*phi(d);
                        }
              }
        return result;
}

ull fexp(ull b,ull e) {
  ull r = 1;
  while(true) {
    if(e%2 == 1) r*=b;
    e/=2;
    if(e == 0) break;
    b*=b;
  }
  return r;
}

ull resr2(ull n) {
  ull ret = 1;
  while(n>1) {
    ull p = prime[n];
    ull e = 0;
    while(n%p == 0) {
      n/=p;
      e++;
    }
    ret *= (fexp(p,2*e+1)+1)/(p+1);
  }
  return ret;
}

int main() {
    sieve();
        int T;
          scanf("%d",&T);
          for(ull n=9000000;n<=T;n++) {
            printf("%llu %llu ",n,(resr(n)==resr2(n)));
            printf("%llu %llu\n",resr(n),resr2(n));
            if(resr(n)!=resr2(n)) break;
                          }
                return 0;
}

