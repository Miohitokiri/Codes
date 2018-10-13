#include<iostream>
#include<vector>

#define pb push_back

using namespace std;

int main(){
	int n, in, L = 0, R = 0;
	vector < int > l, r;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> in;
		if ( !L ){
			L += in + 10;
			l.pb ( i );
		}
		else if ( !R ){
			R += in + 10;
			r.pb ( i );
		}
		else if ( L <= R ){
			L += in + 10;
			l.pb ( i );
		}
		else{
			R += in + 10;
			r.pb ( i );
		}
	}

	for ( int i = 0 ; i < l.size() ; i++ )
		cout << l[i] << ' ';
	cout << L - 10 << '\n';
	for ( int i = 0 ; i < r.size() ; i++ )
		cout << r[i] << ' ';
	cout << R - 10 << '\n';
}