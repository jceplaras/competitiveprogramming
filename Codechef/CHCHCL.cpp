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

int g(int x) {
  return (x+1)%2;
}

int main() {

  int T;
  scanf("%d",&T);
  while(T--) {
    int n,m;
    scanf("%d %d",&n,&m);

    if((g(n) | g(m)) != 0)
      printf("Yes\n");
    else
      printf("No\n");

  }
  
  return 0;
}
