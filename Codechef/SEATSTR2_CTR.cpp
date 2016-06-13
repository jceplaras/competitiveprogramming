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
char temp;

#define swap(a,b) temp = a; a=b; b = temp
int main() {
  int N = 5;
  int count = 0;
  char str[]="-abcde";
  FOR(i,2,N) {
    FOR(ii,1,i-1) {
      FOR(j,i+1,N) {
        FOR(jj,1,j-1) {
          FOR(k,j+1,N) {
            FOR(kk,1,k-1) {
              printf("(%d,%d) - (%d,%d) - (%d,%d)\n",ii,i,jj,j,kk,k);
              swap(str[ii],str[i]);
              swap(str[jj],str[j]);
              swap(str[kk],str[k]);
              printf("%s\n",&str[1]);
              swap(str[kk],str[k]);
              swap(str[jj],str[j]);
              swap(str[ii],str[i]);
              count++; 
            }
          }
        }
      }
    }
  }
  printf("%d\n",count);
  
  return 0;
}
