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
  int A, B;

  scanf("%d",&T);

  while(T--) {
    scanf("%d %d",&A,&B);
    printf("%d\n",(int)(floor(sqrt(B)) - ceil(sqrt(A)) + 1));
  }
  return 0;
}
