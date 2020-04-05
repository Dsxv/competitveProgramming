#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int q , n; 
	cin >> n >> q ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n,greater<int>()) ;
	int k = 0 ;
	int arr[n+2] = {} ;
	while(q--){
		int l , r ;
		cin >> l >> r ;
		l-- , r-- ;
		arr[r+1]-- ;
		arr[l]++ ;
	}
	int ans[n] = {} ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += arr[i] ;
		ans[i] = sum ;
	}
	sort(ans,ans+n ,greater<int>()) ;
	int val = 0 ;
	for(int i = 0 ; i < n ; i++){
		val += a[i]*ans[i];
	}
	cout << val ;
	return 0 ;
}

