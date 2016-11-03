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

  if(A > B && A > C)
    cout << "Alvin";
  else if(B > A && B > C)
    cout << "Berto";
  else if(C > A && C > B)
    cout << "Carlo";

  cout << endl;
  
  return 0;
}