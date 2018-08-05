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

  cin >> s;

  bool a1 = false;
  bool a2 = false;
  bool a3 = false;
  int tail = s.size();
  //cout << s[s.size() - 1] << endl;

  if (s[0] == 'A') a1 = true;

  int c_i;
  int count_c = 0;
  for (int i = 2; i < tail - 1; i++){
    if (s[i] == 'C'){
      count_c++;
      c_i = i;
    }
  }
  int count_s = 0;
  if (count_c == 1){
    for (int i = 1; i < tail; i++){
      if (s[i] >= 'a' && s[i] <= 'z') {
        count_s++;
      }
      //a3 = true;
    }
  }
  if (count_s == tail - 2) a3 = true;

  //cout << c_i << endl;

  if (a1 && a3){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
  return 0;
}
