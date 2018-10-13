#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	string str;
	int ma = -1, idx, in, sum, cnt = 0;
	while ( getline ( cin, str ) ){
		cnt++;
		stringstream ss ( str );
		sum = 0;
		while ( ss >> in ){
			sum += in;
		}
		if ( ma < sum ){
			ma = sum, idx = cnt;
		}
	}
	cout << idx << ' ' << ma << '\n';
}