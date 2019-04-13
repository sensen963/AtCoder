#include <iostream>
#include <vector>

using namespace std;

void printNormalVector(vector<int> &vect){
	for(int x:vect){
		cout << x << endl;
	}
}

void printPairVector(vector<pair<int,int> > &vect){
	for(auto x:vect){
		cout << x.first << " " << x.second << endl;
	}
}

int main(void){
	vector<int> vect(5);
	vect[0] = 1;vect[1] = 100; vect[2] = 30; vect[3] = 20; vect[4] = 4;

	sort(vect.begin(),vect.end());
	printNormalVector(vect);
	sort(vect.begin(),vect.end(),greater<int>());
	printNormalVector(vect);

	vector<pair<int,int> > vect2;
	vect2.push_back(make_pair(1, 30));
	vect2.push_back(make_pair(4, 20));
	vect2.push_back(make_pair(2, 100));
	vect2.push_back(make_pair(10, 10));
	vect2.push_back(make_pair(8, 7));

	sort(vect2.begin(), vect2.end());
	printPairVector(vect2);
	sort(vect2.begin(), vect2.end(), greater<pair<int,int> >());
	printPairVector(vect2);
}
