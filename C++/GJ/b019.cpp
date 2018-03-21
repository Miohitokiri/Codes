#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, stop, data[100];

	cin >> n;

	for ( int times = 0 ; times < n ; times++ )
		cin >> data[times];

	sort ( data, data + n );

	cout << data[n - 1];
	for ( int i = n - 2 ; i >= 0 ; i-- ){
		cout << ' ' << data[i];
	}
	cout << '\n';
}