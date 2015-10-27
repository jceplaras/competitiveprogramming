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

#define swap(a,b) t=a,a=b,b=t

int main() {
  short cards[60];
  int sis[3];
  int bro[2];
  while(true) {
    scanf("%d %d %d %d %d",&sis[0],&sis[1],&sis[2],&bro[0],&bro[1]);
    if(sis[0]+sis[1]+sis[2]+bro[0]+bro[1] == 0)  break;
    FORN(i,60)
      cards[i]=0;
    
    cards[sis[0]] = 1;
    cards[sis[1]] = 1;
    cards[sis[2]] = 1;
    cards[bro[0]] = 1;
    cards[bro[1]] = 1;

    int t;
    if(sis[0] > sis[1]) swap(sis[0],sis[1]);
    if(sis[1] > sis[2]) swap(sis[1],sis[2]);
    if(sis[0] > sis[1]) swap(sis[0],sis[1]);
    if(bro[0] > bro[1]) swap(bro[0],bro[1]);
    int count = 0;

    //printf("S:%d %d %d\n",sis[0],sis[1],sis[2]);
    //printf("B:%d %d\n",bro[0],bro[1]);
    for(int i = 1; i>=0;i--) {
      for(int j=0;j<3;j++) {
        if(sis[j] > bro[i]) {
          count++;
          sis[j] = -1;
          bro[i] = 999;
        }
      }
    }

    if(count == 2) {
      printf("-1\n");
    }
    else {
      int M;
      M = max(sis[0],max(sis[1],sis[2]));
      if(count == 0)
        M = 1;
      for(M=M;M<=52;M++)
        if(cards[M] == 0) {
          printf("%d\n",M);
          break;
        }

      if(M > 52) 
        printf("-1\n");
    }
  }
  
  return 0;
}
