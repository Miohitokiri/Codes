#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, max, maxData;
	while ( cin >> n ){
		max = 0;
		int data[n];
		for ( int i = 0 ; i < n ; i++ ){
			cin >> data[i];
			if ( max < data[i] ){
				max = data[i];
				maxData = i;
			}
		}if ( max != 1){
			data[maxData] = 1;
			sort ( data, data + n );
		}
		else
			data[n - 1] = 2;
		cout << data[0];
		for ( int i = 1 ; i < n ; i++ )
			cout << ' ' << data[i];
		cout << endl;
	}
}