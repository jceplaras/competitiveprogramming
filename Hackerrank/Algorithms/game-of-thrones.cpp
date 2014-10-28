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
int mm[256];
int main() {
  char str[100005];
  scanf("%s",str);

  int len = strlen(str);

  FORN(i,len)
    mm[str[i]]++;
  
  int p = 0;
  FORN(i,256) {
    if(mm[i]%2 != 0)
      p++;
  } 

  if(p > 1)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}
