#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	vector < int > data;
	string a;
	char s;
	cin >> a >> s;;
	for ( int i = 0 ; i < a.size() ; i++ )
		if ( 'A' <= a[i] && a[i] <= 'Z' )
			a[i] += 'a' - 'A';

	if ( 'A' <= s && s <= 'Z' )
		s += 'a' - 'A';
	for ( int i = 0 ; i < a.size() ; i++ )
		if ( a[i] == s )
			data.push_back ( i );

	for ( int i = 1 ; i < data.size() ; i++ )
		cout << data[i] - data[i - 1] << ' ';
	cout << '\n';
}