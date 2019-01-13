// dp
// stair
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int k;
	cin >> k;
	int data[k];
	data[0] = 1, data[1] = 2;
	for ( int i = 2 ; i < k ; i++ )
		data[i] = data[i - 1] + data[i - 2];

	cout << data[k - 1] << '\n';
}