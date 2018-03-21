#include<bits/stdc++.h>
using namespace std;
vector < int > data[505];
queue < int > ans;
inline int dfs ( int n, int s );
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, a, b, mi = 1000;
	while ( cin >> n ){
		for ( int times = 0 ; times < n ; times++ ){
			cin >> a >> b;
			data[a].push_back ( b );
			data[b].push_back ( a );
		}

		for ( int i = 1 ; i < 505 && ans.size() != 0 ; i++ )
			dfs ( i );

		while ( ans.size() != 0 ){
			cout << ans.front() << '\n';
			ans.pop();
		}

		cout << '\n';
	}
}