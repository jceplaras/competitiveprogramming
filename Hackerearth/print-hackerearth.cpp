#include <algorithm>
#include <cmath>
#include <climits>
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

int M[1000];

int main() {

  int N;
  scanf("%d",&N);

  char str[1000001];

  scanf("%s",str);

  FORN(i,N)
    M[str[i]]++;

  int minVal = INT_MAX;

  minVal = min(minVal,M['h']/2);
  minVal = min(minVal,M['a']/2);
  minVal = min(minVal,M['c']);
  minVal = min(minVal,M['k']);
  minVal = min(minVal,M['e']/2);
  minVal = min(minVal,M['r']/2);
  minVal = min(minVal,M['t']);

  printf("%d\n",minVal);

  

  
  return 0;
}
