#include<bits/stdc++.h>
using namespace std;
int data[100005];
int main(){
	int n, m, l, r, type, ma;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> data[i];
	while ( m-- ){
		cin >> type >> l >> r;
		if ( type == 1 )
			data[l] = r;
		else{
			ma = -1;
			for ( int i = l ; i <= r ; i++ )
				ma = max ( ma, data[i] );
			cout << ma << '\n';
		}
	}
}