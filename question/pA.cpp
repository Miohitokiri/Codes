#include<bits/stdc++.h>

using namespace std;

#define int long long

int cnt;
inline void func ( int i ){
	cnt++;
	if ( i == 1 )
		return;
	if ( i % 2 )
		func ( i * 3 + 1 );
	else
		func ( i / 2 );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int l, r, ma, a, b;
	while ( cin >> l >> r ){
		a = l, b = r;
		ma = 0;
		if ( l > r )
			swap ( l, r );
		for ( int i = l ; i <= r ; i++ ){
			cnt = 0;
			func ( i );
			ma = max ( ma, cnt );
		}

		cout << a << ' ' << b << ' ' << ma << '\n';
	}
}