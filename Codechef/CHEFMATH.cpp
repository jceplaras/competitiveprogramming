#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
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
#define MAXVAL 1000000000

vi fibo;
unordered_map <int,unordered_map<int,unordered_map<int,int> > > test;

ull part(int n, int m, int k) {
  if(m == 0)
    return 0;
  if(n < 0)
    return 0;
  if(n != 0 && k == 0)
    return 0;
  if(n == 0 && k == 0)
    return 1;
  if(n/fibo[m] > k)
    return 0;
  ull sum = 0;

  if(test.find(n) != test.end()) {
    if(test[n].find(m) != test[n].end()) {
      if(test[n][m].find(k) != test[n][m].end()) {
        return test[n][m][k];
      }
    }
  }

  //test[n][m][k] = (part(n,m-1,k) + part(n-fibo[m],m,k-1))%MOD;
  FOR(i,1,m)
  sum = (sum + part(n-fibo[i],i,k-1))%MOD;
  test[n][m][k] = sum; 
  return test[n][m][k];
}
int main() {
  fibo.push_back(0);
  int A = 1;
  int B = 2;
  fibo.push_back(1);
  fibo.push_back(2);
  int C;
  
  do {
    C=A+B;
    if(C > MAXVAL) break;
    fibo.push_back(C);
    A=B;
    B=C;
  }while(true);
  
  int T;
  int X,K;

  scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&X,&K);
    printf("%llu\n",part(X,fibo.size()-1,K));
  }
  return 0;
}
