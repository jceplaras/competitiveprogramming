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
typedef pair<string,int> psi;
typedef vector<pii> vpii;

map<string,psi> walk;
map<string,int> data;
char A[51];
char B[51];

char START[51];
int money;

int total;
int main() {
  int T;
  int N;
  
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&N);
    total = 0;
    walk.clear();
    data.clear();
    FORN(i,N-1) {
      scanf("%s %s %d$",A,B,&money);
      
      data[A]+=1;
      data[B]-=1;
  
      
      walk[A].first=B;
      walk[A].second=money;
    }
    
    for (map<string,int>::iterator it=data.begin() ; it != data.end(); it++ )
        if((*it).second == 1)  {strcpy(START,(*it).first.c_str()); break; }
    
    strcpy(A,START);
    FORN(i,N-1) {
      strcpy(B,walk[A].first.c_str());
      total+=walk[A].second;
      printf("%s %s %d$\n",A,B,walk[A].second);
      strcpy(A,B);
    }
    printf("%d$\n",total);
  }
    
  
  return 0;
}
