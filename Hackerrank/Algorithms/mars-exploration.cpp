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
  char str[105];

  scanf("%s",str);
  int len = strlen(str);

  int count = 0;
  for(int i = 0; i<len; i+=3) {
    if(str[i] != 'S') count++;
    if(str[i+1] != 'O') count++;
    if(str[i+2] != 'S') count++;
  }
    
  printf("%d\n",count);
  
  return 0;
}
