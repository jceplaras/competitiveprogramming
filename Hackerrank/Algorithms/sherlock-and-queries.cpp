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
#define MOD 1000000007
int main() {
  int N,M;
  scanf("%d %d",&N,&M);

  ull A[100002];
  int B[100002];
  int C[100002];
  ull T[100002];

  FOR(i,1,N){
    scanf("%llu",&A[i]);
    T[i]=1;
  }
  FOR(i,1,M)
    scanf("%d",&B[i]);
  FOR(i,1,M){
    scanf("%d",&C[i]); 
    T[B[i]] = (T[B[i]]%MOD * C[i]%MOD)%MOD; 
  }
  FOR(i,1,N) {
    int j = i;

    while(j <= N) {
      A[j] = (A[j]%MOD * T[i]%MOD)%MOD;
      j+=i;
    } 
  }
    
  FOR(i,1,N)
    printf("%llu ",A[i]);
  printf("\n");
  return 0;
}
