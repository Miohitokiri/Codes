#include<bits/stdc++.h>

using namespace std;

struct node{
	node *father;
	map < string, node * > lib;
	set < string > dir;
} *root;

inline void newFile ( node *now, string name ){
	now -> lib[name] = new node();
	now -> lib[name] -> father = now;
	now -> dir.insert ( name );
}

inline void print ( node *now, int dep){
	for ( auto i = now -> lib.begin() ; i != now -> lib.end() ; i++ ){
		for ( int j = 0 ; j < dep ; j++ )
			cout << ' ';
		cout << i -> first << '\n';
		print ( i -> second, dep + 1 );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	string str, file;
	root = new node();
	root -> father = root;
	node *now;
	cin >> n;
	n++;
	while ( n-- ){
		getline ( cin, str );
		file = "";
		now = root;
		for ( auto i: str ){
			if ( i == '/' ){
				if ( !file.size() || file == "." ){
					file = "";
					continue;
				}
				if ( file == ".." )
					now = now -> father;
				else{
					if ( now -> dir.find ( file ) == now -> dir.end() ){
						newFile ( now, file );
					}
					now = now -> lib[file];
				}
				file = "";
			}
			else
				file += i;
		}

		if ( !file.size() || file == "." )
				continue;
			if ( file == ".." )
				now = now -> father;
			else{
				if ( now -> dir.find ( file ) == now -> dir.end() ){
					newFile ( now, file );
				}
				now = now -> lib[file];
			}
			file = "";
	}

	print ( root, 0 );
}