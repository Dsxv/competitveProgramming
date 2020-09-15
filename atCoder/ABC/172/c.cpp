#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k;
	int a[n+1] = {} ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i+1] ;
	}
	int b[m+1] = {} ;
	for(int i = 0 ; i < m ; i++){
		cin >> b[i+1] ;
	}
	for(int i = 1 ; i < m ; i++){
		b[i] += b[i-1] ;
	}
	int sum = 0 ;
	int val = 0 ;
	for(int i = 0 ; i <= n ; i++){
		sum += a[i] ;
		int rem = k - sum ;
		if(rem < 0) break ;
		int lo = 1 , hi = m ;
		int ans = 0 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(b[mid] <= rem){
				ans = mid ;
				lo = mid + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		val = max(val , i + ans) ;
	}
	cout << val ; 
	return 0 ;
}

