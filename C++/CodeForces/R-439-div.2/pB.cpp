#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int a, b, ans = 1;
	cin >> a >> b;
	if ( b - a >= 10 )
		ans = 0;
	else
		for ( int i = a + 1 ; i <= b ; i++ ){
			ans *= i;
			ans %= 10;
		}

	cout << ans << '\n';
}