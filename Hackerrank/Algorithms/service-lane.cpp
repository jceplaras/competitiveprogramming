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

int width[100005];

int main() {
  int T, N;
  int A, B;
  int minVal = 10;
  scanf("%d %d",&N,&T);
  FORN(i,N)
    scanf("%d",&width[i]);
  FORN(i,T) {
    minVal = 10;
    scanf("%d %d",&A,&B);

    FOR(x,A,B) {
      minVal = min(minVal,width[x]);
    }
    printf("%d\n", minVal);
  }
  
  return 0;
}
