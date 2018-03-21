#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, ans = 0;

	cin >> n;

	while ( n >= 3 ){
		ans++;
		switch ( n % 3 ){
			case 0 : n /= 3; break;
			case 1 : n = 2 * n + 1; break;
			case 2 : n = 2 * n - 1;
		}
	}

	ans++;

	cout << ans << '\n';
}