#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		stack<int> st ;
		int ans[n] ;
		for(int i = n - 1 ; i >= 0 ; i--){
			while(st.size() && a[i] > a[st.top()]){
				ans[st.top()] = st.top() - i ;
				st.pop() ;
			}
			st.push(i) ;
		}
		while(st.size()){
			ans[st.top()] = st.top() + 1 ;
			st.pop() ;
		}
		for(auto i : ans) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

