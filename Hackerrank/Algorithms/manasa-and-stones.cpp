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
  short check[1000001]; 
  int T;
  int N, A, B;
  int sum;
  scanf("%d",&T);

  while(T--) {
    FORN(i,1000001)
      check[i] = 0;
    scanf("%d %d %d",&N,&A,&B);
    for(int i=0;i<=N-1;i++) {
      sum = i*A + (N-1-i)*B;
      check[sum]=1;
    }
    for(int i=0;i<1000001;i++) {
      if(check[i] == 1)
        printf("%d ",i);
    }
    printf("\n");
  }
  return 0;
}
