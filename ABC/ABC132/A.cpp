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


int main() {

  string s;
  cin >> s;

   string ans = "No";
  if (s[0] != s[1]){
    if ((s[0] == s[2] && s[1] == s[3]) || (s[0] == s[3] && s[1] == s[2])) ans = "Yes";
  }
  else{
    if (s[2] == s[3] && s[0] != s[2]) ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}
