#include<bits/stdc++.h>
#define type first
#define value second

using namespace std;

typedef pair < char, int > pci;

vector < pci > data, sor, ansData;

inline int count ( int p, char t, int num ){
	if ( t == '|' )
		p |= num;
	else if ( t == '&' )
		p &= num;
	else
		p ^= num;

	return p;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, num, res = 0, pst;
	char t;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> t >> num;
		data.push_back ( make_pair ( t, num ) );
	}

	res = count ( 0, data[0].type, data[0].value );
	for ( int i = 1 ; i < n ; i++ )
		if ( data[i].type == data[i - 1].type )
			res = count ( res, data[i].type, data[i].value );
		else{
			sor.push_back ( make_pair ( data[i - 1].type, res ) );
			res = count ( 0, data[i].type, data[i].value );
		}

	res = 0;
	for ( auto i: sor ){
		pst = res;
		res = count ( res, i.type, i.value );
		if ( pst != res )
			ansData.push_back ( i );
	}

	cout << ansData.size() << '\n';
	for ( auto i: ansData )
		cout << i.type << ' ' << i.value << '\n';

	for ( auto i: sor )
		cout << i.first << ' ' << i.second << '\n';
}