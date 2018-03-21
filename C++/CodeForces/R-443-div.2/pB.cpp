#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, k, win = 0, ma, cnt = 0;
	cin >> n >> k;
	vector < int > a ( n );
	for ( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = i + 1 ; j < n ; j++ ){
			if ( a[i] > a[j] )
				cnt++;
			else{
				cnt = 1;
				break;
			}

			if ( cnt == k )
				break;
		}
		if ( cnt == k ){
			cout << a[i] << '\n';
			return 0;
		}
	}

	cout << *max_element ( a.begin(), a.end() ) << '\n';
}