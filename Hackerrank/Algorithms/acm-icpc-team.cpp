#include <algorithm>
#include <bitset>
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

  int N,M;
  scanf("%d %d",&N,&M);

  string bitstring[500];
  FORN(i,N){
    cin >> bitstring[i];
  }
  int MAX_GROUP = -1;
  int MAX_TOPIC = -1;
  FORN(i,N) {
    bitset<500> a(bitstring[i]);
    FOR(j,i+1,N-1) {
      bitset<500> b(bitstring[j]);
      int topic = (b|=a).count();
      if(topic > MAX_TOPIC) {
        MAX_TOPIC = topic;
        MAX_GROUP = 1;
      }
      else if(topic == MAX_TOPIC) {
        MAX_GROUP++;
      }
    }
  }

  printf("%d\n",MAX_TOPIC);
  printf("%d\n",MAX_GROUP);

  return 0;
}
