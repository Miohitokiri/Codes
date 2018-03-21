#include<iostream>
using namespace std;
int main(){
	long long a, b;
	cin >> a >> b;
	if ( a > b )
		for ( int i = a ; i >= b ; i-- ){
			for ( int j = 0 ; j < i ; j++ )
				cout << '*';
			cout << endl;
		}
	else
		for ( int i = a ; i <= b ; i++ ){
			for ( int j = 0 ; j < i ; j++ )
				cout << '*';
			cout << endl;
		}
}