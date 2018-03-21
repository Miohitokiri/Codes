#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, data[20];
	data[0] = data[1] = 0, data[2] = 1;
	for ( int i = 3 ; i < 20 ; i++ )
		data[i] = ( i - 1 ) * ( data[i - 1] + data[i - 2] );
	long long ans;
	while ( cin >> n ){
		if ( !n )
			break;

		cout << data[n] << '\n';
	}
}