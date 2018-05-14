#include<iostream>
#include<string>
using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	string s1,s2;
	int n,k,x=0,a[32]={0};
	cin >> s1 >> s2 >> n >> k;
	a[1]=s1.size();
	a[2]=s2.size();
	for(int i=3;i<32&&i<=n;i++){
		a[i]=a[i-1]+a[i-2];
		if(a[i]>=k){
			x=i;
			break;
		}
	}
	for(int i=x;i>2;i=x){
		if(k>a[i-1]){
			k-=a[i-1];
			x-=2;
		}
		else{
			break;
		}
	}
	if(n<3){
		x=n;
	}
	if(x==0){
		printf("X\n");
	}
	else{
		switch(x){
			case 1:
				if(k>a[1]){
					printf("X\n");
				}
				else{
					printf("%c\n",s1[k-1]);
				}
				break;
			case 2:
				if(k>a[2]){
					printf("X\n");
				}
				else{
					printf("%c\n",s2[k-1]);
				}
				break;
			default:
				for(int i=3;i<=x;i++){
					s1=s2+s1;
					swap(s1,s2);
				}
				printf("%c\n",s2[k-1]);
		}
	}
	return 0;
}