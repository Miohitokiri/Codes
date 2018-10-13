#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	string str, in;
	int i = 0, j;
	while ( getline ( cin, str ) ){
		i++;
		j = 0;
		stringstream ss ( str );
		while ( ss >> in ){
			j++;
			if ( in == "BILL" ){
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
}