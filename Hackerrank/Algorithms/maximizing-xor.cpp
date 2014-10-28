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
  int A, B;
  int maxVal = 0;

  scanf("%d %d",&A,&B);

  FOR(i,A,B)
    FOR(j,i,B) {
      maxVal = max(maxVal,i^j);
    }

  printf("%d\n",maxVal);
  
  
  return 0;
}
