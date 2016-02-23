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
int cmp(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int q[5001];
  
  int min = 1000000000;
  int temp;
  int T;
  int N;
  scanf("%d",&T);
  
  while(T--) {
    min = 1000000000;
    scanf("%d",&N);
    FORN(i,N) {
      scanf("%d",&q[i]);
      FORN(j,i) {
        temp = abs(q[i]-q[j]);
        min = (temp<min)?temp:min;
      }
    }
    
      printf("%d\n",min);
  }
  
  
  return 0;
}
