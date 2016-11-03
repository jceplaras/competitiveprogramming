#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
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

#define MOD(a,b) (a%b+b)%b
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main() {
  int T;
  scanf("%d",&T);

  ll R[200005];
  ll F[200005];
  ll B[200005];

  while(T--) {
    int N;
    int start, end;

    scanf("%d",&N);

    memset(R, 0, sizeof R);
    memset(F, 0, sizeof R);
    memset(B, 0, sizeof R);

    FOR(i,1,N)  
      scanf("%lld",&R[i]);
    scanf("%d %d",&start,&end);
    start--;
    end--;
  
    FOR(i,1,N) {
      R[i] = R[i] + R[i-1];
    }

    ll costDirect = R[end] - R[start];
    ll costIndirect = R[start] + (R[N] - R[end]);

    ll minVal = min(costDirect,costIndirect);

    ll minVal = min(minval, minVal+R[N]);

    ll minSERcost = 0;
    int minSERend = start;
    ll minESRcost = 0;
    int minESRend = end;

    for(int x = start+1; x < end; x++) {
      ll costFromStart = R[x] - R[start];
      ll costFromEnd = R[end] - R[x];

      if(costFromStart < minSERcost) {
        minSERend = x;
        minSERight = costFromStart;
      }

      if(costFromEnd < minESRcost) {
        minESRend = x;
        minESRcost = costFromEnd;
      }
    }

    if(minSERend > minESRend) {
      ll startToESR = 0;

    }
    else {
      minVal = min(minVal, costIndirect + 2*minESRcost + 2*minSERcost);
    }
    
    printf("%lld\n",costDirect);
    printf("%lld\n",costIndirect);

  }
  
  return 0;
}
