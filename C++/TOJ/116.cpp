#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string a, b, index;
	int n, k, count = 2;

	cin >> a >> b >> n >> k;

	if ( n > 2 ){
		while ( b.size() < k && count++ < n ){
			index = a + b;
			swap ( a, b );
			swap ( b, index );
		}

		cout << ( b.size() < k ? 'X' : b[k - 1] );
	}
	else if ( n == 2 )
		cout << ( b.size() < k ? 'X' : b[k - 1] );
	else if ( n == 1 )
		cout << ( a.size() < k ? 'X' : a[k - 1] );

	cout << '\n';
}