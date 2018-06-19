#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


// long long llabs(long long a){
//   if (a < 0){
//     a = -1 * a;
//   }
//
//   return a;
// }

int main(){


  int n, m;
  cin >> n >> m;

  vector<long long> va, vb, vc;

  long long a, b, c;
  for (int i = 0; i < n; i++){
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    va.push_back(a);
    vb.push_back(b);
    vc.push_back(c);
  }

  long long max_tmp = 0;
  long long tmp = 0;
  //vector<long long> cmp;
  int p, q, r;
  for (int i = 0; i < 8; i++){
    vector<long long> cmp;
    p = i % 2;
    q = int(i / 2) % 2;
    r = int(i / 4) % 2;
    cout << r <<q << p << endl;
    for (int j = 0; j < n; j++){
      if (p == 0) tmp += va[j]; else tmp -= va[j];
      if (q == 0) tmp += vb[j]; else tmp -= vb[j];
      if (r == 0) tmp += vc[j]; else tmp -= vc[j];
      cmp.push_back(tmp);
      tmp = 0;
    }
    sort(cmp.begin(), cmp.end(), greater<long long>());
    for (int j = 0; j < m; j++){
      tmp += cmp[j];
      cout << cmp[j] << endl;
    }
    // max_tmp = max_tmp > tmp ? max_tmp : tmp;
    if (max_tmp < tmp) max_tmp = tmp;
    //cmp.clear();
    tmp = 0;
  }
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(va[i] + vb[i] + vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(va[i] + vb[i] - vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(va[i] - vb[i] + vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(va[i] - vb[i] - vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(-1 * va[i] + vb[i] + vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(-1 * va[i] + vb[i] - vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(-1 * va[i] - vb[i] + vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;
  // for (int i = 0; i < n; i++){
  //   cmp.push_back(-1 * va[i] - vb[i] - vc[i]);
  // }
  // sort(cmp.begin(), cmp.end(), greater<int>());
  // for(int i = 0; i < m; i++){
  //   tmp += cmp[i];
  // }
  // max_tmp = max_tmp > tmp ? max_tmp : tmp;
  // cmp.clear();
  // tmp = 0;

  // sort(va.begin(), va.end());
  // sort(va.begin(), va.end());
  // sort(va.begin(), v.end());

  cout << max_tmp << endl;
  //printf("%lld\n", max_tmp);
  return 0;

}
