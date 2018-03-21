#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	bool ans;
	string in, s;
	while ( cin >> in ){
		if ( in == "END" )
			break;

		for ( int i = 0 ; i < in.size() ; i++ ){
			s += in[i];
			if ( in[i] == '0' || in[i] == '1' )
				continue;
		}
	}
}