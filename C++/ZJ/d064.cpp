#include<iostream>
using namespace std;
int main(){
	long long i;
	while ( cin >> i ){
		if ( i % 2 == 0 ){
			cout << "Even";
		}
		else if ( i % 2 == 1 ){
			cout << "Odd";
		}
		cout << endl;
	}
	return 0;
}
