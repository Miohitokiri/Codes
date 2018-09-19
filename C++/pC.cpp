// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str, swp;
	int t;
	cin >> t;
	getline ( cin, str );
	while ( t-- ){
		getline ( cin, str );
		cout << "Tokens found:\n";
		swp = "";
		for ( auto i: str ){
			if ( i == ':' || i == ',' || i == ';' ){
				cout << swp << '\n';
				swp = "";
			}
			else
				swp += i;
		}
		if ( swp != "" )
			cout << swp << '\n';
	}
}