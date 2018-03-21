#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, ma = -1, ans, stop, t;
	vector < int > data;
	cin >> t;
	while ( t-- ){
		cin >> n;
		data.resize ( n );
		ans = 0, ma = -1;
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];

		for ( int i = 1 ; i < n ; i++ ){
			stop = fabs ( data[i] - data[i - 1] );
			if ( ma < stop ){
				ma = stop;
				ans = i;
			}
		}

		cout << ans << '\n';
	}
}