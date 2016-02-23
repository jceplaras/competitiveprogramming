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
  scanf("%d",&T);
  ull n1,n2,m;

  while(T--) {
    scanf("%llu %llu %llu",&n1,&n2,&m);

    ull sum = (m*(m+1))/2;

    ull minN = min(n1,n2);

    if(minN < sum) {
      ull candM = (ull)((sqrt(8*minN + 1)-1)/2);

      ull candMSum = (candM*(candM+1))/2;

      printf("%llu\n",(n1-candMSum)+(n2-candMSum));


    }
    else {
      printf("%llu\n",(n1-sum)+(n2-sum));
      
    }
    
  }
  
  return 0;
}
