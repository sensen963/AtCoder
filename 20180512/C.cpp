#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  string s;
  int k;
  cin >> s >> k;

  vector<string> v;

  for (int i = 0; i < s.length(); i++){
    for (int j = 1; j <= k; j++){
      v.push_back(s.substr(i, j));
    }
  }
  // for(auto itr = v.begin(); itr != v.end(); ++itr) {
  //         std::cout << *itr << "\n";
  //     }
  // cout << endl;
  sort(v.begin(), v.end());
  // for(auto itr = v.begin(); itr != v.end(); ++itr) {
  //       std::cout << *itr << "\n";
  //   }
  //   cout << endl;
  unique(v.begin(), v.end());
  // for(auto itr = v.begin(); itr != v.end(); ++itr) {
  //       std::cout << *itr << "\n";
  //   }
  //   cout << endl;

  cout << v[k-1] << endl;
  return 0;
}
