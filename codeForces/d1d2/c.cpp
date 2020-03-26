#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	if(n > m){
		cout << 0 ;
		return 0 ;
	}
	sort(a,a+n) ;
	int ans = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			ans = (ans*(a[j]-a[i])) % m ;
		}
	}
	cout << ans ;
	return 0 ;
}

