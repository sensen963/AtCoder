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

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
  vector<int> array(n);
  vector<int> odd_a(1e5+1, 0), even_a(1e5+1, 0);
  REP(i, n){
    cin >> array[i];
    if(i % 2 == 0){
      odd_a[array[i]]++;
    } else {
      even_a[array[i]]++;
    }
  }
  int max_odd, max_even, max_odd1, max_even1;
  int odd_count = 0;
  int even_count = 0;
  int odd_count1 = 0;
  int even_count1 = 0;
  int ans = 0;
  REP(i, 1e5+1) {
    if(odd_count < odd_a[i]){
      odd_count = odd_a[i];
      max_odd = i;
    }
  }
  REP(i, 1e5+1) {
    if(even_count < even_a[i]){
      even_count = even_a[i];
      max_even = i;
    }
  }
  if (even_count > odd_count){
    if (max_odd == max_even) {
      odd_count = 0;
      REP(i,1e5+1) {
        if (i != max_even && odd_count < odd_a[i]){
          odd_count = odd_a[i];
          max_odd = i;
        }
      }
      ans = n - even_count - odd_count;
    }else {
      ans = n - even_count - odd_count;
    }
  }else if (even_count < odd_count) {
    if (max_odd == max_even) {
      even_count = 0;
      REP(i,1e5+1) {
        if (i != max_odd && even_count < even_a[i]){
          even_count = even_a[i];
          max_even = i;
        }
      }
      ans = n - even_count - odd_count;
    }else {
      ans = n - even_count - odd_count;
    }
  } else {
    if (max_odd == max_even) {
      even_count1 = 0;
      REP(i,1e5+1) {
        if (i != max_odd && even_count1 < even_a[i]){
          even_count1 = even_a[i];
          max_even1 = i;
        }
      }
      odd_count1 = 0;
      REP(i,1e5+1) {
        if (i != max_even && odd_count1 < odd_a[i]){
          odd_count1 = odd_a[i];
          max_odd1 = i;
        }
      }
      ans = min(n - even_count - odd_count1, n - even_count1 - odd_count);
    } else {
      ans = n - even_count - odd_count;
    }
  }

  cout << ans << endl;
  return 0;
}
