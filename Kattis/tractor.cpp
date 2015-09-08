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

  ull temp[200000004];
int main() {
  int A;
  int B;
  int T;

  scanf("%d",&T);
  while(T--) {

  scanf("%d %d",&A,&B);
  if(B > A) {
    int temp = A;
    A = B;
    B = temp;
  }

  double dblA = A;
  double dblB = B;

  ull sum = floor(log2(dblA+1))+1;

  for(int b=1;b<=B;b++) {
    sum += (floor(log2(dblA+b+1))+1) -(floor(log2(b))+1);
  }

  printf("%llu\n",sum);

  }

  return 0;
}
