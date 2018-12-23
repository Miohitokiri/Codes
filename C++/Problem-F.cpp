#include<bits/stdc++.h>
#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxq=61095;
inline int query(int x){
	printf("%d\n",x);
	fflush(stdout);
	int q;
	scanf("%d",&q);
	return q;
}
int ans[3010];
vector<int> st;
vector<int> cur_st;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int q1=maxq,q2=n,q3=m*floor(log2(2*n));
	int limt=min(q1,min(q2,q3));
	if(limt==q1){
		int block_size=(n+3000-1)/3000;
		for(int i=1;i<=n;i+=block_size){
			st.push_back(i);
			cur_st.push_back(i);
		}
		int idx=0;
		for(int i=m;i>=0 && idx<(int)st.size();i--){
			int cur=cur_st[idx],l=cur;
			int q=query(cur);
			if(q!=i){
				i=q+1;
				continue;
			}
			if(i==0){
				ans[i]=n-cur+1;
				break;
			}
			while(idx+1<(int)st.size() && query(st[idx+1])==i)
				l=st[++idx];
			int r;
			if(idx+1==(int)st.size()) r=n+1;
			else r=st[idx+1];
			int edge=r;
			while(r-l>1){
				int mid=(l+r)>>1;
				if(query(mid)!=i) r=mid;
				else l=mid;
			}
			if(l+1==edge) idx++;
			else cur_st[idx]=l+1;
			ans[i]=l-cur+1;
		}
	}else if(limt==q2){
		for(int i=1;i<=n;i++)
			ans[query(i)]++;
	}else{
		int cur=1;
		while(cur<=n){
			int l=cur,r=n+1,num=query(cur);
			if(num==0){
				ans[num]=n-cur+1;
				break;
			}
			while(r-l>1){
				int mid=(l+r)>>1;
				if(query(mid)!=num) r=mid;
				else l=mid;
			}
			ans[num]=l-cur+1;
			cur=l+1;
		}
	}
	puts("0");
	for(int i=0;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}