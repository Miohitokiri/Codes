#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	long long ans;
	vector < int > candy, chochlet;
	while ( cin >> n ){
		ans = 0;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			candy.push_back ( stop );
		}

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			chochlet.push_back ( stop );
		}

		sort ( candy.begin(), candy.end() );
		sort ( chochlet.begin(), chochlet.end() );

		while ( n-- )
			ans += candy[n] * chochlet[n];

		cout << ans << '\n';

		candy.clear();
		chochlet.clear();
	}
}