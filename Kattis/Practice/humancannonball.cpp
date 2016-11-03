#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define DBLMAX std::numeric_limits<double>::max()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

double getTime(double x1, double y1, double x2, double y2, int source) {
    double dx = x2-x1;
    double dy = y2-y1;
    double distance = sqrt(dx*dx + dy*dy);
    double minTime = distance/5;

    if(source != 0 && source != 1) {
       double cannonTime = 2 + (abs(distance-50))/5;
       minTime = min(minTime,cannonTime);
    }
    return minTime;

}

int main() {
  double X[102];
  double Y[102];

  int N;
  int c=0;
  scanf("%lf %lf",&X[c],&Y[c]);
  c++;
  scanf("%lf %lf",&X[c],&Y[c]);
  c++;
  scanf("%d",&N);

  while(c < N+2) {
    scanf("%lf %lf",&X[c],&Y[c]);
    c++;
  }
/*
  FORN(i,N+2)
      printf("t:%lf %lf\n",X[i],Y[i]);
*/
  double graph[102][102];

  //get time needed from one point to another
  FORN(i,N+2)
    FORN(j,i) {
        graph[i][j] = getTime(X[i],Y[i],X[j],Y[j],i);    
        graph[j][i] = getTime(X[i],Y[i],X[j],Y[j],j); 
    }
/*
  FORN(i,N+2) {
      FORN(j,N+2)
        printf("%lf ",graph[i][j]);
      printf("\n");
  }
  printf("\n\n");
*/

  //do floyd warshall
  FORN(k,N+2)
      FORN(i,N+2)
        FORN(j,N+2)
            if(graph[i][j] > graph[i][k] + graph[k][j])
                graph[i][j] = graph[i][k] + graph[k][j];
  /*FORN(i,N+2) {
      FORN(j,N+2)
        printf("%lf ",graph[i][j]);
      printf("\n");
  }*/

  printf("%lf\n",graph[0][1]);
  return 0;
}
