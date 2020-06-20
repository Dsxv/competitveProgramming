#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int ans[n] ;
	stack<int> s ;
	for(int i = n - 1 ; i >= 0 ; i--){
		while(s.size() && a[i] < a[s.top()]){
			a[s.top()] = i ;
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		a[s.top()] = -1 ;
		s.pop() ;
	}
	for(auto i : a) cout << i + 1 << " " ;
	return 0 ;
}

