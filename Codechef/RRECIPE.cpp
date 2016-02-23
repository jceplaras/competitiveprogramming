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

#define MOD 10000009
int main() {
  char s[1000000];
  int len = 0;
  int count;
  bool notPal = false;
  int T;
  scanf("%d",&T);
  while(T--) {
  notPal = false;
   count = 1;
    scanf("%s",s);
    len = strlen(s);
    
    for(int i=0,j=len-1;i<=j;i++,j--) {
     // printf("%d %d\n",i,j);
      if(s[i] == '?') {
        if(s[j] == '?') {
            count=(count*26)%MOD;
        }
       
      }
      else if(s[j] == '?') {
        if(s[i] == '?') {
            count=(count*26)%MOD;
        }
        
      }
      else if(s[i] != s[j]){
        
        notPal = true; break;
      } 
    }
    
    
    if(notPal)
      printf("0\n");
    else printf("%d\n",count);
  }
   
  return 0;
}
