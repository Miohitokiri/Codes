#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int y, m, ans = 0;
	cin >> y >> m;
	if ( ( y < 90 || ( y == 90 && m < 7 ) ) || ( y > 101 || ( y == 101 && m > 8 ) ) ){
		cout << "0\n";
		return 0;
	}

	if ( y == 90 ){
		ans = m - 8;
	}
	else{
		ans = 4 + ( y - 90 - 1 ) * 12 + m + 1;
	}
	cout << ans << '\n';
}