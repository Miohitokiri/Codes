#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	long long t, stop, ss;
	cin >> t;
	string data, find;
	for ( int times = 0 ; times < t ; times++ ){
		cin >> data >> stop;
		for ( int i = 0 ; i <= stop ; i++ ){
			cin >> find;
			bool test = false;
			for ( int j = 0 ; j < data.size() ; i++ )
				if ( data[i] == find[0] ){
					ss = i;
					break;
				}
			for ( int i = ss ; i < find.size() + ss ; i++ ){
				if ( data[i] == find[i - ss] )
					test = true;
				else{
					test = false;
					break;
				}
			}
			if ( test )
				cout <<'y';
			else
				cout << 'n';
			cout << endl;
		}
	}
}

void int dfs ( int i, int j ){
	
}