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

ull dRoot(ull n) {
  if(n==0) return 0;
  if(n%9==0) return 9;
  return n%9;
}

int main() {
  int T;
  ull rep[10];
  scanf("%d",&T);
  ull A,D,L,R;
  ull sum;
  int r;
  while(T--) {
    scanf("%llu %llu %llu %llu",&A,&D,&L,&R);
    FORN(i,10)
      rep[i] = 0;
    rep[1]=dRoot(A);
    A=A+D;
    int r=1;
    FOR(i,2,9) {
      ull dR = dRoot(A);
      if(dR == rep[1]) break;
      rep[i]=dR + rep[i-1];
      A=A+D;
      r++;
    }
   /* printf("\n");
    printf("%d\n",r);
    FORN(i,r+1)
      printf("%llu ",rep[i]);
    printf("\n");
  */  
    ull right = (R/r)*rep[r] + rep[R%r];
    ull left = ((L-1)/r)*rep[r] + rep[(L-1)%r];
    //printf("%llu-%llu %llu\n",right,left,right-left); 
    printf("%llu\n",right-left);
    
  }

  
  return 0;
}
