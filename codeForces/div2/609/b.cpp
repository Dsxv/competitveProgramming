#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int* a , int* b , int n){
	for(int i = 0 ; i < n ; i++) if(a[i] != b[i]) return false ;
	return true ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] , b[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	sort(a,a+n) ;
	sort(b,b+n) ;
	int ans = INT_MAX ;
	for(int i = 0 ; i < n ; i++){
		int temp[n] ;
		for(int j = 0 ; j < n ; j++) temp[j] = a[j] ;
		int x = ( b[i]-a[0] + m ) % m ;
		for(int j = 0 ; j < n ; j++) temp[j] = (temp[j]+x)%m ;
		sort(temp,temp+n) ;
		if(check(temp,b,n)) {
			ans = min(ans,x) ;
		}
	}
	cout << ans ;
	return 0 ;
}

