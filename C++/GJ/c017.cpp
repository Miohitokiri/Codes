#include<iostream>
#include<set>
#include<vector>

using namespace std;

int data[105];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, k;
	set < int > used;
	vector < int > lib;
	cin >> n >> k;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> data[i];
		lib.push_back ( data[i] );
	}

	sort ( lib.begin(), lib.end() );
	reverse ( lib.begin(), lib.end() );
	k--;
	for ( int i = 0 ; i < n ; i++ ){
		if ( lib[i] == data[k] ){
			cout << i + 1 << '\n';
			return 0;
		}
	}
}