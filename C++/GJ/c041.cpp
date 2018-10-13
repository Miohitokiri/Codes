#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in, avg = 0, ans = 0;
	vector < int > data;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		data.push_back ( in );
		avg += in;
	}
	avg /= n;
	for ( int i = 0 ; i < n ; i++ ){
		if ( data[i] > avg ){
			ans += data[i] - avg;
		}
	}
	cout << ans << '\n';
}