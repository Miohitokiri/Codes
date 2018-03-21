#include<iostream>
using namespace std;
void f(int a){
        for(int i=0;i<a;i++){
                for(int j=a-i-1;j>0;j--) cout<<' ';
                for(int k=0;k<2*i+1;k++) cout<<'*';
                cout<<endl;
        }
}
void g(int a){
        for(int i=0;i<a;i++){
                for(int j=0;j<i+1;j++){
                        for(int k=a-j-1;k>0;k--) cout<<' ';
                        for(int l=0;l<2*j+1;l++) cout<<'*';
                        cout<<endl;
                }
        }
}
void h(int a){
        for(int m=0;m<a;m++){
                for(int n=a+1-m;n>0;n--) cout<<' ';
                for(int o=0;o<2*m+1;o++) cout<<'*';
                cout<<endl;
        }
        for(int p=0;p<2*(a+2)-1;p++) cout<<'#';
        cout<<endl;
}
int main(){
        int a,c[30];
        char b[30];
        while(cin>>a){
                for(int i=0;i<a;i++){
                        char b1;
                        int c1;
                        cin>>b1>>c1;
                        b[i]=b1;
                        c[i]=c1;
                }
                for(int j=0;j<a;j++){
                        if(b[j]=='A'){
                                f(c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='B'){
                                for(int q=0;q<2;q++)
                                        f(c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='C'){
                                g(c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='D'){
                                f(10*c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='E'){
                                h(c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='F'){
                                f(2*c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='G'){
                                f(3*c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='H')
                        {
                                f(7*c[j]);
                                cout<<endl;
                        }
                        else if(b[j]=='I')
                        {
                                f(4*c[j]-1);
                                cout<<endl;
                        }
                }
                
        }
        return 0;
}