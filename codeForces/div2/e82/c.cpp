#include <bits/stdc++.h>
using namespace std ;

#define int long long

void nope(){
	cout << "NO\n" ;
}

void solve(){
		string s ;
		cin >> s ;
		set<char> mp[26] ;
		int n = s.size() ;
		for(int i = 0 ;  i < n ; i++){
			if(i > 0) mp[s[i]-'a'].insert(s[i-1]) ;
			if(i < n-1) mp[s[i]-'a'].insert(s[i+1]) ;
		}
		int candid = -1  , mx = 0;
		for(int i = 0 ; i < 26 ; i++){
			if(mp[i].size() == 1){
				candid = i ;
			}
			mx = max(mx,(int)mp[i].size()) ;
		}
		if((candid == -1 || mx > 2) && mx) {
			nope() ; return ; 
		}
		if(mx == 0) candid = 0 ; 
		string ans(26,'0') ;
		set<int> rem ;
		for(int i = 0 ; i < 26 ; i++) rem.insert(i) ;
		queue<int> q;
		q.push(candid) ;
		int vis[26] = {0} ; vis[candid] = 1 ;
		int count = 0 ;
		while(q.size()){
			int tp = q.front() ; q.pop() ;
			ans[count++] = (char)(tp + 'a');
			rem.erase(tp) ;
			int cntt = 0 ;
			for(auto i : mp[tp]){
				if(!vis[i-'a']){
					cntt++ ;
					q.push(i-'a') ;
					vis[i-'a'] = 1 ;
				}
			}
			assert(cntt <= 1) ;
		}
		for(auto i : rem){
			ans[count++] = (char)(i+'a') ;
		}
		cout << "YES\n" ;
		cout << ans << endl ;
}
				

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		solve() ;
	}
}
