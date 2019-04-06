#include<bits/stdc++.h>

using namespace std;

vector < string > data[15];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	while ( cin >> str ){
		data[str.size()].push_back ( str );
	}

	for ( int i = 1 ; i <= 10 ; i++ ){
		cout << i << ' ' << "Word " << data[i].size();
		if ( data[i].empty() ){
			cout << '\n';
		}
		else{
			cout << " (" << data[i][0];
			for ( int j = 1 ; j < data[i].size() ; j++ ){
				cout << ',' << data[i][j];
			}
			cout << ")\n";
		}
	}
}