#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
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

#define MAXD numeric_limits<double>::max()
int main() {
  int N;
  int P;

  string name;
  int caseNo = 1;
  while(true) {
    scanf("%d %d\n",&N,&P);
    if(N == 0 && P == 0) break;

    FORN(i,N) {
      getline(cin,name);
    }

    string bestRFP = "";
    double bestPrice = MAXD;
    int bestCompliance = 0;
    
    FORN(i,P) {
      string RFP;
      getline(cin,RFP);
      double price;
      int complied;

      scanf("%lf %d\n",&price,&complied);
      FORN(j,complied)
        getline(cin,name);

      if(complied > bestCompliance) {
        bestRFP = RFP;
        bestPrice = price;
        bestCompliance = complied;
      }
      else if(complied == bestCompliance) {
        if(price < bestPrice) {
          bestRFP = RFP;
          bestPrice = price;
          bestCompliance = complied;
        }
      }
    }
    if(caseNo != 1)
      cout << endl;
    printf("RFP #%d\n",caseNo++);
    cout << bestRFP << endl;

  }
  
  return 0;
}
