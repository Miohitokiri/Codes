#include<bits/stdc++.h>

using namespace std;

int n, m, a, b;
int x[150];

int main(){
	cin >> n >> m;
	while ( n-- ){
		cin >> a >> b;
		for ( int i = a ; i < b ; i++ )
			x[i] = 1;
	}
	for ( int i = 0 ; i < m ; i++ )
		if ( !x[i] ){
			cout << "NO\n";
			// return 0;
		}
	cout << "YES\n";
	for ( int i = 0 ; i <= m ; i++ )
		cout << x[i] << ' ';
	cout << '\n';
}