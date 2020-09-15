#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(vector<pair<int,int>>& p , vector<int>& a, int n){
	stack<int> s ;
	for(int i = 0 ; i < n ; i++){
		while(s.size() && a[i] > a[s.top()]){
			p[s.top()].first = a[i];
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].first = a.back() ;
		s.pop() ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		while(s.size() && a[i] > a[s.top()]){
			p[s.top()].second = a[i];
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].second = a.back() ;
		s.pop() ;
	}
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int temp[n] ;
		vector<int> a ;
		for(int i = 0 ; i < n ; i++) cin >> temp[i] ;
		int mx = *max_element(temp , temp+n) ;
		a.push_back(mx) ;
		a.push_back(temp[0]) ;
		for(int i = 1 ; i < n ; i++){
			if(a.back() == temp[i]) continue ;
			a.push_back(temp[i]) ;
		}
		a.push_back(mx) ;
		vector<pair<int,int>> p(a.size()) ;
		solve(p , a , a.size()) ;
		vector<int> v(a.size()) ;
		stack<int> st ;
		for(int i = a.size() - 1 ; i >= 1 ; i--){
			while(st.size() && a[i] >= a[st.top()]){
				v[st.top()] = a[i] ;
				st.pop() ;
			} st.push(i) ;
		}
		while(st.size()) {
			v[st.top()] = mx ; st.pop() ;
		}

		int ans = 0 ;
		int cmax = 0 ;
		for(int i = 1 ; i < a.size() - 1 ; i++){
			if(cmax < a[i]) {
				cmax = max(a[i] , cmax) ;
				continue ;
			}
			if(v[i] == a[i]) continue ;
			ans += min(p[i].first , p[i].second) - a[i] ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

