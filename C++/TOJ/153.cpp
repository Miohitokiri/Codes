#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, data[3];
	cin >> n;
	while ( n-- ){
		for ( int i = 0 ; i <= 2 ; i++ )
			cin >> data[i];
		sort ( data, data + 3 );
		if ( ( data[0] <= 0 || data[1] <= 0 || data[2] <= 0 ) || ( data[0] + data[1] <= data[2] ) ){
			cout << "illegal triangle\n";
			continue;
		}

		for ( int i = 0 ; i < 3 ; i++ )
			data[i] *= data[i];

		if ( data[0] + data[1] == data[2] )
			cout << "right triangle\n";
		else if ( data[0] + data[1] < data[2] )
			cout << "acute triangle\n";
		else
			cout << "obtuse triangle\n";
	}
}