#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( 0 );
	cin.tie ( 0 );
	string a, b;
	while ( cin >> a >> b ){
		if ( a == "0" || b[0] == '0' ){
			cout << 0;
		}
		else if ( a[0] == '-' || b[0] == '-' ){
			if ( a[0] == '-' && b[0] == '-' ){
				for ( int i = 1 ; i < b.size() ; i++ )
					cout << b[i];
				for ( int i = 2 ; i < a.size() ; i++ )
					cout << a[i];
			}
			else if ( b[0] == '-' ){
				cout << b;
				for ( int i = 1 ; i < a.size() ; i++ )
					cout << a[i];
			}
			else{
				cout << '-' << b;
				for ( int i = 2 ; i < a.size() ; i++ )
					cout << a[i];
			}
		}
		else{
			cout << b;
			for ( int i = 1 ; i < a.size() ; i++ )
				cout << a[i];
		}
		cout << '\n';
	}
}