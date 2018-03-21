#include<bits/stdc++.h>

using namespace std;

struct file{
	map < string, file* > dir;
	file *father;
} *root;

inline void print ( file *now ){
	if ( now )
		for ( auto i = now -> dir.begin() ; i != now -> dir.end() ; i++ )
			cout << i -> first << '\n';
}

inline void newFile ( file *now, string name ){
	now -> dir[name] = new file();
	now -> dir[name] -> father = now;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	root = new file();
	root -> father = root;
	file *now = root;
	string type, name, stop;
	char ch;
	int i;

	while ( cin >> type ){
		cin.get();
		name = "";
		if ( type != "ls" )
			while ( ( ch = cin.get() ) != '\n' )
				if ( ch != '\\' )
					name += ch;

		if ( type == "ls" )
			print ( now );
		else if ( type == "mkdir" || type == "touch" )
			newFile ( now, name );
		else{
			i = 0;

			if ( name[0] == '/' )
				now = root, i = 1;

			string stop;

			for ( ; i < name.size() ; i++ ){
				if ( name[i] == '\\' )
					continue;

				if ( name[i] != '/' )
					stop += name[i];

				if ( name[i] == '/' || i == name.size() - 1 ){
					if ( stop == ".." )
						now = now -> father;
					else if ( stop == "." )
						now = now;
					else
						now = now -> dir[stop];

					stop = "";
				}
			}
		}
	}
}