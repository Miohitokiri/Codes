#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, f, k;
	cin >> a >> b >> f >> k;

	if ( b < f || ( a - f ) > b || ( k > 1 && ( a - f ) * 2 > b ) || ( k > 2 && f * 2 > b ) )
		cout << -1;
	else{
		int gas = b - f, ans = 0;

		vector < int > flag;
		flag.push_back ( f );
		for ( int i = 1 ; i < k ; i++ ){
			if ( i & 1 )
				flag.push_back ( *( flag.end() - 1 ) + 2 * ( a - f ) );
			else
				flag.push_back ( *( flag.end() - 1 ) + 2 * f );
		}

		if ( k & 1 )
			flag.push_back ( *( flag.end() - 1 ) + a - f );
		else
			flag.push_back ( *( flag.end() - 1 ) + f );

		for ( int i = 1 ; i < flag.size() ; i++ ){
			if ( gas < flag[i] - flag[i - 1] )
				gas = b, ans++;
			gas -= flag[i] - flag[i - 1];
		}

		cout << ans;
	}

	cout << '\n';
}