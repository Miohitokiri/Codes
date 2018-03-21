#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int c ( int n, int k ){
	int sum = 1;
	for ( int i = 0 ; i < k ; i++ ){
		sum *= n;
		n--;
	}

	for ( int i = 1 ; i <= k ; i++ )
		sum /= k;

	return sum;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, d;
	while ( cin >> n >> d ){
		if ( !n && !d )
			break;
	}
}