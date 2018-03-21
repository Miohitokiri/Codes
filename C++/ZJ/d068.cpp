#include<iostream>
using namespace std;
int main(){
	long long a;
	while ( cin >> a ){
		if ( a > 50 ){
			cout << a - 1;
		}
		else{
			cout << a;
		}
		cout << endl;
	}
	return 0;
}
