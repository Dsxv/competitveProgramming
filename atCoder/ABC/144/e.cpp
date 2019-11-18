#include <bits/stdc++.h>
using namespace std ;
#define int long long

int n ;

bool check(int mid , int* a , int* f , int k){
	for(int i = 0 ; i < n ; i++){
		if(a[i]*f[i] > mid){
			k -= a[i] - mid/f[i] ;
		}
		if(k < 0) return false ;
	}
	return true ;
}

int bs(int* a , int* f , int k ){
	int l = 0 , r = a[0]*f[n-1] ;
	int mid ;
	int ans = r ;
	while(l <= r ) {
		mid = (l+r)/2 ;
		if(check(mid,a,f,k)){
			ans = mid ;
			r = mid - 1 ;
		}else{
			l = mid + 1;
		}
	}
	return ans ;
}

int32_t main(){
	int k ;
	cin >> n >> k ;
	int a[n] , f[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> f[i] ;
	sort(a,a+n,greater<int>()) ;
	sort(f,f+n) ;
	cout << bs(a,f,k) ;
	return 0 ;
}
