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

#define swap(a,b) temp = a; a = b; b = temp
bool isSimilar(char a[], char b[], int N) {
  
  FORN(i1,N) {
    FOR(j1,i1,N-1) {
      FORN(i2,N) {
        FOR(j2,i2,N-1) {
          swap(a[i1],a[j1]);
          swap(b[i2],b[j2]);
          if(strcmp(a,b) == 0) {
            swap(a[i1],a[j1]);
            swap(b[i2],b[j2]);
            return true;
          }
          swap(a[i1],a[j1]);
          swap(b[i2],b[j2]);
        }
      }
    }
  }
  return false;
}

int main() {
  char str[] = "abcde"; 
  char str2[] = "abcde";
  int count = 0;
  //do {
    do {
      if(!isSimilar(str,str2,strlen(str))) {
        count++;
        printf("%s\n",str2);
      }
    }while(next_permutation(str2,str2+strlen(str)));
  //}while(next_permutation(str,str+strlen(str)));
  printf("count: %d\n",count);
  
  return 0;
}
