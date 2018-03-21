#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n;
	string data[100];

	cin >> n;

	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];

	sort ( data, data + n );

	for ( int i = 0 ; i < n ; i++ )
		cout << data[i] << '\n';
}