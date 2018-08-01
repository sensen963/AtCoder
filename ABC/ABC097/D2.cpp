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
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};


int main() {
  int N, M;

  cin >> N >> M;

  vector<int> p(N);
  int x, y;

  union_find uf(N);

  for(int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
  }

  for(int i = 0; i < M; i++){
    cin >> x >> y;

    x--;
    y--;
    x = uf.find(x);
    y = uf.find(y);

    uf.unite(x, y);
  }

  vector<vector<int>> a(N), b(N);
  int k;
  for(int i = 0; i < N; i++){
    k = uf.find(i);
    a[k].push_back(i);
    b[k].push_back(p[i]);
  }

  int count = 0;

  // for (int i = 0; i < N; i++){
  //   if(!a[i].empty()){
  //     for(int x : a[i]){
  //       for(int y : b[i]){
  //         if (x == y) {
  //           count++;
  //            break;
  //          }
  //       }
  //     }
  //   }
  // }

  for (int i = 0; i < N; i++) {
		if (!a[i].empty()) {
			set<int> s(b[i].begin(), b[i].end());
			for (int x : a[i])if (s.count(x))count++;
		}
	}
  cout << count << endl;

  return 0;
}
