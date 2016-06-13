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
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
   
    ull total = 0;
    ull a;
      if( N > 1) {
      FORN(i,N) {
        cin >> a;
        
        total += ((ull)log2(a))+1;
      }
      if(total % 2)
        cout << "Henry" << endl;
      else
        cout << "Derek" << endl;
    }
    else {
      cin >> a;
      int moves = 0;
      while(a > 0) {
        if(a < 6) {
          a /= 6; 
        }else {
          a /= 2;
        }
        moves++;
      }
      if(moves % 2)
        cout << "Henry" << endl;
      else
        cout << "Derek" << endl;

    }
      
      
  }
  
  return 0;
}
