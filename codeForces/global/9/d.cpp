#include <bits/stdc++.h>
using namespace std ;

#define int long long

int get_mex(int* a , int n){
	int b[n+1] = {} ;
	for(int i = 0 ; i < n ; i++){
		b[a[i]]++ ;
	}
	for(int i = 0 ; i < n ; i++){
		if(!b[i]) return i;
	}
	return n; 
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n; 
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		vector<int> ans ;
		for(int i = 0 ; i < n ;){
			if(a[i] == i) {
				i++ ;
				continue ;
			}
			int x = get_mex(a,n) ;
			if(x == i){
				ans.push_back(i) ;
				a[i] = i ;
			} else {
				if(x == n) {
					a[i] = x ;
					ans.push_back(i) ;
				} else {
					a[x] = x ;
					ans.push_back(x) ;
				}
			}
		}
		cout << ans.size() << '\n' ;
		for(auto i : ans) cout << i + 1 << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

