// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define max N 100005

int pre[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, l, r;
	cin >> n >> m;
	for ( int i = 1 ; i < n ; i++ ){
		cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	while ( m-- ){
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}
}