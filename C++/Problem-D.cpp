#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll s[5010],p[5010];
int main(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",s+i);
	for(int i=1;i<=n;i++)
		scanf("%lld",p+i);
	ll ans=1ll<<62;
	for(int i=1;i<=n;i++){
		if(s[i]==k) ans=min(ans,0ll);
		if(s[i]>k) ans=min(ans,p[i]);
		else{
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(s[i]+s[j]==k) ans=min(ans,0ll);
				else if(s[i]+s[j]>k) ans=min(ans,min(p[i],p[j]));
			}
		}
	}
	if(ans==1ll<<62) ans=-1;
	printf("%lld\n",ans);
	return 0;
}