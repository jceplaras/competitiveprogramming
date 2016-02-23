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

int gcd(int a, int b) {
  int tmp;
  while(b) {
    a%=b; tmp=a; a=b; b=tmp;
  }
  return a;
}

int main() {
  int T;
  int N,M;

  scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&N,&M);
    int g = 0;
    if(M == 0 || N==M) {
      g = N;
    }
    else {
      g=gcd(N,M);
    }

    int ans = N/g;
    if(ans == N) {
      printf("Yes\n");
    }
    else
      printf("No %d\n",ans);
    
  }
  
  return 0;
}
