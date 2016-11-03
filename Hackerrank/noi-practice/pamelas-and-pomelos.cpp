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

  int A, B, C;

  cin >> A >> B >> C;

  A = abs(A);
  B = abs(B);
  C = abs(C);

  if(A < B && A < C)
    cout << "PAMELA I";
  else if(B < A && B < C)
    cout << "PAMELA II";
  else if(C < A && C < B)
    cout << "PAMELA III";

  cout << endl;
  
  return 0;
}
