#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	long long n;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		cout << "1x" << i << "= " << i;
		for ( int j = 2 ; j <= n ; j++ ){
			cout << "  " << j << 'x' << i << '=' << setw ( 2 ) << i * j;
		}
		cout << endl;
	}
}