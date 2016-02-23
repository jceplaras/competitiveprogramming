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
  int S,B;
  bool sold[100005];
  int  left[100005];
  int right[100005];
  while(true) {
    scanf("%d %d",&S,&B);

    if(S == 0 && B == 0) break;

    FORN(i,S+2) {
        sold[i] = true;
        left[i] = i-1; 
        right[i] = i+1;
    }
    int L,R;
    FORN(i,B) {
      scanf("%d %d",&L,&R);
      right[left[L]] = right[R];
      left[right[R]] = left[L];

      if(left[L] == 0) printf("* ");
      else printf("%d ",left[L]);

      if(right[R] == S+1) printf("*\n");
      else printf("%d\n",right[R]);
    }
    printf("-\n");
  }
  
  return 0;
}
