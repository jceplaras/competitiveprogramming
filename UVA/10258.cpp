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

int penalty[101][11];
int accept[101][11];

bool comp(int i, int j) {
  if(accept[i][0] == accept[j][0]) {
    if(accept[i][10] == accept[j][10]) {
      return (i < j); 
    }
    else return (accept[i][10] < accept[j][10]); 
  }
  else return (accept[i][0] > accept[j][0]);
}

int main() {

  int T;
  char line[100];
  scanf("%d",&T);
  int t = 0;
  gets(line);
  gets(line);
  vi values;
  while(T--) {

    FORN(i,101)
    {
      fill_n(penalty[i],11,0);
      fill_n(accept[i],11,0);
    }

    while(gets(line) && strlen(line)) {
    int contestant;
    int problem;
    int time;
    char L;
    sscanf(line,"%d %d %d %c",&contestant,&problem,&time,&L);
    //printf("%d %d %d %c\n",contestant,problem,time,L);
    
    if(find(values.begin(),values.end(),contestant) == values.end())
      values.push_back(contestant);

    if(L == 'C') {
      if(accept[contestant][problem]==0) {
      accept[contestant][problem] = penalty[contestant][problem] + time;
      accept[contestant][0]++;
      accept[contestant][10] += accept[contestant][problem];
      }
    }
    else if(L == 'I')
      if(accept[contestant][problem]==0)
        penalty[contestant][problem] += 20;

    }

    sort(values.begin(),values.end(),comp);

    FORN(i,values.size()) {
      int cont = values[i];
      printf("%d %d %d\n",cont,accept[cont][0],accept[cont][10]);
    }
    if(T) printf("\n");
    values.clear();


  }
  return 0;
}
