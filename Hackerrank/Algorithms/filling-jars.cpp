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
  unsigned long long int total;

  int N,M;
  unsigned long long int a,b,k;
  scanf("%d %d",&N,&M);
  FORN(i,M) {
    scanf("%llu %llu %llu",&a,&b,&k);

    total += (b-a+1)*k;
  }  
  printf("%llu\n",total/N);
  return 0;
}
