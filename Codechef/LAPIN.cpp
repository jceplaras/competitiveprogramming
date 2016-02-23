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
	int ftable[256];
	char str[1001];
	int T;
	bool isLapin;
	scanf("%d",&T);
	
	while(T--) {
		FORN(i,256)
			ftable[i] = 0;
			
		isLapin = true;
		scanf("%s",str);
			
		for(int i=0,j=strlen(str)-1;i<=j;i++,j--) {
			ftable[str[i]]++;
			ftable[str[j]]--;
		}	
			
		FORN(i,256)
			if(ftable[i] != 0)
				{
					isLapin = false;
					break;
				}
				
		if(isLapin)
			printf("YES\n");
		else
			printf("NO\n");	
	}  
  
  return 0;
}
