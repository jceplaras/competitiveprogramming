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
  int N;

  scanf("%d",&T);

  while(T--) {
    scanf("%d",&N);
    int countFive = N/3;
    int countThree;
    for(;countFive>=0;countFive--) {
      countThree = N-(countFive*3);
      if(countThree%5 == 0)
        break;
    }

    if(countFive == -1)
      printf("-1\n");
    else {
      for(int i=0;i<countFive;i++) {
        printf("555");
      }
      for(int i=0;i<countThree;i++)
        printf("3");
      printf("\n");
    }
  }

  return 0;
}
