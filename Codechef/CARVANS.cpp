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
  int N;
  int T;
  
  int prev;
  int count = 1;
  int c;
  scanf("%d",&T);
  while(T--) {
    count = 1;
    scanf("%d", &N);
    
    scanf("%d", &prev);
    
    for(int i=1;i<N;i++) {
      scanf("%d",&c);
      if(c <= prev)  {
      count++;
      prev = c;
      }
    }
    printf("%d\n",count);
  }
  
  return 0;
}
