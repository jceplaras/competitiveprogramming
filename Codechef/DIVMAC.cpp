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
#define MAXN 200005
int sieve[1000001];

void computeSieve(int N) {
  FORN(i,N)
    sieve[i] = i;
  sieve[0] = 1;
  sieve[1] = 1;
  FOR(i,2,sqrt(N)) {
    if(sieve[i] == i) {
      for(int j = i*i; j < N; j += i) {
        if(sieve[j] == j)
          sieve[j] = i;
      }
    }
  }
}
int tree[MAXN];
template<class T,class V>
class SegmentTree {

private:
  //tree rooted at index 1
  int size;
  int treeSize;


  V merge(T leftVal, T rightVal) {
    if(sieve[leftVal] > sieve[rightVal])
      return leftVal;
    else
      return rightVal;
  }
  void build(T orig[],int t,int l, int h) {
    if(l == h) {
      tree[t] = orig[l];
      return;
    }
    int left = 2*t;
    int right = 2*t + 1;
    int mid = (l+h)/2;

    build(orig,left,l,mid);
    build(orig,right,mid+1,h);

    tree[t] = merge(tree[left],tree[right]);
  }
  V query(int t,int left, int right, int l, int h) {
    int mid = (left+right)/2;

    //if exact to interval [l,h]
    if(left == l && right == h) 
      return tree[t];
    //if interval [l,h] right side of tree
    else if(l > mid) {
      return query(2*t + 1, mid+1, right, l,h); 
    }
    //if interval [l,h] left side of tree
    else if(h <= mid) {
      return query(2*t, left, mid, l, h);
    }
    //if interval is spans the middle of the tree
    else {
      T leftVal = query(2*t,left,mid,l,mid);
      T rightVal = query(2*t + 1,mid+1,right,mid+1,h);
      return merge(leftVal,rightVal); 
    }
  }
  
  void update(int t, int l, int h, int origIndex, T value) {
    if(l == h) {
      tree[t] /= sieve[tree[t]];
      return;
    }
    int left = 2*t;
    int right = 2*t + 1;
    int mid = (l+h)/2;

    if(origIndex <= mid) 
      update(left,l,mid,origIndex,value);
    else
      update(right,mid+1,h,origIndex,value);

    tree[t] = merge(tree[left],tree[right]);
  }

  void updateRange(int t, int l, int h, int s, int e, T value) {
    if(l == h) {
      tree[t] /= sieve[tree[t]];
      return;
    }
    if(tree[t] == 1)
      return;

    int left = 2*t;
    int right = 2*t + 1;
    int mid = (l+h)/2;

    if(e <= mid)
      updateRange(left, l, mid, s, e, value);
    else if(s > mid)
      updateRange(right, mid+1, h, s, e, value);
    else {
      updateRange(left, l, mid, s, mid, value);
      updateRange(right, mid+1, h, mid+1, e, value); 
    }
    
    tree[t] = merge(tree[left],tree[right]);
  }
  
public:
  SegmentTree(T orig[],int size) {
    this->size = size;
    this->treeSize = getSegmentTreeSize(size);
    build(orig,1,0,size-1);
  }

  int getSegmentTreeSize(int N) {
    int size;
    for(size = 1;size < N; size <<= 1);
    return size << 1;
  }

  V get(int a) {
    return tree[a];
  }

  V query(int low, int high) {
    return query(1, 0, size-1, low, high); 
  }

  void update(int origIndex, T value) {
    update(1, 0, size-1, origIndex, value);
  }

  void updateRange(int l, int r, T value) {
    updateRange(1, 0, size-1, l, r, value);
  }

};


int A[100001];

int main() {

  computeSieve(1000001);

  int T;
  scanf("%d",&T);

  while(T--) {
    int N, M;
    scanf("%d %d",&N,&M);

    FORN(i,N) {
      scanf("%d",&A[i]); 
    }
    SegmentTree<int,int> st(A,N);

    FORN(i,M) {
      int T,L,R;
      scanf("%d %d %d",&T,&L,&R);

      if(T == 0)
        st.updateRange(L-1,R-1,-1);
      else {
        int val = st.query(L-1,R-1);
        printf("%d ",sieve[val]);
      }
    }
    printf("\n");


  }
  return 0;
}
