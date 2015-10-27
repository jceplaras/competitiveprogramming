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

int main() {
  int N;
  double P;
  double L;
  int T;
  double dArr[101];

  while(true) {
    scanf("%d %lf %lf %d",&N,&P,&L,&T);
    if(N < 0) break;

    FORN(i,101)
      dArr[i] = 0;

    int m;
    double d;
    while(T--) { 
      scanf("%d %lf",&m,&d);
      dArr[m] = d;
    }
    //FORN(i,10)
    //  printf("%lf ",dArr[i]);
    //printf("\n");

    double prev = -1;
    FORN(i,N+1) {
      if(dArr[i] != 0)
        prev = dArr[i];
      dArr[i] = prev;
    }

    double car = L+P;
    double loan = L;
    double Pay = loan/N;
    int month=0;
    car = (1-dArr[0])*car;
    if(loan >= car)
    for(int i=1;i<=N;i++) {
      car = (1-dArr[i])*car;
      loan -= Pay;
      if(loan < car) {
        month = i;
        break;
      }
    }

    if(month == 1) {
      printf("1 month\n");
    }
    else 
      printf("%d months\n",month);

  }
  
  return 0;
}
