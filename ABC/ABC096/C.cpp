#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int h, w;

  cin >> h >> w;

  vector<string> data;
  string s;
  for (int i = 0; i < h; i++){
    cin >> s;
    data.push_back(s);
  }
  /*
  for (int i; i < h; i++){
    cout << data[i] << endl;
  }
  */

  /*
  cout << data[1][1] << endl;
  cout << data[-1][0] << endl;
  cout << data[h][w] << endl;
    cout << data[0][-1] << endl;

  */

  bool ispossible = true;
  //bool inc = false;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j ++){
      if (data[i][j] == '#'){
        //inc = true;
        if (i == 0 && j == 0){
          ispossible = ((data[i][j+1] == '#') || (data[i+1][j] == '#'));
        }else if (i == 0 && j == w-1){
          ispossible = ((data[i][j-1] == '#') || (data[i+1][j] == '#'));
        }else if (i == h-1 && j == w-1){
          ispossible = ((data[i][j-1] == '#') || (data[i-1][j] == '#'));
        }else if (i == h-1 && j == 0){
          ispossible = ((data[i][j+1] == '#') || (data[i-1][j] == '#'));
        }else if (i == 0){
          ispossible = ((data[i+1][j] == '#') || (data[i][j+1] == '#') || (data[i][j-1] == '#'));
        }else if (i == h-1){
          ispossible = ((data[i-1][j] == '#') || (data[i][j+1] == '#') || (data[i][j-1] == '#'));
        }else if (j == 0){
          ispossible = ((data[i-1][j] == '#') || (data[i][j+1] == '#') || (data[i+1][j] == '#'));
        }else if (j == w-1){
          ispossible = ((data[i-1][j] == '#') || (data[i][j-1] == '#') || (data[i+1][j] == '#'));
        }else{
          ispossible = ((data[i-1][j] == '#') || (data[i][j+1] == '#') || (data[i][j-1] == '#') || (data[i+1][j] == '#'));
        }
      }
      if (!ispossible) break;
    }
    if (!ispossible) break;
  }

  if (ispossible){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
