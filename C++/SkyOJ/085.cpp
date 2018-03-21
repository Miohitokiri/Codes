#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bitBasicData[1000005], bitLazyTag[1000005];
int n;

inline void add ( ll *b, ll i, ll value ){
	while ( i <= n ){
		b[i] += value;
		i += i & -i;
	}
}

inline ll sum ( ll *b, ll i ){
	ll re = 0;

	while ( i ){
		re += b[i];
		i -= i & -i;
	}

	return re;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	ll q, stop, type, l, r, x;
	ll ans;

	cin >> n;
	for ( ll i = 1 ; i <= n ; i++ ){
		cin >> stop;
		add ( bitBasicData, i, stop );
	}

	cin >> q;
	while ( q-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> l >> r >> x;
			add ( bitBasicData, l, -x * ( l - 1 ) );
			add ( bitLazyTag, l, x );
			add ( bitBasicData, r + 1, x * r );
			add ( bitLazyTag, r + 1, -x );
		}
		else{
			cin >> l >> r;
			ans = 0, l--;
			ans += sum ( bitBasicData, r ) + sum ( bitLazyTag, r ) * r;
			ans -= sum ( bitBasicData, l ) + sum ( bitLazyTag, l ) * l;

			cout << ans << '\n';
		}
	}
}