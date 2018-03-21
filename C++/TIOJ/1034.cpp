#include<bits/stdc++.h>
#define maxN 25

using namespace std;

int data[maxN][maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, q;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ )
			cin >> data[i][j];
}