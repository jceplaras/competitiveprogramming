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
  int A[1005];

  int N;
  scanf("%d",&N);
  FORN(i,N)
    scanf("%d",&A[i]);

  int minVal = 100000;
  FORN(i,N) {
    FORN(j,i) {
      int dist = i-j;

      if(A[i] == A[j])
        minVal = min(minVal,dist);
    }
  }

  if(minVal == 100000)
    minVal = -1;

  printf("%d\n",minVal);
  
  return 0;
}
