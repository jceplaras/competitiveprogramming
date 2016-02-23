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
  bool test[100001];

int main() {

  int N,R;
  FORN(i,100001)
    test[i] = false;
  test[0] = true;
  scanf("%d",&N);
  FORN(i,N) {
    scanf("%d",&R);
    test[R] = true;
  }
  FORN(i,N+1)
    if(!test[i])
      printf("%d ",i);
  printf("\n");
  
  return 0;
}
