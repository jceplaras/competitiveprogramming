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

#define aV(newX,newY,newZ) tx=newX;ty=newY;tz=newZ;x=tx;y=ty;z=tz 

int main() {
  int L;

  int x,y,z;
  int tx,ty,tz;


  while(true) {
    scanf("%d",&L);
    if(L == 0) break;
    aV(1,0,0);

    string s;
    FORN(i,L-1) { 
      cin >> s;
      if(s.compare("+z") == 0) {
        //positive Y rotation
        aV(-z,y,x);
      }
      if(s.compare("-z") == 0) {
        //negative Y rotation
        aV(z,y,-x);
      }
      if(s.compare("+y") == 0) {
        //positive Z rotation
        aV(-y,x,z);
      }
      if(s.compare("-y") == 0) {
        //negative Z rotation
        aV(y,-x,z);
      }

    }

    if(x > 0)
      printf("+x");
    else if(x < 0)
      printf("-x");
    else if(y > 0)
      printf("+y");
    else if(y < 0)
      printf("-y");
    else if(z > 0)
      printf("+z");
    else if(z < 0)
      printf("-z");
    printf("\n");

  }
  return 0;
}
