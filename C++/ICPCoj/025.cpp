#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str, data = "MTF";
	cin >> str;
	for ( int i = 0 ; i < str.size() ; i++ ){
		int cnt = 0;
		for ( int j = 0 ; j < data.size() ; j++ )
			if ( data[j] == str[i + j] )
				cnt++;
		if ( cnt != 3 )
			str[i] = '.';
		if ( cnt == 3 )
			i += 2;
	}

	cout << str << '\n';
}