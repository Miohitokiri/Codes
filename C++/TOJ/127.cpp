#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	string d;
	cin >> d;
	// cout << d << endl;//del
	for ( int j = 0 ; j < t ; j++ ){
		for ( int i = 0 ; i < d.size() ; i++ ){
			d[i]--;
			if ( d[i] == '@' )
				d[i] = 'Z';
		}
		// cout << d << endl;
	}
	cout << d << endl;
}