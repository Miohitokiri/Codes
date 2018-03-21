#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		if ( n % 3 == 0 ){
			cout << "yes";
		}
		else{
			cout << "no";
		}
		cout << endl;
	}
	return 0;
}
