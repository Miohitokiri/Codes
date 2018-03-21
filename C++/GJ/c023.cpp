#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, x, y, dis = 0, ans, ma = 0;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> x >> y;
		dis = x * x + y * y;
		if ( ma < dis ){
			ma = dis;
			ans = i;
		}
	}

	cout << ans << ' ' << ma << '\n';
}