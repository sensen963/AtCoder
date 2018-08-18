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
  string s;
  ll K;

  cin >> s;
  cin >> K;

  ll i = 0;
  ll k;
  while(i <= s.size()){
    if (s[i] != '1'){
      break;
    }
    i++;
  }
//  cout << i << endl;

  if (i >= K){
    cout << 1 << endl;
  }else{
    cout << s[i] << endl;
  }



  return 0;
}
