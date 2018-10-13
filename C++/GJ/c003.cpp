#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	reverse ( a.begin(), a.end() );
	reverse ( b.begin(), b.end() );

	int i;
	for ( i = 0 ; i < 8 ; i++ ){
		if ( a[i] != b[i] )
			break;
	}

	if ( i == 3 )
		cout << 200;
	else if ( i == 4 )
		cout << 1000;
	else if ( i == 5 )
		cout << 4000;
	else if ( i == 6 )
		cout << 10000;
	else if ( i == 7 )
		cout << 40000;
	else if ( i == 8 )
		cout << 200000;
	else
		cout << 0;
	cout << '\n';
}