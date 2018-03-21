#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, stop, cnt = 0, ans, ma = 0, p;
	vector < int > data;
	cin >> n;
	while ( n-- ){
		cin >> stop;
		data.push_back ( stop );
	}

	sort ( data.begin(), data.end() );

	for ( int i = 0 ; i < n ; i++ ){
	}
}