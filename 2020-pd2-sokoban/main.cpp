// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;
typedef pair < int, int > pii;
#define F first
#define S second
#define push_back

char mp[maxN][maxN], idxmp[maxN][maxN];
vector < pii > boxes, indexex;

inline void initEasy ( int n, int m ){
	for ( int i = 0 ; i < maxN ; i++ )
		for ( int j = 0 ; j < maxN ; j++ )
			mp[i][j] = ' ';

	for ( int i = 0 ; i <= n + 1 ; i++ )
		mp[i][0] = mp[i][m + 1] = 'W';
	for ( int i = 0 ; i <= m ; i++ )
		mp[0][i] = mp[n + 1][i] = 'W';
}

inline vector < pii > getPosEasy ( int num, int n, int m ){
	set < pii > lib;
	vector < pii > res;
	int x = 0, y = 0;
	for ( int i = 0 ; i < num ; i++ ){
		x = rand() % n + 1, y = rand() % m + 1;
		while ( mp[x][y] != ' ' || lib.find ( pii ( x, y ) ) != lib.end() )
			x = rand() % n + 1, y = rand() % m + 1;
		lib.insert ( pii ( x, y ) );
		res.pb ( pii ( x, y ) );
	}

	return res;
}

inline bool findBox ( int X, int Y ){
	for ( auto [x, y]: boxes )
		if ( x == X && y == Y )
			return true;

	return false;
}

inline bool findIdx ( int X, int Y ){
	for ( auto [x, y]: indexes )
		if ( x == X && y == Y )
			return true;

	return false;
}

inline void move ( int &x, int &y, char op ){
	if ( op == 'w' )
		x--;
	if ( op == 'x' )
		x++;
	if ( op == 'a' )
		y--;
	if ( op == 'd' )
		y++;
}

inline void outputMp ( int x, int y ){
	for ( int i = 0 ; i <= n + 1 ; i++ ){
		for ( int j = 0 ; j <= m + 1 ; j++ ){
			if ( i == x && y == j )
				cout << 'S';
			else if ( mp[i][j] != ' ' )
				cout << mp[i][j];
			else
				cout << '.';
		}
		cout << '\n';
	}
}

int main(){
	srand ( time ( NULL ) + clock() + clock() * time ( NULL ) );
	int n, m, num = 3, x, y, swpX, swpY, px, py;
	char op;
	string type = "easy";

	cin >> n >> m;
	if ( type == "easy" ){
		initEasy ( n, m );
		boxes = getPosEasy ( num, n, m );
		for ( auto [X, Y]: boxes )
			mp[X][Y] = 'B';
		indexes = getPosEasy ( num, n, m );
		for ( auto [X, Y]: indexes )
			idxmp[X][Y] = 'I';
		x = rand() % n + 1, y = rand() % n + 1;
		while ( mp[x][y] != ' ' )
			x = rand() % n + 1, y = rand() % n + 1;
	}
	else if ( type == "mid" ){
	}
	else if ( type == "hard" ){
	}
	x = px, y = py;
	while ( true ){
		cin >> op;
	}
}