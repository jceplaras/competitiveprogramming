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

struct Suit {
  bool hasKing;
  bool hasAce;
  bool hasQueen;
  bool hasJack;
  bool isStopped;
  int other;
};


int getSuitNum(char S) {
  switch(S) {
    case 'S': return 0;
    case 'H': return 1;
    case 'D': return 2;
    case 'C': return 3;
  }
  return 0;
}

char getNumSuit(int S) {
  switch(S) {
    case 0: return 'S';
    case 1: return 'H';
    case 2: return 'D';
    case 3: return 'C';
  }
  return 0;
}

int main() {
  Suit S[4];
  int score[3];
  char card[10];
  int counter = 0;
  

  FORN(i,3)
    score[i] = 0;
  FORN(i,4) {
    S[i].other = 0;
    S[i].hasKing = S[i].hasQueen = S[i].hasJack = S[i].hasAce = S[i].isStopped = false;
  }
  while(scanf("%s",card)!=-1) {
    counter++;

    int currentSuit = getSuitNum(card[1]);
    S[currentSuit].other++; 
    if(card[0] == 'A') {
      S[currentSuit].hasAce = true;
      score[1] += 4;
    }
    if(card[0] == 'K') {
      S[currentSuit].hasKing = true;
      score[1] += 3;
    }
    if(card[0] == 'Q') {
      S[currentSuit].hasQueen = true;
      score[1] += 2;
    }
    if(card[0] == 'J') {
      S[currentSuit].hasJack = true;
      score[1]++;
    }


    if(counter == 13) {
      counter = 0;

      int maxSuit = 0;
      int maxSuitSym = 0;
      FORN(i,4) {
        if(S[i].hasKing && S[i].other <= 1)
          score[1]--;
        if(S[i].hasKing && S[i].other > 1) {
          S[i].isStopped = true;
        }
        if(S[i].hasQueen && S[i].other <= 2)
          score[1]--;
        if(S[i].hasQueen && S[i].other > 2) {
          S[i].isStopped = true;
        }
        if(S[i].hasJack && S[i].other <= 3)
          score[1]--;
        if(S[i].hasAce)
        {
          S[i].isStopped = true;
        }

        if(S[i].other == 2)
          score[2]++;
        if(S[i].other == 1)
          score[2]+=2;
        if(S[i].other == 0)
          score[2]+=2;

        if(S[i].other > maxSuit) {
          maxSuit = S[i].other;
          maxSuitSym = i;
        }
      }
      score[0] = score[1]+score[2];
      
      if(score[0] < 14)
        printf("PASS\n");
      else if(score[1] >= 16 && S[0].isStopped && S[1].isStopped && S[2].isStopped && S[3].isStopped) 
        printf("BID NO-TRUMP\n");
      
      else 
        printf("BID %c\n",getNumSuit(maxSuitSym));
        



      FORN(i,4) {
        S[i].other = 0;
        S[i].hasKing = S[i].hasQueen = S[i].hasJack = S[i].hasAce = S[i].isStopped = false;
      }
      FORN(i,3)
        score[i] = 0;
    }
    
  }
  
  
  return 0;
}
