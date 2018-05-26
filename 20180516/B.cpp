#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  char S[N];
  cin >> S;

  int i, j, k;
  int max = 0;
  int tmp;
  bool isfollow = false;
  bool isj = false;
  for(i = 1; i < N; i++){
    tmp = 0;
    for(j = 0; j < i; j++){
      // 前の確認
      if (j != 0){
        for(k = j-1; k >= 0; k--){
          if(S[j] == S[k]){
            isfollow = true;
            //cout << j << k << endl;
          }

        }
      }
      if(isfollow == false){
        for(k = i; k < N; k++){
          if(S[j] == S[k]){
            isj = true;
            break;
          }
        }
        if (isj){
          tmp++;
        }
      }
      isfollow = false;
      isj = false;
    }
    //cout << tmp << endl;
    if (tmp > max){
      max = tmp;
    }
  }

  cout << max;
  return 0;

}
