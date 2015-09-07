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
    int i,j,k;
    scanf("%d %d %d",&i,&j,&k);

    if((i+j)==k)
        printf("%d+%d=%d\n",i,j,k);
    else if((i-j)==k)
        printf("%d-%d=%d\n",i,j,k);
    else if((i*j)==k)
        printf("%d*%d=%d\n",i,j,k);
    else if((i/j)==k)
        printf("%d/%d=%d\n",i,j,k);
    else if(i==(j+k))
        printf("%d=%d+%d\n",i,j,k);
    else if(i==(j-k))
        printf("%d=%d-%d\n",i,j,k);
    else if(i==(j*k))
        printf("%d=%d*%d\n",i,j,k);
    else if(i==(j/k))
        printf("%d=%d/%d\n",i,j,k);
    return 0;
}
