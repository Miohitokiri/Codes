#include<bits/stdc++.h>

using namespace std;

int data[100];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );


	int n;
	while ( cin >> n ){
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];

		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0 ; j < n ; j++ ){
				data[j] = data[j + 1] - data[j];
			}
		}

		cout << data[0] << '\n';
	}
}