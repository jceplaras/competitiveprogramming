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

#define MAXN 2*100005  

template<class T,class V>
class SegmentTree {

private:
  //tree rooted at index 1
  T tree[MAXN];
  int size;
  int treeSize;


  V merge(T leftVal, T rightVal) {
    return min(leftVal,rightVal);
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
  
public:
  SegmentTree(T orig[],int size) {
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
    update(1, 0, size-1, index, value);
  }

};

int main() {
  int N;
  int arr[MAXN];


  cin >> N;

  FORN(i,N)
    cin >> arr[i];

  SegmentTree<int,int> st(arr,N);

  int Q;
  cin >> Q;

  while(Q--) {
    int l,r;
    cin >> l >> r;

    cout << st.query(l,r) << endl;
  }

  
  return 0;
}
