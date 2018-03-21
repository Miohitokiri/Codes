#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop, ans = 0, Index = 0, mark;
	vector < int > data;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		data.push_back ( stop );
	}

	for ( int i = 0 ; i < n ; i++ )
		if ( data[i] == 1 )
			Index = i;

	for ( int i = 2 ; i <= n ; i++ ){
		for ( int j = 0 ; j < n ; j++ )
			if ( data[j] == i ){
				mark = j;
				break;
			}

		ans += fabs ( mark - Index );
		Index = mark;
	}

	cout << ans << '\n';
}