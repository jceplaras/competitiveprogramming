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

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

bool isPrime (int x)
{
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  int s=(int)(sqrt((x)));
  for(int i=5;i<=s;i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}
#define N 10000
int main() {
  int a[N+1];
  int ways, p ,q ;
  int T,X;
  int n = 2*N+1;
  bool prime[n];
	for(int i=2;i<n;i++)
		prime[i] = true;
	prime[0]=false;
	prime[1]=false;
	int m=(int)sqrt(n );
	for (int i=2; i<=m; i++)
		if (prime[i])
			for (int k=i*i; k<=n; k+=i)
				prime[k]=false;

 for(int i=0;i<N+1;i++) {
 		ways = 0;
 		for(q=0;2*q<=i;q++) {
 			p = i - 2*q;
 			if(prime[p]&&prime[q]) {
 				ways++;
 				}
 		}
 		a[i] = ways;
  }
 	
 	
 	scanf("%d",&T);
 	
 	while(T--) {	
 		scanf("%d",&X);
 		
 		printf("%d\n",a[X]);
 	}
  
  return 0;
}
