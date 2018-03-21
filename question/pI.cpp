#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, cnt, Index;
	while ( cin >> n ){
		if ( n == 1 ){
			cout << 1 << '\n';
			continue;
		}
		cnt = 1;
		Index = 1;
		while ( cnt < n ){
			cnt += 2;
			for ( int i = 0 ; i < cnt ; i++ )
				Index += 2;
		}

		cout << ( Index * 3 - 6 ) << '\n';
	}
}