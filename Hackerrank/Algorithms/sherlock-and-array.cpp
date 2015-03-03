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
  int N;
  int A[100005];
  bool found = false;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&N);
    A[0] = 0;
    found = false;
    FORN(i,N){
      scanf("%d",&A[i+1]);
      A[i+1] += A[i];
    }
    A[N+1] = A[N];
    
      FOR(i,1,N) {
        if(A[i-1] == (A[N+1]-A[i])){
          found = true; 
          break;
        }
      }

    if(found)
      printf("YES\n");
    else
      printf("NO\n");
    
  }
  
  return 0;
}
