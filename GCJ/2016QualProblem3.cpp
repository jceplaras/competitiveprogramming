#include <algorithm>
#include <bitset>
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

int isPrime(ull n) {
  if(n%2 == 0) return 2;
  if(n%3 == 0) return 3;

  int i = 5;
  int w = 2;

  while(i*i <= n) {
    if(n%i == 0) return i;

    i += w;
    w = 6 - w;
  }

  return 0;
}

int main() {
  ull mMin, mMax;
  ull ONE = 1;

  int N;
  cin >> N;
  mMin = (ONE << (N-1)) + 1;
  cout << mMin << endl;

  mMax = (ONE << N) - 1; 
  cout << mMax << endl;

  for(ull i=mMin;i<=mMax;i++) {
    //bitset<32> X(i);
    //cout << X << endl;
  }

  return 0;
}
