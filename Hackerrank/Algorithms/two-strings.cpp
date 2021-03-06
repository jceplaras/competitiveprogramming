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
  int temp[256];

  char s1[100000];
  char s2[100000];

  bool found = false;
  scanf("%d",&T);

  while(T--) {
    scanf("%s",s1);
    scanf("%s",s2);
    found = false;
    FORN(i,256)
      temp[i]=0;

    FORN(i,strlen(s1))
      temp[s1[i]]=1;

    FORN(i,strlen(s2))
      if(temp[s2[i]] == 1) {
        found = true;
        break;
      }

    if(found)
      printf("YES\n");
    else
      printf("NO\n");

  }
  

  return 0;
}
