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
int N,M;

map<vi,int> temp;
char str[105][101];
pair<vi,int> pp;

void printVI(vi v) {
  printf("<");
  FORN(i,v.size()) {
    printf("%d ",v[i]);
  }
  printf(">");
}

bool allEqual(vi index) {
  char x = str[0][index[0]];

  for(int i=1;i<N;i++) 
    if(x!= str[i][index[i]]) return false;
  return true;
}

bool hasNegative(vi index) {
  FORN(i,N) {
    if(index[i] < 0) return true;
  }

  return false;
}

int lcs(vi index,int t) {
  if(hasNegative(index)) {
    return 0;
  }
  else if(temp.find(index) != temp.end()) {
    /*FORN(i,t)
      printf("\t");
    printVI(index);
    printf("---");
    printVI((temp.find(index))->first);
    printf("==> %d",(temp.find(index))->second);
    printf("is exist in memo\n");*/
    return temp.at(index);
  }
  else if(allEqual(index)) {
    /*FORN(i,t)
      printf("\t");
    printVI(index);
    printf("all equal\n");*/
    pp.first = index;

    FORN(i,N)
      index[i] = index[i] - 1;
    pp.second = lcs(index,t+1)+1;
    temp.insert(pp);
    return pp.second;
  }
  else {
    /*FORN(i,t)
      printf("\t");
    printVI(index);
    printf("otherwise\n");*/
    int mM = 0;
    int tM;
    FORN(i,N) {
      index[i] = index[i] - 1;
      pp.first=index;
      mM = max(mM,tM = lcs(index,t+1));
      pp.second=tM;
      temp.insert(pp);
      index[i] = index[i] + 1;
    }
    pp.first=index;
    pp.second=mM;
    temp.insert(pp);
    return mM;
  }
}
int main() {
  int T;
  scanf("%d",&T);

  while(T--) {
    scanf("%d",&N);
    FORN(i,N) {
      scanf("%s",str[i]);
    }
    M=strlen(str[0]);
    FORN(i,M) {
      str[N][i] = 'a';
    }
    N=N+1;
    vi index(N,M-1);
    int len1 = lcs(index,0);
    //printf("aaaa: %d\n",len);
    temp.clear();
    N=N-1;
    FORN(i,M) {
      str[N][i] = 'b';
    }
    N=N+1;
    index.assign(N,M-1);
    int len2 = lcs(index,0);

    //printf("bbbb: %d\n",len);
    printf("%d\n",min(len1,len2));
    temp.clear();
  }

  return 0;
}
