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
  bool answer[256];
  bool attempts[256];
  char temp[100000];

  while(true) {
    int T;

    FORN(i,256)
      answer[i] = attempts[i] = false;
    scanf("%d",&T);

    if(T == -1) 
      break;

    int charCount = 0;
    scanf("%s",temp);
    FORN(i,strlen(temp)) {
      if(!answer[temp[i]]) {
        answer[temp[i]] = true;
        charCount++;  
      }
    }
   
    scanf("%s",temp);
    int attCount = 0;
    FORN(i,strlen(temp)) {
      if(!attempts[temp[i]]) {
        attempts[temp[i]] = true;
        if(answer[temp[i]]) {
          answer[temp[i]] = false;
          charCount--;
        }
        else {
          attCount++;
        }
      }

      if(charCount == 0) break;
      if(attCount == 7) break;
    }
    printf("Round %d\n",T);
    if(charCount == 0) printf("You win.\n");
    else if(attCount == 7) printf("You lose.\n");
    else printf("You chickened out.\n");
      
  }
  
  return 0;
}
