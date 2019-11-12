// by. MiohitoKiri5474
#include<iostream>

using namespace std;

// gg2ez

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, in, cnt = 0;
	cin >> n >> m;
	if ( m == 1 )
		cnt = 18;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		if ( in > 87 ){
			if ( cnt < 18 ){
				cout << "1 ";
				continue;
			}
			cnt++;
		}
		cout << "0 ";
	}

	cout << '\n';
	if ( cnt < 18 )
		cout << "HAHAHA\n";
	else
		cout << "GOOD\n";
}