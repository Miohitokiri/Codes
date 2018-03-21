#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	stringstream ss;
	string in, data;
	long long stop, ans;
	while ( getline ( cin, in ) ){
		ss.str ( "" );
		ss.clear();
		ans = 0;
		in += ' ';
		for ( int i = 0 ; i < in.size() ; i++ )
			if ( in[i] != ' ' )
				data += in[i];
			else if ( data.size() != 0 ){
				ss << data;
				data = "";
				ss >> stop;
				ss.str ( "" );
				ss.clear();
				ans += stop;
				ans %= 1000000007;
			}

		printf ( "%d\n", ans );
	}
}