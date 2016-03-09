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
  vector<ull> store;
  ull x;

  while(cin >> x) {
    store.push_back(x);

    if(store.size()%2 == 0) {
      x = 0;
      nth_element(store.begin(),store.begin()+store.size()/2,store.end());
      x += store[store.size()/2];
      nth_element(store.begin(),store.begin()+store.size()/2-1,store.end());
      x += store[store.size()/2 - 1];
      x /= 2;
      cout << x << endl;
    }
    else {
      nth_element(store.begin(),store.begin()+store.size()/2,store.end());
      cout << store[store.size()/2] << endl;
    }
  } 

  
  return 0;
}
