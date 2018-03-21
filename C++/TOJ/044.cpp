#include<bits/stdc++.h>
#define maxN 1005
#define x first
#define y second

using namespace std;

typedef pair < int, int > pii;

int n, m, x2, y2, w;
bool maze[maxN][maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int x, y;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ )
			cin >> maze[i][j];

	cin >> x >> y >> x2 >> y2;
	queue < pii > data;
	data.push ( pii ( x, y ) );
	pii dot;
	while ( !data.empty() ){
		dot = data.front();
		data.pop();
	}
}