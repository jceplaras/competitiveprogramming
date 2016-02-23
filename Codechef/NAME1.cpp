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

bool isSubsequence(char * a, char * b) {
	
}

int main() {
  int T,N;
  int count[256];
  char temp[40001];
  scanf("%d",&T);
  int k;
  while(T--) {
  	FORN(i,256) count[i] = 0;
  	scanf("%s",temp);
  	FORN(i,strlen(temp)) count[temp[i]]++;
  	scanf("%s",temp);
  	FORN(i,strlen(temp)) count[temp[i]]++;
  	
  	scanf("%d",&N);
  	FORN(n,N) {
  		scanf("%s",temp);
  	FORN(i,strlen(temp)) count[temp[i]]--;
  	}
  	
  	for(k=0;k<256;k++)
  		if(count[k] < 0) break;
  		
  	if(k==256) printf("YES\n");
  	else printf("NO\n");
  	
  }
  
  return 0;
}
