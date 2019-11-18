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
	sort(a,a+n,greater<int>()) ;
	for(int i = n ; i  >=  1 ; i--){
		if(a[i-1] >= i){
			cout << i << '\n' ; break ;
		}
	}
	}
	return 0 ;
}

