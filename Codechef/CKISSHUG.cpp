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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int m = 2;
int p2 = 2;

long modpow(int exponent) {
    long result = 1;
    ll base = 2;
    while(exponent>0) {
        if (exponent%2==1)
           result=(result*base)%MOD;
        exponent = exponent >> 1;
        base = (base * base)%MOD;
       // printf("-%lld\n",base);
        }
    //printf("=%ld\n",result);
    return result;
}

int main() {
  int T;
  int N;
  long m;
  long temp;
  int sub;
  long sum;
  scanf("%d",&T);
  while(T--){
    m = 2;
    scanf("%d",&N);
    sub = N - 1;
    sub = sub/2;
    //printf("%d\n",sub);
    temp=modpow(sub+1);
    //printf("%ld\n",temp);
    sum = (temp-2)%MOD;
    //printf("%ld\n",sum);
    sum = (sum*2)%MOD;
    
    if(N%2==0)
      sum = (sum+temp)%MOD;
      
    m = (m+sum)%MOD;
    printf("%ld\n",m);
  }  
  
  return 0;
}
