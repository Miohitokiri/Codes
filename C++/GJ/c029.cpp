#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	vector < int > data;
	cin >> n;
	while ( n-- ){
		cin >> stop;
		data.push_back ( stop );
	}

	cin >> n;
	while ( n-- ){
		cin >> stop;
		data.push_back ( stop );
	}

	sort ( data.begin(), data.end() );

	for ( int i = 0 ; i < data.size() ; i++ )
		cout << data[i] << ' ';
	cout << '\n';
}