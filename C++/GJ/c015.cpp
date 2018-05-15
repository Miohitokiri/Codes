#include<iostream>
#include<vector>
#include<set>

using namespace std;

#define pb push_back

int main(){
	int in;
	vector < int > data;
	set < int > used;
	for ( int i = 0 ; i < 4 ; i++ ){
		cin >> in;
		data.pb ( in );
		used.insert ( in );
	}
	sort ( data.begin(), data.end() );

	if ( used.size() == 1 )
		cout << "1000\n";
	else if ( used.size() == 4 )
		cout << "0\n";
	else if ( used.size() == 3 )
		cout << "10\n";
	else if ( ( data[0] == data[1] && data[1] == data[2] ) || ( data[1] == data[2] && data[2] == data[3] ) )
		cout << "100\n";
	else
		cout << "50\n";
}