#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, x, stop, ans = 0;
	vector < int > dataV;
	set < int > dataS;
	cin >> n >> x;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		if ( stop == x )
			ans++;
		if ( stop == x && dataS.find ( stop ) != dataS.end() )
			dataS.insert ( stop );

		if ( dataS.find ( stop ) != dataS.end() )
			continue;

		dataV.push_back ( stop );
		dataS.insert ( stop );
	}

	sort ( dataV.begin(), dataV.end() );

	for ( int i = 0 ; i < *( dataV.end() - 1 ) && i != x ; i++ )
		if ( dataS.find ( i ) == dataS.end() )
			ans++;
	ans += ( x - *( dataV.end() - 1 ) - 1 <= 0 ? 0 : x - *( dataV.end() - 1 ) - 1 );

	if ( x == 0 )
		cout << ( dataV[0] == 0 ? 1 : 0 );
	else
		cout << ans;
	cout << '\n';

	// cout << dataV.size() << '\n';
	// for ( auto i: dataV )
	// 	cout << i << ' ';
	// cout << '\n';
}