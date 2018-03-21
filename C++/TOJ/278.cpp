#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	set < string > be;
	be.insert ( "be" );
	be.insert ( "is" );
	be.insert ( "was" );
	be.insert ( "am" );
	be.insert ( "are" );
	be.insert ( "were" );
	be.insert ( "been" );

	string in, stop;
	const char data = 'a' - 'A';
	int t, ans;
	cin >> t;
	cin.ignore();
	while ( t-- ){
		ans = 0;
		stop = "";
		vector < string > vs ( 1 );
		getline ( cin, in );
		for ( auto i: in ){
			if ( !( 'a' <= i && i <= 'z' || 'A' <= i && i <= 'Z' ) )
				vs.push_back ( "" );
			else if ( 'a'<=i && i <= 'z' )
				vs.back() += i;
			else
				vs.back() += i + data;
		}

		for ( auto i: vs )
			be.count ( i ) ? ans++ : ans;

		cout << ans << '\n';
	}
}