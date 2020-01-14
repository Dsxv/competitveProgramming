#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int k , string s){
	for(char ch = 'a' ; ch <= 'z' ; ch++){
		vector<int> v ; v.push_back(-1) ;
		for(int i = 0 ; i < s.size() ; i++){
			if(ch == s[i]) v.push_back(i) ;
		} v.push_back(s.size()) ;
		int mx = -1;
		int l = v.size() ;
		for(int i = 0 ; i < l - 1 ; i++){
			mx = max(mx,v[i+1] - v[i]) ;
		}
		if(mx <= k) return true ;
	}
	return false ;
}
		

int32_t main(){
	string s;
	cin >> s ;
	int n = s.size() ;
	int lo = 1 , hi = n ;
	int ans = -1;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,s)){
			ans = mid ;
			hi = mid - 1 ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}
