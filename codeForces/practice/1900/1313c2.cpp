#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int a[n + 2] ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	stack<int> st ;
	int dpl[n + 2] = {} , dpr[n + 2] = {} ;
	int sl[n + 2] , sr[n + 2] ;
	for(int i = 1 ; i <= n ; i++){
		while(st.size() && a[i] < a[st.top()]){
			sr[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	while(st.size()){
		sr[st.top()] = n + 1 ;
		st.pop() ;
	}
	for(int i = n ; i >= 1 ; i--){
		while(st.size() && a[i] < a[st.top()]){
			sl[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	while(st.size()){
		sl[st.top()] = 0 ;
		st.pop() ;
	}
	for(int i = n ; i >= 1 ; i--){
		int x = sr[i] ;
		dpr[i] = dpr[x] + (x - i) * a[i] ;
	}
	for(int i = 1 ; i <= n ; i++){
		int x = sl[i] ;
		dpl[i] = dpl[x] + (i - x) * a[i] ;
	}
	int ai = 1 , mx = 0;
	for(int i = 1 ; i <= n ; i++){
		int val = dpl[i] + dpr[i] - a[i] ;
		if(val > mx){
			ai = i ;
			mx = val ;
		}
	}
	int cur = a[ai] ;
	for(int i = ai ; i <= n ; i++){
		cur = min(a[i] , cur) ;
		a[i] = cur ;
	}
	cur = a[ai] ;
	for(int i = ai ; i >= 1 ; i--){
		cur = min(a[i] , cur) ;
		a[i] = cur ;
	}
	for(int i = 1 ; i <= n ; i++) cout << a[i] << " " ;
	return 0 ;
}

