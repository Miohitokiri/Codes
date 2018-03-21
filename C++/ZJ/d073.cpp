#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		long long a = n % 3;
		if ( a % 3 == 0 ){
			cout << n / 3;
		}
		else{
			cout << n / 3 + 1;
		}
		cout << endl;
	}
	return 0;
}
