#include<iostream>
using namespace std;
int main(){
	int n;
	while ( cin >> n ){
		if ( n <= 10 ){
			cout << n * 6 ;
		}
		else if ( n > 10 && n <= 20 ){
			cout << 60 + ( n - 10 ) * 2;
		}
		else if ( n > 20 && n <= 40 ){
			cout << 80 + n - 20;
		}
		else{
			cout << 100;
		}
		cout << endl;
	}
	return 0;
}
