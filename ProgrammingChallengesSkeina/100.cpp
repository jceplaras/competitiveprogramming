/*Author:       James Carlo Plaras
 * UVA Problem: 100
 */

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

int store[2000000];

int getN(int n) {
  int ans;
  if( n < 2000000 && n > 0 && store[n]!=0)
    return store[n];
  else if(n==1) return 1;
  else if(n%2==0) {
    ans = getN(n>>1)+1;
    if(n <= 1999999 && n > 0) store[n] = ans;
    return ans; 
  }
  else  {
    ans = getN((3*n+1)>>1)+2;
    if(n <= 1999999 && n > 0) store[n] = ans;
    return ans;
  }
}

int main() {
  int i,j;
  int xI, xJ;
  int mx;
  while(scanf("%d %d",&i,&j)!=-1) {
    mx = 0;
    if(i>j) {
      xJ = i; xI = j;
    }
    else {
      xJ = j; xI = i;
    }
    FORD(x,xJ,xI) {
      mx = max(mx,getN(x));
    }
    printf("%d %d %d\n",i,j,mx);
  }
  return 0;
}
