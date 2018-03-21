#include<bits/stdc++.h>
#define maxN 1005

using namespace std;

#define int long long

int bit[maxN][maxN], n, m;

inline void add ( int a, int b ){
    for ( int i = a ; i <= n ; i += i & -i )
        for ( int j = b ; j <= m ; j += j & -j )
            bit[i][j]++;
}

inline int sum ( int x, int y ){
	int res = 0;
	for ( int i = x ; i ; i -= i & -i )
		for ( int j = y ; j ; j -= j & -j )
			res += bit[i][j];

	return res;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int k, q, x1, x2, y1, y2;
	while ( cin >> n >> m >> k >> q ){
		memset ( bit, 0, sizeof bit );
		while ( k-- ){
			cin >> x1 >> y1;
			x1++, y1++;
			add ( x1, y1 );
		}
		while ( q-- ){
			cin >> x1 >> y1 >> x2 >> y2;
			x2++, y2++;
			cout << sum ( x2, y2 ) - sum ( x1, y2 ) - sum ( x2, y1 ) + sum ( x1, y1 ) << '\n';
		}
	}
}