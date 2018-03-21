#include<bits/stdc++.h>

using namespace std;

priority_queue < int > data[100005];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, q, type, x, v, l, r, ans, t;
	cin >> n >> q;
	while ( q-- ){
		cin >> type;
		if ( !type ){
			cin >> x >> v;
			data[x].push ( v );
		}
		else{
			ans = -1, t = -1;
			cin >> l >> r;
			if ( l > r )
				swap ( l, r );
			for ( int i = l ; i <= r ; i++ )
				if ( !data[i].empty() && data[i].top() >= ans ){
					t = i;
					ans = data[i].top();
				}
			if ( t != -1 ){
				ans = data[t].top();
				data[t].pop();
			}
			cout << ( ans == -1 ? -1 : ans ) << '\n';
		}
	}
}