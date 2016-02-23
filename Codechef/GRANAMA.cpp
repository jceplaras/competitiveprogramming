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
  int num = 'z'-'a'+1;
  int M[2][num];
  char str[1001];
  
  int N;
  
  scanf("%d",&N);
  
  while(N--) {
    bool isGuessedGranamana = true, isGranamana = true;
    FORN(i,num)
      M[0][i] = M[1][i] = 0;
      
    scanf("%s",str);
    FORN(i,strlen(str))
      M[0][str[i]-'a']++;
    scanf("%s",str);
    FORN(i,strlen(str))
      M[1][str[i]-'a']++;
    
    FORN(i,num) {
      if((M[0][i] > 0 && M[1][i] == 0) || (M[1][i] > 0 && M[0][i] == 0))
        isGuessedGranamana = false;
      if(M[0][i] != M[1][i])
        isGranamana = false;  
    }
    if(isGuessedGranamana == isGranamana)
      printf("YES\n");
    else
      printf("NO\n");
    
    
  }
  
  return 0;
}
