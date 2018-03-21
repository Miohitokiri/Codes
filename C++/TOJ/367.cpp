#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, m, ma, stop;

	while ( cin >> n >> m ){
		ma = 0;
		while ( n-- )
			for ( int i = 0 ; i < m ; i++ ){
				cin >> stop;
				ma = max ( ma, stop );
			}

		cout << ma << ".000000\n";
	}
}