#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , w ;
	cin >> n >> w ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	int val = 0 ;
	int len = n - 1 ;
	for(int i = 0 ; i < n ; i++){
		int lo = i + 1 , hi = len ;
		if(i == hi){
			val++ ;
			break ;
		}
		int ans = -1 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(a[mid] + a[i] <= w){
				lo = mid + 1 ;
				ans = mid ;
			} else {
				hi = mid - 1 ;
			}
		}
		if(ans == -1){
			val += len - i + 1;
			break ;
		}
		val += len - ans + 1 ;
		len = ans - 1 ;
	}
	cout << val ;
	return 0 ;
}

