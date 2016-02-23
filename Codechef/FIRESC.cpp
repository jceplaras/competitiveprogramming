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
#define FOREACH(type,it,v) for(type::iterator it = v.begin();it!=v.end();it++)
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main() {
  int T;
  scanf("%d",&T);
	ull answer;
  int N,M;
  int v[100002];
  int f[100002]; 
  vi graph[100002];
  int a,b;			
  while(T--) {
  	answer = 1;
  	scanf("%d%d",&N,&M);
  
  	FORN(i,100002) {
  		v[i] = f[i] = 0;
  		graph[i].clear();
  	}
  
  	FORN(i,M) {
  		scanf("%d%d",&a,&b);
  		
  		graph[a].push_back(b);
  		graph[b].push_back(a);
  	}
  	
  	/*
  	FOR(i,1,N) {
  		printf("%d: ",i);
  		FOREACH(vi,it,graph[i]){
  			printf("%d ",*it);
  		}
  		printf("\n");
  	}*/
  	
  	int tag = 0;
  	FOR(i,1,N) {
  		if(v[i] == 0) {
  			tag++;
  			queue<int> Q;
  			Q.push(i);
  			v[i] = tag;
  			f[tag]++;
  			while(!Q.empty()) {
  				int t = Q.front();
  				Q.pop();
  				
  				FOREACH(vi,it,graph[t]){
  					int u = *it;
  					if(v[u] == 0) {
  						v[u] = tag;
  						f[tag]++;
  						Q.push(u);
  					}
  				}
  			}
  		}
  	}
  	/*
  	FOR(i,1,N) {
  		printf("%d ",v[i]);
  	}
  	printf("\n");
  	FOR(i,1,tag) {
  		printf("%d ",f[i]);
  	}
  	printf("\n");
  	*/
  	FOR(i,1,tag) {
  		answer = (answer * f[i])%MOD;
  	}
  	
  	printf("%d %llu\n",tag,answer);
  } 
  return 0;
}
