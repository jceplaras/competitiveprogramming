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

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int p(int i) {
	int a = 1;
	int b = 1;
	int c = 2;
	
	if(i == 0 || i == 1) return 1;
	
	else {
		i-=2;
		while(i--) {
			a =b;
			b = c;
			c = (a%MOD + b%MOD)%MOD;
		}
		
		return c;
	}
}

int c(int i) {
	int sum = 0;
	while(i!=0) {
	//	printf("%d",i%2);
		sum+=i%2;
		i/=2;
	}
	//printf("\n");
	return sum;
}
int A[1000001];
int main() {
 	int T;
 	int N,G;
 	A[0] = A[1] = 1;
 	for(int i=2;i<1000001;i++) {
		A[i] = (A[i-1]+A[i-2])%MOD;
	}
 	
 	scanf("%d",&T);
 	while(T--) {
 		scanf("%d %d",&N,&G);
 		
 		if(c(A[N]) == G) printf("CORRECT\n");
 		else printf("INCORRECT\n");
 	}
 	
 	return 0;
}
