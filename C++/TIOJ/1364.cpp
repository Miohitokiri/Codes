#include<bits/stdc++.h>
using namespace std;
int data[1000005];
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m;
	while (  ( cin >> n ) != false ){
		cin >> m;
		m--;
		memset ( data, 0, sizeof ( data ) );
		for ( int i = 0 ; i < n ; i++ ){
			cin >> data[i];
			data[i] *= -1;
		}

		sort ( data, data + n );

		// for ( int i = 0 ; i < n ; i++ )
		// 	cout << data[i] << ' ';
		// cout << '\n';

		cout << data[m] * -1 << '\n';
	}
}