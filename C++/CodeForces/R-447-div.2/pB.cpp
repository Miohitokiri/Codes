#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, k, ans = 1;
	cin >> n >> m >> k;
	if ( n == 1 || m == 1 ){
		cout << 1 << '\n';
		return 0;
	}

	if ( k == -1 ){
		n--, m--;
		n /= 2, m /= 2;
		cout << n * m << '\n';
	}
	else{
		n /= 2, m /= 2;
		cout << n * m << '\n';
	}
}