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

  bool ans = false;
  int in_c = 0;
  int c_i;
  int tail = s.size();
  if(s[0] == 'A'){
    for (int i = 2; i < tail - 1; i++){
      if (s[i] == 'C'){
        in_c++;
        c_i = i;
      }
    }
    if (in_c == 1){
      for (int j = 1; j < tail; j++){
        if (j != c_i){
          if (s[j] >= 'a' && s[j] <= 'z'){
          }
          else{
            break;
          }
        }
        ans = true;
      }
    }
  }

  //cout << s.size() << endl;


  if (ans){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
  return 0;
}
