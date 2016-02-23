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

char str[1001];
char temp[1001];
int T;
int N;

int count(char * str,int N) {
  int count = 0;
  FOR(i,1,N)
    if(str[i] == '1') count++;
    else if(str[i-1] == '1' || str[i+1] == '1') count++;
    
    return count;
}
int main() {
  
  scanf("%d",&T);
  
  while(T--) {
    scanf("%d",&N);
    
    scanf("%s",temp);
    
    sprintf(str,"%d%s%d",0,temp,0);
    
    printf("%d\n",N-count(str,N));
  }
  
  
  return 0;
}