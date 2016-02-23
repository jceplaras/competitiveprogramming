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
    if(N < 7)
    printf("-1\n");
    else {
      printf("%d\n",N);
      printf("1 2\n");
      printf("1 3\n");
      printf("2 4\n");
      printf("3 5\n");
      printf("2 6\n");
      printf("3 6\n");
      printf("6 7\n");
      for(int i=8;i<=N;i++) {
        printf("%d 3\n",i);
      }
      printf("1\n");
    }
  } 
  return 0;
}
