#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int root(vector<int> uni, int iter){
  int parent = iter;
  if (parent == uni[parent]) {
    return parent;
  }else{
    return root(uni, uni[parent]);
  }
}

int main() {
  int N, M;

  cin >> N >> M;

  vector<int> p(N), U(N), rank(N);
  int x, y;

  for(int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
    rank[i] = 0;
    U[i] = i;
  }
  for(int i = 0; i < M; i++){
    cin >> x >> y;

    x--;
    y--;
    x = root(U, x);
    y = root(U, y);
    if (x == y){
    }else if (rank[x] > rank[y]){
      U[y] = x;
    }else{
      U[x] = y;
      if(rank[x] == rank[y]) rank[y]++;
    }
  }
  int count = 0;

  //for(int i = 0; i < N; i++) cout << i  << ":" << root(U,i) << endl;
  // for (int i = 0; i < N; i++){
  //   if (i == p[i]){
  //     count++;
  //   }else if (root(U, i) == root(U, p[i])) {
  //     count++;
  //   }
  // }

  vector<vector<int>> a(N), b(N);
  int k;
  for(int i = 0; i < N; i++){
    k = root(U, i);
    a[k].push_back(i);
    b[k].push_back(p[i]);
  }

  for (int i = 0; i < N; i++){
    if(!a[i].empty()){
      for(x : a[i]){
        for(y : b[i]){
          if (x == y) {
            count++;
             break;
           }
        }
      }
    }
  }
  cout << count << endl;



  return 0;
}
