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
  char s[100005];
  scanf("%d",&T);

  while(T--) {
    scanf("%s",s);
    int len = strlen(s);

    int z = 0;
    int o = 0;

    FORN(i,len)
      if(s[i] == '0')
        z++;
      else
        o++;
  }
  
  return 0;
}
