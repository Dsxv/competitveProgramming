#include <bits/stdc++.h>
using namespace std ;

int vis[1<<21] ;

int convertMask(string x){
	int ans = 0 ;
	for(auto i : x) ans |= 1 << ((i-'a') + 1) ;
	return ans ;
}

void solve(int mask , int val){
	if(vis[mask]) return ;
	vis[mask] = val ;
	for(int i = 0 ; i < 21 ; i++){
		if(mask&(1<<i)){
			solve(mask^(1<<i) , val) ;
		}
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		for(int i = 0 ; i < (1 << 21) ; i++) vis[i] = 0 ;
		vis[0] = 1 ;
		int n , k ;
		cin >> n >> k ;
		string s ; cin >> s ;
		for(int i = 0 ; i < k ; i++){
			string x ; cin >> x ;
			solve(convertMask(x) , i + 1) ;
		}
		int cur = 0 ;
		int ans[n] = {};
		for(int i = 0 ; i < n ; i++){
			int x = convertMask(string(1,s[i])) ;
			if(!vis[cur|x]){
				ans[i-1] = vis[cur] ;
				cur = x ;
			} else {
				cur |= x ;
			}
		}
		ans[n-1] = vis[cur] ;
		cur = 0 ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(ans[i]) cur = ans[i] ;
			ans[i] = cur ;
		}
		for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

