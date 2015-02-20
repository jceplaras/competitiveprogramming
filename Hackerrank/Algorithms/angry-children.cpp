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

#define INT_MAX 1000000000;

int main() {
  int store[100001];

  int N;
  int K;

  scanf("%d",&N);
  scanf("%d",&K);

  FORN(i,N)
    scanf("%d",&store[i]);

  int min = INT_MAX;
  sort(store,store+N);


  for(int i=0;i<=N-K;i++) {
    int temp = store[i+K-1] - store[i];
    if(temp < min)
      min = temp;
  }

  printf("%d\n",min);


  return 0;
}
