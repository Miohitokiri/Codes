#include<iostream>
#include<string>
#include<vector>

using namespace std;

inline cmp ( string a, string b ){
	if ( a.size() == b.size() )
		return a > b;
}

string data[3];
inline void strSort ( void ){
	for ( int i = 0 ; i < 3 ; i++ )
		for ( int j = 0 ; j < i ; j++ )
			if ( data[i] > data[j] )
				swap ( data[i], data[j] );
}

int main(){
	cin >> data[0] >> data[1] >> data[2];

	strSort();

	cout << data[0] << data[1] << data[2] << '\n';
}