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

#define MOD 1000000007

char a[100005];
char b[100005];
ull table[100005];

#define CHECK(a,i) ((a[i] == '1' && a[i+1] == '1' && a[i+2] == '1') || (a[i] == '2' && a[i+1] == '2' && a[i+2] == '1'))

#define UNCHECK(a,i) ((a[i] == '2' && a[i+1] == '1' && a[i+2] == '2') || (a[i] == '2' && a[i+1] == '2' && a[i+2] == '2'))

int len;  

ull f(int i) {
  if(i == len-1) {
      return table[i-3]*2;
  }

  if(UNCHECK(a,i-3) || UNCHECK(b,i-3)) {
    return 0;
  }
  if(CHECK(a,i-3) && CHECK(b,i-3)) {
    table[i] = table[i] + (table[i-3] * 2);
  }

  if(a[i] == b[i])
    return (2*f(i+1))%MOD;
  else {
    int c = 0;
    c = (c + f(i+1))%MOD;
    char x = a[i];
    a[i] = b[i];
    b[i] = x;
    c = (c + f(i+1))%MOD;
    x = a[i];
    a[i] = b[i];
    b[i] = x;
    
    return c;
  }
}

int main() {
  int T;
  scanf("%d",&T);

  while(T--) {
    scanf("%s",&a[3]);
    scanf("%s",&b[3]);

    FORN(i,3) {
      a[i] = b[i] = '1';
      table[i] = 1;
    }
    
    len = strlen(a);

    cout << f(3) << endl; 


  }
  return 0;
}
