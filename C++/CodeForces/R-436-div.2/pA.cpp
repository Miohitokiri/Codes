#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, data[105], stop, a, b;
	memset ( data, 0, sizeof ( data ) );
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		data[stop]++;
	}

	bool ans = false;
	for ( int i = 0 ; i < 105 && !ans ; i++ )
		for ( int j = 0 ; j < i && !ans ; j++ ){
			if ( data[i] == data[j] && data[i] != 0 && data[i] + data[j] == n ){
				ans = true;
				a = i, b = j;
			}
		}

	if ( !ans )
		cout << "No";
	else{
		if ( a > b )
			swap ( a, b );
		cout << "Yes\n" << a << ' ' << b;
	}

	cout << '\n';
}