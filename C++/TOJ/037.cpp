#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string in;
	int ans, stop;
	while ( getline ( cin, in ) ){
		// cout << ans << endl;// del
		stringstream data ( in );
		ans = 0;
		while ( data >> stop )
			ans++;
		cout << ans << endl;
	}
}