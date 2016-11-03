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

int intLog2(int N) {
  if(N == 0) return 0;
  else return (int)log2(N);
}

int g(int N) {
  if(N%2 == 0) return 1;
  else return 0;
}

int A[1000001];

int main() {

  int N,Q;
  scanf("%d %d",&N,&Q);

  FOR(i,1,N) {
    int a;
    scanf("%d",&a);

    A[i] = g(intLog2(a));
  }

  A[0] = 0;
  FOR(i,1,N)
    A[i] ^= A[i-1];

  FORN(i,Q) {
    int L,R;
    scanf("%d %d",&L,&R);

    int temp = g(A[L-1])^g(A[R]); 


    if(temp != 0)
      printf("Mishki\n");
    else
      printf("Hacker\n");
  }

  
  return 0;
}
