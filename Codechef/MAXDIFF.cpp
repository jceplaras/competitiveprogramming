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

#define M 100001
int main() {
  int a[M];
  int T;
  int N, K, t;
  int x;
  int m=0,n=0;
  scanf("%d",&T);
  while(T--) {
  	m =0; n=0;
  	FORN(i,M)
  		a[i] = 0;
  	
  	scanf("%d %d",&N,&K);
  	
  	FORN(i,N) {
  		scanf("%d", &t);
  		a[t]++;
  	}
  	
  	K = min(K,N-K);
  	for(x=0;x<M && K != 0;) {
  		if(a[x]!=0) {
  			K--;
  			m += x;
  			a[x]--;
  		}
  		else x++; 
  	}
  	
  	for(;x<M;x++) {
  		n+= a[x] * x;
  	}
  	/*printf("-----");
  	printf("%d\n",n);
  	printf("%d\n",m);*/
  	printf("%d\n",n-m);
  }
  
  
  return 0;
}
