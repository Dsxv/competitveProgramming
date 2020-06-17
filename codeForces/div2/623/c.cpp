#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int mn = *min_element(a , a + n) ;
	int pre[n] = {} , suf[n] = {} ;
	int sum = accumulate(a,a+n,0LL) ;
	for(int i = 0 ; i < n ; i++){
		pre[i] = a[i] - mn ;
		if(i) pre[i] += pre[i-1] ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		suf[i] = a[i] - mn ;
		if(i < n - 1) suf[i] += suf[i+1] ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == mn){
			ans = max(ans , min(suf[i] , pre[i])) ;
		}
	}
	int id = -1 ;
	bool left = true  ;
	if(ans == 0){
		for(auto i : a) cout << i << " " ;
		return 0 ;
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] == mn && ans == min(suf[i] , pre[i])){
			id = i ;
			if(suf[i] > pre[i]) left = false ;
		}
	}
	// left means left chorro 
	if(left){
		for(int i = id + 1 ; i < n ; i++){
			a[i] = mn ;
		}
	} else {
		for(int i = id - 1 ; i >= 0 ; i--){
			a[i] = mn ;
		}
	}
	for(auto i : a) cout << i << " " ;

	return 0 ;
}

