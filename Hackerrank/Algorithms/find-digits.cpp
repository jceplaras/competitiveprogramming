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
  int T;
  long long int N;

  scanf("%d",&T);

  while(T--) {
    scanf("%lld",&N);
    int count = 0;

    long long int X = N;
    while(N > 0) {
      int c = N%10;
      N = N/10;

      if(c!=0&&X%c==0)
        count++;  
    }
    printf("%d\n",count);
  }
  return 0;
}
