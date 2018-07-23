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

int main() {

  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for(int i = 0; i < M; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<int> vect_M(M);
  vector<int> vect_M1(0);
  for(int i=0; i<M; i++) vect_M[i] = i;

  int count = 0;
  //for(int i: vect_M) cout << vect_M[i];

  while(vect_M.size() > 0){
    int min_b = INF;
    for (int i: vect_M) min_b = min(b[i], min_b);

    //cout << "min_b: " << min_b << endl;

    vect_M1.clear();
    for(auto i : vect_M){
      if(a[i] >= min_b){
        vect_M1.push_back(i);
        //cout << vect_M1[i] << i << endl;
      }
    }
    vect_M = vect_M1;
    //for(int j: vect_M1) cout << j << endl;
    // cout << endl;
    // for(int j: vect_M) cout << vect_M[j];
    // cout << endl;
    count++;
  }

  cout << count << endl;

  return 0;
}
