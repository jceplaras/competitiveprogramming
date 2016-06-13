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


ull fact[15];
char temp[100000];
int main() {
  fact[0] = 1;
  FOR(i,1,14) { 
    fact[i] = fact[i-1] * i;
  }

  int T;
  char mm[256];
  scanf("%d",&T);
  while(T--) {
    FORN(i,256)
      mm[i] = 0;
    
    scanf("%s",temp);
      
    int n = strlen(temp);

    FORN(i,n) {
      mm[temp[i]]++;
    }
    ull answer = fact[n];

    FOR(i,'a','z') {
      answer /= fact[mm[i]];
    }

    ull tt = 0;

    FOR(i,1,n-3) {
      tt += (((ull)((pow(2,n-2-i)-1))) * fact[n-1])/fact[i-1];
      printf("%llu--\n",(((ull)((pow(2,n-2-i)-1))) * fact[n-1])/fact[i-1]);
    }
    printf("%llu\n",tt);

    answer = answer * tt;
    printf("%llu\n",answer);
  }

  
  return 0;
}
