#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
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
typedef vector<ull> vull;

#define MAXN 3*100001

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
    else if(s > mid)
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
    low = max(0,low);
    return query(1, 0, size-1, low, high); 
  }

  void update(int origIndex, T value) {
    update(1, 0, size-1, origIndex, value);
  }

  void updateRange(int l, int r, T value) {
    updateRange(1, 0, size-1, l, r, value);
  }

};

SegmentTree<ull,ull> st;
ull maxW = ULLONG_MAX;
int N,M,Q;
int a, b;
int v, k;
ull w;
ull minVal[100001];
vi graph[100001];
vull storeCost[100001];
vi storeKeep[100001];

void dfs(int v, int d) {
  for(int i=0;i<graph[v].size();i++) {
    int vertex = graph[v][i];
    ull minReach = maxW;

    for(int s=0;s<storeCost[vertex].size();s++) {
      minReach = min(minReach,st.query(d-storeKeep[vertex][s],d-1)+storeCost[vertex][s]); 
    }
    minVal[vertex] = minReach;

    st.update(d,minReach);
    dfs(vertex,d+1);
  }
}

int main() {
  FORN(i,100001)
    minVal[i] = maxW;

  scanf("%d %d",&N,&M);


  FORN(i,N-1) {
    scanf("%d %d",&a,&b);
    a--;
    b--;

    graph[b].push_back(a);
  }

  FORN(i,M) {
    scanf("%d %d %llu",&v,&k,&w);
    v--;

    storeCost[v].push_back(w);
    storeKeep[v].push_back(k);
  }

  st.build(minVal,N);
  st.update(0,0);
  minVal[0] = 0;
  dfs(0,1);
  
  //query
  int Q;
  scanf("%d",&Q);

  while(Q--) {
    int q;
    scanf("%d",&q);

    printf("%llu\n",minVal[q-1]);
  }



  
  return 0;
}
