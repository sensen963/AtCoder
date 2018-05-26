#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  char S[N];
  cin >> S;

  int min = N;
  int count = 0;
  bool isover = false;
  for(int i=0; i < N; i++){
    count = 0;
    isover = false;
    for (int j=0; j < i; j++){
      if (S[j] == 'W'){
        count++;
        if (count > min){
          isover = true;
          break;
        }
      }
    }
    if (!isover){
      for (int j = i + 1; j < N; j++){
        if (S[j] == 'E'){
          count++;
          if (count > min){
            isover = true;
            break;
          }
        }
      }
    }
    //cout << count << endl;
    if (min > count && !isover) min = count;

  }
  cout << min << endl;
  return 0;
}
