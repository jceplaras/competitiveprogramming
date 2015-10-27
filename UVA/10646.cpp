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
int getCardVal(char c) {
  if(c >= '2' && c <= '9') 
    return c-'2'+2;
  else
    return 10;
}
int main() {
  char cards[60][3];

  int T;
  scanf("%d",&T);

  FORN(c,T) {
    FOR(i,1,52) {
      scanf("%s",cards[i]);
    }
    int top = 27;
    int Y = 0;
    FORN(i,3) {
     // printf("TOP:%s\n",cards[top]);
      int X = getCardVal(cards[top][0]);
     // printf("value of %c is %d\n",cards[top][0],X);
      Y += X;
      top-=(10-X)+1;
    }
    for(int x=top+1,y=28;y<=52;x++,y++) {
      cards[x][0] = cards[y][0];
      cards[x][1] = cards[y][1];
    }

    printf("Case %d: %s\n",c+1,cards[Y]);
  }
  
  return 0;
}
