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
  int m[10001];
  
  int T;
  int N;
  int temp;
  int mx = 10001;
  
  int ans;
  scanf("%d", &T);
  
  while(T--) {
    
    scanf("%d", &N);
    ans = 0;
    mx = 10001;
    FORN(i,N) {
      scanf("%d",&m[i]);
      if(m[i] < mx)
        mx = m[i];
    }
    
    FORN(i,N) {
      ans+=(m[i]-mx);
    }
    
    printf("%d\n",ans);
  
  }
  
  return 0;
}
