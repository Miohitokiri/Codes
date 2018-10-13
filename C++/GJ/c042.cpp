#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int ans = 0;
	string str;
	vector < int > data;
	cin >> str;
	str = 'f' + str + 'f';
	for ( int i = 0 ; i < str.size() ; i++ ){
		if ( str[i] == 'f' )
			data.push_back ( i );
	}

	// for ( int i = 0 ; i < data.size() ; i++ )
	// 	cout << data[i] << ' ';
	// cout << '\n';
	for ( int i = 1 ; i < data.size() ; i++ ){
		ans = max ( ans, data[i] - data[i - 1] - 1 );
	}
	cout << ans << '\n';
}