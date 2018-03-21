#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, stop, ans;
	vector < int > data;
	cin >> t;
	while ( t-- ){
		cin >> n;
		data.clear(), ans = 0;
		while ( n-- ){
			cin >> stop;
			data.push_back ( stop );
		}
		sort ( data.begin(), data.end() );
		for ( int i = 2 ; i < data.size() ; i++ )
			for ( int j = 1 ; j < i ; j++ )
				for ( int  s = 0 ; s < j ; s++ )
					data[i] * data[i] == data[j] * data[j] + data[s] * data[s] ? ans++ : ans;

		cout << ans << '\n';
	}
}