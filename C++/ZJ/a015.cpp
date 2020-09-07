#include<iostream>
using namespace std;
int data[106][106];
int main(){
	long long r,c;
	while ( cin >> r >> c ){
		for ( int i = 0 ; i < r ; i++ ){
			for ( int j = 0 ; j < c ; j++ ){
				cin >> data[j][i];
			}
		}
		for ( int i = 0 ; i < c ; i++ ){
			for ( int j = 0 ; j < r ; j++ ){
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
