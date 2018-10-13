#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int h, m;
	cin >> h >> m;
	if ( h >= 17 || h < 7 || ( h == 7 && m < 30 ) ){
		cout << "XXX";
	}
	else if ( h == 12 ){
		cout << ( m < 30 ? "NO" : "YES" );
	}
	else{
		cout << ( m < 10 ? "NO" : "YES" );
	}
	cout << '\n';
}