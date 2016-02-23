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
  int A[256];
  char t[201];
  int N;
  int sum;
  scanf("%d",&N);
  while(N--) {
  	FORN(i,256)
  		A[i] = 0;
  	sum = 0;
  	scanf("%s",t);
  	
  	FORN(i,strlen(t))
  		A[t[i]]++;
  	
  	FORN(i,256) {
  		A[i] = A[i]/2 + A[i]%2;
  		sum += A[i];
  	}
  	
  	
  	printf("%d\n",sum);
  }
  
  
  return 0;
}
