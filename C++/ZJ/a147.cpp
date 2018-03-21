#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		if ( n == 0 )
			break;
		else
			for ( int i = 0 ; i < n ; i++ ){
				if ( i % 7 != 0 )
					cout << i << " ";
			}
			cout << endl;
	}
	return 0;
}