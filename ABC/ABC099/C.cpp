
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> memo;
  vector<int> usable;

  int use_six = 6;
  int use_nine = 9;

  usable.push_back(1);
  memo.push_back(1);

  int ming = 99999;

  for (int i = 2; i <= n; i++){
    if (i == use_six){
      memo.push_back(1);
      usable.push_back(i);
      use_six *= 6;
    } else if(i == use_nine){
      memo.push_back(1);
      usable.push_back(i);
      use_nine *= 9;
    } else{
      ming = 9999;
      for(int x: usable){
        ming = min(memo[x-1] + memo[i - x - 1], ming);
      }
      memo.push_back(ming);
    }
    //cout << memo[i-1] << endl;

  }

  cout << memo[n-1] << endl;


  return 0;

}
