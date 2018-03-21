#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	string a, b, c;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> a >> b >> c;
		if ( a.size() == b.size() && b.size() == c.size() )
			cout << max ( max ( a, b ), c );
		else{
			int ma = max ( max ( a.size(), b.size() ), c.size() );
			if ( ma == a.size() )
				cout << a;
			else if ( ma == b.size() )
				cout << b;
			else
				cout << c;
		}
		cout << '\n';
	}
}