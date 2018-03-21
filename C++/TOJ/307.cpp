#include<bits/stdc++.h>
using namespace std;
int counter[30];
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string index, data;
	getline ( cin, index );
	cin >> data;
	for ( auto i: data )
		counter[i]++;

	for ( auto i: index ){
		if ( i == ' ' ){
			cout << ' ';
			continue;
		}

		if ( counter[i] > 0 ){
			counter[i]--;
			cout << i;
		}
		else
			break;
	}

	cout << '\n';
}