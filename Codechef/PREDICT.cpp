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
  double Pa, Pb;
  double Pmax;
	double Ans;  
  int T;
  
  scanf("%d",&T);
  while(T--) {
  	scanf("%lf",&Pa);
  	Pb = 1 - Pa;
  	
  	Pmax = max(Pa,Pb);
  	
  	Ans = (2 * ( 1 - Pmax) * 10000 + 10000) * Pmax;
  	
  	
		printf("%lf\n",Ans);
  }
  
  
  return 0;
}
