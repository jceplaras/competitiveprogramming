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

#define MAXN 100

T tree[MAXN];
template<class T,class V>
class SegmentTree {

  private:
  int size;
  int treeSize;


  V merge(T leftVal, T rightVal) {
    //TODO
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

    if(left == l && right == h) 
      return tree[t];
    else if(l > mid) {
      return query(2*t + 1, mid+1, right, l,h); 
    }
    else if(h <= mid) {
      return query(2*t, left, mid, l, h);
    }
    else {
      T leftVal = query(2*t,left,mid,l,mid);
      T rightVal = query(2*t + 1,mid+1,right,mid+1,h);
      return merge(leftVal,rightVal); 
    }
  }
  
  void update(int t, int l, int h, int origIndex, T value) {
    if(l == h) {
      tree[t] = value;
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
      tree[t] = value;
      return;
    }

    int left = 2*t;
    int right = 2*t + 1;
    int mid = (l+h)/2;

    if(e <= mid)
      update(left, l, mid, s, e, value);
    else if(start > mid)
      update(right, mid+1, h, s, e, value);
    else {
      update(left, l, mid, s, mid, value);
      update(right, mid+1, h, mid+1, e, value); 
    }
    
    tree[t] = merge(tree[left],tree[right]);
  }
  
public:
  void build(T orig[],int size) {
    this->size = size;
    this->treeSize = getSegmentTreeSize(size);
    build(orig,1,0,size-1);
  }

  static int getSegmentTreeSize(int N) {
    double size = ceil(log2(N));
    int sizeInt = (int) size;
    return 1 << sizeInt;
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

int main() {
  
  return 0;
}
