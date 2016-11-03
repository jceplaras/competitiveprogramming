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
#define PI 3.14159265358979323846


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

double f(int n) {
  return 1 - cos((2*PI)/n);
}

int main() {
  int T;
  scanf("%d",&T);

  while(T--) {
    double s, v;

    scanf("%lf %lf",&s,&v);

    printf("%lf\n",s/((1.5)*v)); 
  }
    
  
  return 0;
}
