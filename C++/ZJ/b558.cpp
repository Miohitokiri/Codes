#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	while ( cin >> n )
		cout << ( long long ) n * ( n - 1 ) / 2 + 1 << '\n';
}