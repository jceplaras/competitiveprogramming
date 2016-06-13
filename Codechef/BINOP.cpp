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
  char A[1000005];
  char B[1000005];

  int T;
  cin >> T;
  while(T--) {
    int iZ, iO;
    iZ = iO = 0;
    bool hasZ, hasO;
    hasZ = hasO = false;
    

    cin >> A;
    cin >> B;

    int len = strlen(A);

    FORN(i,len) {
      if(A[i] != B[i]) {
        if(A[i] == '0')
          iZ++;
        else
          iO++;
      }
      if(A[i] == '0')
        hasZ = true;
      else
        hasO = true;
    }


    if(!hasO && iZ != 0)
      cout << "Unlucky Chef" << endl;
    else if(!hasZ && iO != 0)
      cout << "Unlucky Chef" << endl;
    else {
      cout << "Lucky Chef" << endl;
      int X = min(iZ,iO);
      
      cout << X+(iZ-X) + (iO-X) << endl; 
    }
  }
  
  return 0;
}
