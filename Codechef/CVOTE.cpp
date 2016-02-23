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
#define FOREACH(it,a) for ( it=a.begin() ; it != a.end(); it++ )
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main() {
  map<string,string> chefToCountry;
  map<string,int> chefVote;
  map<string,int> countryVote;
  
  int N, M;
  char s[20];
  char t[20];
  scanf("%d %d",&N,&M);
  while(N--) {
    scanf("%s %s",s,t);
    
    chefToCountry[(string)s] = (string)t;
  }
  
  while(M--) {
    scanf("%s",s);
    
    chefVote[(string)s]++;
    countryVote[chefToCountry[(string)s]]++;
  }
  //printf("TEST");
  int maxChef = 0;
  int maxCountry = 0;
  string maxChefStr = "";
  string maxCountryStr = "";
  
  map<string,int>::iterator it;
  FOREACH(it,chefVote)
    if((*it).second > maxChef) {
     maxChef = (*it).second;
     maxChefStr = (*it).first; 
    }
  FOREACH(it,countryVote)
    if((*it).second > maxCountry) {
     maxCountry = (*it).second;
     maxCountryStr = (*it).first; 
    }  
  printf("%s\n%s\n",maxCountryStr.c_str(),maxChefStr.c_str());
  return 0;
}
