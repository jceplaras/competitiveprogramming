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
  char str[100001];int len;
  char prev='C';

  int T;
  int del;
  scanf("%d",&T);
  while(T--) {
    prev = 'C';
    scanf("%s",str);
    len = strlen(str);
    del = 0;
    FORN(i,len) {
      if(prev != str[i]) {
        prev = str[i];

      }
      else
        del++;


    }
    printf("%d\n",del);
  }

  return 0;
}
