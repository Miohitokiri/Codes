#include<iostream>
using namespace std;
int main(){
	int data;
	while ( cin >> data ){
		data -= 15;
		if ( data > 0 ){
			cout << data;
		}
		else if ( data == 0 ){
			cout << data;
		}
		else{
			cout << data + 24;
		}
		cout << endl;
	}
	return 0;
}
