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

 int SN, P;

  while(true) {
    scanf("%d %d",&SN,&P);

    if(SN == 0 && P == 0) break;

    int startX = SN/2 +1;
    int startY = SN/2 +1;
    
    int incX = 0;
    int incY = 1;
    int maxLen = 1;
    int cLen = 0; 
    int i = 1;
    while(true) {
      if(i==P) {
        printf("Line = %d, column = %d.\n",startY,startX);
        break;
      }
      if(i+maxLen <= P) {
      startX+=incX*maxLen;
      startY+=incY*maxLen;
      i+=maxLen;
      }
      else {
      startX+=incX*(P-i);
      startY+=incY*(P-i);
      i=P;
      }

        if(incX == 0 && incY == 1) { //up
          incX = -1;
          incY = 0;
        }
        else if(incX == -1 && incY == 0) { //left
          incX =0;
          incY = -1;
          maxLen++;
        }
        else if(incX == 0 && incY == -1) {
          incX = 1;
          incY = 0;
        }
        else if(incX == 1 && incY == 0) {
          incX = 0;
          incY = 1;
          maxLen++;
        }
    }
  }
  
  return 0;
}
