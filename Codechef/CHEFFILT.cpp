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

#define MOD 1000000007
#define L 10 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
  ull DP[1024][1024];
  ull store[1024];

ull mod_pow(ull b, ull e) {

  ull res = 1;
  b = b%MOD;
  while(e>0) {
    if(e%2 == 1) {
      res = (res%MOD * b%MOD)%MOD;
    } 
    e/=2;
    b = (b%MOD * b%MOD)%MOD;
  }
  return res;
}

int main() {
  int T,N;
  char temp[11];


  scanf("%d",&T);

  while(T--) {
    int target = 0;
    scanf("%s",temp);

    FORN(i,L)
      if(temp[i] == 'w')
        target = target + (1 << i);


    scanf("%d",&N);

    FORN(i,1024) {
      FORN(j,1024) {
        DP[i][j] = 0;
      }
      store[i] = 0;
    }

    FORN(x,N) {
      scanf("%s",temp);
      int val = 0; 
      FORN(i,L)
        if(temp[i] == '+')
          val = val + ( 1 << i);

      store[val]++;

    }
    DP[0][0] = mod_pow(2,store[0]);
    //printf("---%llu\n",DP[0][0]);
    for(int i=1;i<=1023;i++) {
      for(int j=0;j<=1023;j++) {
        //DP[i][j] = (DP[i-1][j]%MOD + DP[i-1][j ^ store[i]]%MOD)%MOD;
        if(store[i] == 0) {
          DP[i][j] = DP[i-1][j]%MOD; 
        }
        else {
          ull additional = mod_pow(2,store[i]-1);

          ull temp = 0;
          if(j == 0) temp = (((DP[i-1][0]%MOD * (additional-1)%MOD)%MOD) + DP[i-1][0])%MOD;
          //temp = (temp%MOD +  ((additional-1)%MOD * DP[i-1][j]%MOD)%MOD + ((additional%MOD * DP[i-1][j ^ i]%MOD)%MOD))%MOD)%MOD; 
          else temp = (temp%MOD + ((additional)%MOD * DP[i-1][j]%MOD)%MOD)%MOD;
          temp = (temp%MOD + (additional%MOD * DP[i-1][j ^ i]%MOD)%MOD)%MOD;
          DP[i][j] = temp;
        }
      }
    }

    /*FORN(i,16) {
      FORN(j,16) {
        printf("%3d ",DP[i][j]); 
      }
      printf("\n");
    }*/

    printf("%llu\n",DP[1023][target]);
  

  }
  
  return 0;
}
