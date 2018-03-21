#include<iostream>
using namespace std;
int main(){
	string data[500];
	bool ans;
	getline ( cin,data[0] );
	if ( data[0] != "EOF" && data[0] != "eof" ){
		cout << "NO" << endl;
		for ( int i = 1 ; i < 500 ; i++ ){
			getline ( cin,data[i] );
			ans = true;
			if ( data[i] != "EOF" ){
				for ( int j = 0 ; j < i ; j++ ){
					if ( data[i] == data[j] ){
						ans = false;
						break;
					}
				}
				if ( ans == true ){
					cout << "NO";
				}
				else if ( ans == false ){
					cout << "YES";
				}
				cout << endl;
			}
			else{
				break;
			}
		}
	}
	return 0;
}
