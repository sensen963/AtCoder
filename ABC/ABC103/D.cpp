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

  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for(int i = 0; i < M; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  int count = 0;

  vector<int> vect_M(M);
  for(int i=0; i<M; i++) vect_M[i] = i;

  while(vect_M.size() > 0){

    vector<int> vect(N);
    //for(int i = 0; i < N; i++)cout << vect[i] << endl;
    //for(int i = 0; i < M; i++) for(int j=a[i]; j < b[i]; j++) vect[j]++;
    for(int i : vect_M) for(int j=a[i]; j < b[i]; j++) vect[j]++;
    std::vector<int>::iterator iter = max_element(vect.begin(), vect.end());
    for(int i = 0; i < N; i++)cout << vect[i] << endl;
    int index = distance(vect.begin(), iter);
    cout << index << endl;

    vector<int> vect_M1;
    for(int i : vect_M){
      if(a[i] <= index && b[i] > index){
      }else{
        vect_M1.push_back(i);
        //cout << i << endl;
      }

    }
    vect_M = vect_M1;
    count++;
    cout << endl;
    for(int i : vect_M) cout << vect_M[i];
    cout << endl;
  }

  cout << count << endl;

  return 0;
}
