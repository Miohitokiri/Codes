#include<iostream>
#include<string>

using namespace std;

int main(){
	string str;
	int cnt = 0;
	cin >> str;
	for ( int i = 0 ; i < str.size() ; i++ )
		if ( str[i] == 'S' )
			cnt++;

	double w = cnt * 1.0 / str.size();
	if ( w >= 0.1 )
		cout << "EUROPE\n";
	else if ( w <= 0.02 )
		cout << "AFRICA\n";
	else
		cout << "NORMAL\n";
}