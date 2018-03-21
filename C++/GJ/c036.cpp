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

	sort ( data.begin(), data.end() );

	cout << *( data.end() - 2 ) - data[1] << '\n';
}