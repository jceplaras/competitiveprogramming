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

  int A[100005];
  int p[100005];
  int x[100005];

  int T;

  scanf("%d",&T);

  while(T--) {
    int N;
    scanf("%d",&N);

    FORN(i,N) {
      scanf("%d",&A[i]);
      p[i] = -1;
      x[i] = -1;
    }
    int count = 0;

    FORN(i,N) {
      if(p[i]==-1) {
        int cc = 1;
        int curr = i;
        int last = -1;

        //printf("Start at %d\n",i);
        while(p[curr] == -1) {
          //printf("\tCurr at %d\n",curr);
          p[curr] = cc;
          x[curr] = i;
          cc++;
          last = curr;
          curr = (curr + A[curr] + 1)%N;
        }
        
        if(x[last] == x[curr])
        count += p[last] - p[curr] + 1;
      }
    }

    printf("%d\n",count);
  }
  
  return 0;
}
