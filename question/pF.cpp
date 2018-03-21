#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, cnt = 0, ans, sum;
	vector < int > data;
	while ( cin >> n ){
		if ( !n )
			break;
		ans = sum = 0;
		data.resize ( n );
		for ( int i = 0 ; i < n ; i++ ){
			cin >> data[i];
			sum += data[i];
		}

		sum /= n;
		for ( auto i: data )
			ans += abs ( sum - i );

		ans /= 2;
		cout << "Set #" << ++cnt << "\nThe minimum number of moves is " << ans << ".\n\n";
	}
}