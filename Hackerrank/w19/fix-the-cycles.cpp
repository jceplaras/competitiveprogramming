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
  int a,b,c,d,e,f;


  scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);


  int P = 100000000;
  P = min(P,a+d+e);
  P = min(P,a+b+f);
  P = min(P,a+b+c+d);

  if(P >= 0) printf("-1\n");
  else printf("%d\n",-P);
  
  return 0;
}
