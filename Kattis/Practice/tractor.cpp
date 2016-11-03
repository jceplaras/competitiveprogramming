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

int uint64_log2(ull n)
{
    if(n == 1) return 0;
    int ret = 0;
    while(n > 1) {
        n >>= 1;
        ret++;
    }
    return ret;
}

int main() {
  int A;
  int B;
  int T;

  scanf("%d",&T);
  //printf("%d",int(log2(200000001)+1));
 while(T--) {
//for(A=1;A<=T;A++)
//    for(B=1;B<=A;B++) {
  scanf("%d %d",&A,&B);
  if(B > A) {
    int temp = A;
    A = B;
    B = temp;
  }

  double dblA = A;
  double dblB = B;

  int sum = uint64_log2(A+1)+1;

  for(int b=1;b<=B;b++) {
    sum += uint64_log2(A+b+1)-uint64_log2(b);
  }

  printf("%llu\n",sum);

  }

  return 0;
}
