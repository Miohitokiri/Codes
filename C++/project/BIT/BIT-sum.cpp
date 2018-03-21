// 帶單點修改修改區間最大值
#include<bits/stdc++.h>

using namespace std;

int BIT[105], basic[105];
inline void insert ( int a, int k );
inline int low_bits ( int n );
inline int query ( int l, int r );
inline int sum ( int n );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int stop, a, b, type, n, q;
	cin >> n >> q;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> stop;
		insert ( i, stop );
		basic[i] = stop;
	}

	while ( q-- ){
		cin >> type >> a >> b;
		if ( type == 2 ){
			insert ( a, b );
			basic[a] = b;
		}
		else
			cout << query ( a, b ) << '\n';
	}
}

inline int low_bits ( int n ){
	return n & -n;
}

inline void insert ( int a, int k ){
	while ( a <= 9 ){
		BIT[a] += k - basic[a];
		a += low_bits ( a );
	}
}

inline int query ( int a, int b ){
	if ( a > b )
		swap ( a, b );
	return sum ( b ) - sum ( a - 1 );
}

inline int sum ( int n ){
	int s = 0;
	while ( n ){
		s += BIT[n];
		n -= low_bits ( n );
	}
	return s;
}