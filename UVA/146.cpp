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
  vector<char> code;
  string s;
  while(true) {
    cin >> s;
    if(s == "#") break;
    FORN(i,s.size())
      code.push_back(s[i]);

    bool x = next_permutation(code.begin(),code.end());
    if(x) { 
    FORN(i,s.size()) {
      printf("%c",code[i]);
    }
    printf("\n");
    }
    else {
      printf("No Successor\n");
    }
    code.clear();
  }
  
  return 0;
}
