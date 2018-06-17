#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int N;
  vector<int> now{0, 0, 0};
  vector<int> next{0, 0, 0};

  bool isable = true;
  cin >> N;
  int i;
  for (i=0; i < N; i++){
    //cin >> next[0] >> next[1] >> next[2];
    scanf("%d", &next[0]);
    scanf("%d", &next[1]);
    scanf("%d", &next[2]);
    if (isable && (next[1] + next[2] - now[1] - now[2]) <= (next[0] - now[0]) &&
        (((next[0] - now[0]) - (next[1] + next[2] - now[1] - now[2])) % 2 == 0)){
      now = next;
    }else{
      isable = false;
    }
  }

  if (!isable){
    cout << "No" << endl;
  }else cout << "Yes" << endl;

  return 0;

}
