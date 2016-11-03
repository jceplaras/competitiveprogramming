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
  char str[100];
  char x;

  while(true) {
    scanf("%s",str);

    if(strcmp(str,"0") == 0) break;
    
    int N;
    int I[10001];
    int M[10001];
    memset(I,0,sizeof I);
    sscanf(str,"%d%c",&N,&x);

    FORN(i,N) {
      scanf("%d",&M[i]);
      I[M[i]] = i;
    }
    
    bool anti = false;
    FORN(i,N-2) {
      FOR(j,i+1,N-2) {

        int diff = M[j] - M[i];   
        int target = M[i] + diff*2;
        
        if(target > 0 && target < N && I[target] > j) {
          anti = true;
          break;
        }

      }
      if(anti) break;
    }

    if(anti) printf("no\n");
    else printf("yes\n");
    
  }
  
  return 0;
}
