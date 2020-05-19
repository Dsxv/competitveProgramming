#include <bits/stdc++.h>
using namespace std ;

#define int long long

int ff(int cur , int t, int s = 0 , int p = -1){
	if(cur == t) return p+s ;
	if(t > cur/2){
		if(t == cur-1) return cur+s;
		return ff(cur/2,t-cur/2,s+cur/2,cur) ;
	} else {
		return ff(cur/2,t,s,cur) ;
	}
}

vector<int> solve(int h , vector<int>& a){
	vector<int> ans ;
	for(auto i : a) ans.push_back(ff((1LL<<h) - 1 , i)) ;
	return ans ;
}

int32_t main(){
	int h , n ;
	cin >> h >> n ;
	//cout << ff((1LL<<h)-1,n) ;
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vector<int> ans = solve(h,a) ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

