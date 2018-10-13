#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int m, d, l;
	cin >> m >> d >> l;
	// cout << m << ' ' << d << ' ' << l << '\n';
	d += l;
	if ( d > 31 ){
		d -= 31;
		m++;
	}
	// cout << m << ' ' << d << '\n';
	if ( m < 8 || ( m == 8 && d <= 30 ) )
		cout << "YES\n";
	else
		cout << "NO\n";
}