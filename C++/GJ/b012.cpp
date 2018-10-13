#include<iostream>
#include<string>
#include<vector>

#define pb push_back

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	long long ans = 0;
	string str;
	vector < int > data;
	cin >> str;
	for ( int i = 0 ; i < str.size() ; i++ ){
		if ( str[i] == 'I' )
			data.pb ( 1 );
		else if ( str[i] == 'V' )
			data.pb ( 5 );
		else if ( str[i] == 'X' )
			data.pb ( 10 );
		else if ( str[i] == 'L' )
			data.pb ( 50 );
		else if ( str[i] == 'C' )
			data.pb ( 100 );
		else if ( str[i] == 'D' )
			data.pb ( 500 );
		else if ( str[i] == 'M' )
			data.pb ( 1000 );
	}

	data.pb ( 0 );
	data.pb ( 0 );
	data.pb ( 0 );
	int i;
	for ( i = 0 ; i < data.size() - 1 ; i++ ){
		if ( data[i] < data[i + 1] ){
			ans += data[i + 1] - data[i];
			i++;
		}
		else
			ans += data[i];
	}

	ans += data[i];

	cout << ans << '\n';
}