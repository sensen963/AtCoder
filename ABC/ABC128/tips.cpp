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

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

struct hoge{
  int x;
  int y;
  string name;
  hoge(int _x, int _y, string _name){
    x = _x;
    y = _y;
    name = _name;
  }
};


int main() {

  vector<hoge> v;

  v.push_back(hoge(1, 2, "an"));
  v.push_back(hoge(3, 4, "bn"));
  v.push_back(hoge(5, 6, "cm"));
  v.push_back(hoge(7, 8, "dp"));

  sort(v.begin(), v.end(), [](hoge& hoge1, hoge& hoge2){
    return (hoge1.x > hoge2.x);
  });

  for(auto tmp : v) cout << tmp.name << endl;
  return 0;
}
