#include<iostream>
#include<set>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, stop;
	set < int > data;
	cin >> n >> m;
	while ( m-- ){
		cin >> stop;
		data.insert ( stop );
	}

	for ( int i = 1 ; i <= n ; i++ )
		if ( data.find ( i ) == data.end() )
			cout << i << ' ';

	cout << '\n';
}