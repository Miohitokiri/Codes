#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int cnt = 0;
	string str;
	cin >> str;
	for ( int i = 0 ; i < str.size() - 1 ; i++ )
		if ( str[i] == 'A' && str[i + 1] == 'C' )
			cnt++;

	cout << cnt << '\n';
}