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

ull countSig(char X[]) {
  int len = strlen(X);

  ull count = 0;
  bool c = false;

  FORD(i,len-1,0) {
    if(X[i] == '0' && !c) {
      c = true;
      count++;
    }
    else if(X[i] == '1' && c) {
      count++;
    }
  }

  return count;
}

ull countOne(char X[]) {
  ull count = 0; 

  int len = strlen(X);
  FORN(i,len) {
    if(X[i] == '1') count++;
  }

  return count;
}
int main() {

  int T;
  scanf("%d",&T);

  char L1[1001];
  char L2[1001];
  char L3[1001];
  int N;

  while(T--) {
    ull x = 0;

    scanf("%s %s %s %d",L1,L2,L3,&N);

    ull count3 = countSig(L3);

    if(count3 != 0) {
      printf("%llu\n",countOne(L1)+(countOne(L2)*N)+count3);
    }
    else {
      ull count2 = countSig(L2);
      if(count2 != 0) 
        printf("%llu\n",countOne(L1)+(countOne(L2)*(N-1))+count2);
      else {
        ull count1 = countSig(L1);

        if(count1 != 0) 
          printf("%llu\n",count1);
        else
          printf("1\n");
      }
    }
  }
  
  return 0;
}
