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
  int T;
  scanf("%d",&T);

  while(T--) {
    int N;
    scanf("%d",&N);
    int maxScore = -1;
    int win = 0;
    bool tie = false;

    FORN(n,N) {
      int C;
      scanf("%d",&C);
      int T[6];
      memset(T,0,sizeof T);
      FORN(i,C) {
        int t;
        scanf("%d",&t);

        T[t-1]++;
      }
      sort(T,T+6);
      /*printf("[");
      FORN(i,6)
        printf("%d ",T[i]);
      printf("]\n");
      */

      int score = C;
      score = max(score,C+T[0]*4);
      score = max(score,C+(T[1]-T[0])*2);
      score = max(score,C+max(0,(T[2]-(T[1]+T[0]))));
      //printf("score = %d\n",score);

      if(maxScore == score) {
        maxScore = score;
        tie = true;
        win = n;
      }
      else if(score > maxScore) {
        tie = false;
        maxScore = score;
        win = n;
      }
    }
    if(tie)
      printf("tie\n");
    else if(win == 0)
      printf("chef\n");
    else
      printf("%d\n",win+1);
  }
  
  return 0;
}
