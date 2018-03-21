#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, k;
	while ( cin >> n >> k ){
		int data[n];
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];
		sort ( data, data + n );
		cout << data[n - 2] << endl;
	}
}