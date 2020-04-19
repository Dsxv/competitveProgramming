#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
vector<int> p[N] ;
int s[N] ;
int a[N];

void solve(int start , int tsum = 0){
	if(s[start] != -1){
		a[start] = s[start] - tsum ;
		if(p[start].size()) {
			for(auto i : p[start]) solve(i,s[start]) ;
		}
	} else {
		if(p[start].size() == 0) {
			a[start] = 0 ;
			return ;
		}
		int val = INT_MAX ;
		for(int i : p[start]) { 
			val = min(val , s[i]) ;
		}
		a[start] = val - tsum ;
		for(auto i : p[start]){
			solve(i,val) ;
		}
	}
}
	
	

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 1 ; i < n ; i++){
		int x ;
		cin >> x ;
		x-- ;
		p[x].push_back(i) ;
	}
	for(int i = 0 ; i < n ; i++) cin >> s[i] ;
	solve(0);
	for(int i = 0 ; i < n ; i++){
		if(a[i] < 0) {
			cout << -1 ;
			return 0 ;
		}
	}
	cout << accumulate(a,a+n,0LL) ;
	return 0 ;
}

