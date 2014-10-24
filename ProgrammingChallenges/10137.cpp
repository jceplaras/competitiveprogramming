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
  int num[1001];
  int N;
  int sum; 
  double temp;
  int avg;
  int neg, pos;
  int intTemp;

  while(true) {
    scanf("%d",&N);
    if(N == 0) break;

    sum = pos = neg = 0;

    FORN(i,N) {
      scanf("%lf", &temp);

      num[i] = temp*1000;
      sum += num[i];
    }
    int mod = sum%N;
    printf("m=%d\n",mod);
    avg = sum/N;
    if(avg%10 > 5)
      avg = (avg/10 + 1)*10;
    else
      avg = (avg/10)*10;
    printf("%d %f\n",avg,sum/(float)N);
    FORN(i,N) {
      intTemp = num[i] - avg;
      if(intTemp > 0)
        pos += intTemp;
      else
        neg += intTemp;
    } 

    printf("%f %f\n",pos/1000.0f,neg/1000.0f);
  }
  
  return 0;
}
