#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long a, b, c;
	while(cin >> a >> b >> c){
		if( b*b >= 4*a*c ){
				long long x1=( -b + pow(( b*b -4*a*c ) , 0.5 ))/2*a,x2=( -b - pow(( b*b -4*a*c ) , 0.5 ))/2*a;
				if( b*b > a*4*c ){
					if( x1 >x2 )
						cout<<"Two different roots x1="<<x1<<" , x2="<<x2;
					
					else if( x2 > x1 )
						cout<<"Two different roots x1="<<x2<<" , x2="<<x1;
				}
				else if( b*b >= 4*a*c ){
					if( x1 == -4 )
						cout<<"Two same roots x=-1";
					else
						cout<<"Two same roots x="<<x1;
				}
		}
		else
			cout<<"No real root";
		cout<<endl;
	}
	return 0;
}