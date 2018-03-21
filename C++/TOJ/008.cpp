#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, s;
	string in;
	while ( cin >> n ){
		cin.get();
		queue < char > data[256];
		s = 0;
		getline ( cin, in );
		while ( s < in.size() )
			for ( int i = 0 ; i < n ; i++ ){
				data[i].push ( in[s] );
				s++;
			}

		for ( int i = 0 ; i < n ; i++ )
			while ( !data[i].empty() ){
				cout << data[i].front();
				data[i].pop();
			}

		cout << '\n';
	}
}