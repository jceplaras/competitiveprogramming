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


char temp[1000001];
int main() {
  int t,k;
  
  scanf("%d",&t);
  char x;
  int n = 103993;
  int d = 33102;
  n= (n%d)*10;
  for(int i=0;i<1000001;i++) {
  	temp[i] = n/d + 48;
  	n= (n%d)*10;
  }
  temp[1000000] = 0;
  while(t--) {
  	scanf("%d",&k);
  	if(k > 0) {
  		x = temp[k];
  		temp[k] = 0;
  		printf("3.%s\n",temp);
  		temp[k] = x;
  	}
  	else printf("3\n");
  	
  	
  }
  
  return 0;
}
