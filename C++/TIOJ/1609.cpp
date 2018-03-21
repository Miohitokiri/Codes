#include<bits/stdc++.h>

using namespace std;

int data[1000005];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];

	sort ( data, data + n );

	cout << data[0];
	for ( int i = 1 ; i < n ; i++ )
		cout << ' ' << data[i];
	cout << '\n';
}