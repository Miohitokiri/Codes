#include<bits/stdc++.h>

using namespace std;

map < string, string > dir;

void Init(){
	dir.clear();
}

void InsertWord ( string a, string b ){
	dir[a] = b;
}

string Ask ( string a ) {	
	if ( dir.find ( a ) != dir.end() )
		return dir.find ( a ) -> second;
	return "Not found!";
}