#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , int* a , int n , int k){
	int sum = 0 ;
	int reg = 1 ;
	for(int i = 0 ; i < n ; i++){
		if(sum + a[i] > x){ // this is break point // not region
			sum = 0 ;
			reg++ ;
		}
		sum += a[i] ;
	}
	return reg <= k;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int sum = accumulate(a,a+n,0LL) ;
	int lo = *max_element(a,a+n) , hi = sum ;
	int ans = -1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid , a , n , k)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

