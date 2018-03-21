#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, stop, data1, data2, data3;
	cin >> n;
	for ( int times = 0 ; times < n ; times++ ){
		cin >> stop;
		data3 = 1;
		data1 = stop * 2 - 1;
		data2 = stop * 2 + 1;
		for ( data3 = 1 ; data3 < data1  - 6 ; data3 += 2 ){
			for ( int i = 0 ; i < round ( data2 / 2 ) ; i++ ){
				if ( i <= ( data2 - data3 ) / 2 )
					cout << ' ';
				else
					cout << '*';
			}
			cout << endl;
		}
		for ( int i = 0 ; i < data2 ; i++ )
			cout << '*';
		cout << endl << ' ';
		for ( int i = 0 ; i < data2 - 2 ; i++ )
			cout << '*';
		cout << endl;
		for ( int i = 0 ; i < data2 ; i++ )
			cout << '*';
		cout << endl;
		for ( data3 = data1 - 6 ; data3 > 0 ; data3 -= 2 ){
			for ( int i = 0 ; i < ( data2 - data3 ) / 2 ; i++ )
				cout << ' ';
			cout << '*' << endl;
		}	
	}
}
