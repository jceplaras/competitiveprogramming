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
  char a[256];
  char s[200];
  
	int t;
	int i,j,x = 0;
	scanf("%d",&t);
	scanf("%s",s);
	
		for(i=0;i<256;i++)
			a[i] = i;
		for(i=65,j=97,x=0;i<91;i++,j++,x++) {
			a[i] = s[x]-32;
			a[j] = s[x];
		}
		a[95] = ' ';
		
		
	while(t--) {
	
	scanf("%s",s);
	FORN(i,strlen(s))
		s[i] = a[s[i]];
	printf("%s\n",s);
	}
  
  return 0;
}
