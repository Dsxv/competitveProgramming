#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k;
		vector<int> a(n) ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		vector<int> ans[2] ;
		for(int j = 0 ; j < 2 ; j++){
			int x = *max_element(a.begin() , a.end()) ;
			for(int i = 0 ; i < n ; i++){
				a[i] = x - a[i] ;
			}
			ans[(j+1)%2] = a ;
		}
		for(int i = 0 ; i < n ; i++){
			cout << ans[k%2][i] << " " ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

