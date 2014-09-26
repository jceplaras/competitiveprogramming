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

int store[1000000];

int getN(int n) {
  //printf("%d\n",n);
  if(store[n]!=0) return store[n];
  else if(n==1) return 1;
  else if(n%2==0) return store[n]=getN(n/2)+1;
  else return store[n]=getN(3*n+1)+1;
}

int main() {
  //printf("num: %d\n",getN(22)); 
  int i,j;
  int mx;
  while(scanf("%d %d",&i,&j)!=-1) {
    mx = 0;
    FOR(x,i,j) {
      mx = max(mx,getN(x));
    }
    printf("%d %d %d\n",i,j,mx);
  }
  return 0;
}
