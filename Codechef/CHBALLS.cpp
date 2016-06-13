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

  
  printf("1\n");
  fflush(stdout);
  printf("3 1 1 2\n");
  fflush(stdout);
  printf("3 3 3 4\n");
  fflush(stdout);

  int x;
  scanf("%d",&x);
  printf("2\n");
  fflush(stdout);
  if(x == 0)
    printf("5\n");
  else if(x == 1)
    printf("2\n");
  else if(x == 2)
    printf("1\n");
  else if(x == -1)
    printf("4\n");
  else 
    printf("3\n");
  fflush(stdout);
  
  return 0;
}
