#include<iostream>
#include<vector>

using namespace std;

typedef pair < int, int > pii;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, k, stop;
	cin >> n >> k;
	vector < pii > data;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> stop;
		data.push_back ( make_pair ( -1 * stop, i ) );
	}

	sort ( data.begin(), data.end() );

	for ( int i = 0 ; i < n ; i++ )
		if ( data[i].second == k ){
			cout << i + 1 << '\n';
			return 0;
		}
}