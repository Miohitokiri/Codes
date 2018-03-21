#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, t, data[100];

	cin >> t;
	while ( t-- ){
		cin >> n;
		for ( int i = 1 ; i <= n + 1 ; i++ )
			cin >> data[i];

		for ( int i = n ; i > 0 ; i-- )
			for ( int j = 1 ; j <= i ; j++ )
				data[j] = data[j + 1] - data[j];

		cout << data[1] << '\n';
	}	
}
