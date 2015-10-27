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

#define swap(a,b,t) t=a,a=b,b=t

int main() {
  int N;
  int a,b,c;
  int t;
  int cc=1;
  scanf("%d",&N);
  while(N--) {
    scanf("%d %d %d",&a,&b,&c);
    //printf("%d %d %d\n",a,b,c);
    if(a > b)
      swap(a,b,t);
    //printf("%d %d %d\n",a,b,c);
    if(b > c)
      swap(b,c,t);
    //printf("%d %d %d\n",a,b,c);
    if(a > b)
      swap(a,b,t);
    //printf("%d %d %d\n",a,b,c);

    printf("Case %d: %d\n",cc++,b);
  }
  
  return 0;
}
