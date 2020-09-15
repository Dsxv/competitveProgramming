#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t; 
	while(t--){
		string s; 
		cin >> s; 
		int n = s.size() ;
		int ok[n] = {} ;
		stack<int> st ;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '('){
				st.push(i) ;
			} else {
				if(st.size()){
					ok[st.top()] = i ;
					st.pop() ;
				}
			}
		}
		while(st.size()) {
			ok[st.top()] = n + 10 , st.pop() ;
		}
		int ans[n+1] ;
		memset(ans , -1 , sizeof(ans)) ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(ok[i]) ans[i] = ok[i] ;
			else ans[i] = ans[i+1] ;
		}
		int q ;
		cin >> q ;
		while(q--){
			int x ; cin >> x ; x-- ;
			if(~ans[x] && (ans[x] != (n+10))) cout << ans[x] + 1 << '\n' ;
			else cout << -1 << '\n' ;
		}
	}
	return 0 ;
}

