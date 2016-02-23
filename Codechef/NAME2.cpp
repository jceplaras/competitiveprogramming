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
  int N;
  char name1[25002];
  char name2[25002];
  char temp[25002];
  scanf("%d",&N);
  int i = 0;
	int j = 0;
	int iLen,jLen;
  while(N--) {
  	scanf("%s",name1);
  	scanf("%s",name2);
  	i=j=0;
  	if(strlen(name2)<strlen(name1)) {
  		strcpy(temp,name1);
  		strcpy(name1,name2);
  		strcpy(name2,temp);
  	}
  	iLen = strlen(name1);
  	jLen = strlen(name2);
	while(i<iLen && j<jLen) {
		while(name1[i]!=name2[j] && j<jLen) {
		j++;
		}
		if(name1[i] == name2[j]) { i++; j++; }
		
	}
	if(i == iLen) printf("YES\n");
	else printf("NO\n");
  	
  }
  
  return 0;
}
