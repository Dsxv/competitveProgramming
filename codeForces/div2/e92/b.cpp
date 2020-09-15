#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k , z;
		cin >> n >> k >> z;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int pre[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			if(i) pre[i] = pre[i-1] ;
			pre[i] += a[i] ;
		}
		int sum = pre[k] ;
		for(int i = 1 ; i < k ; i++){
			int rem_back = min(k - i, z) ;
			int cur = pre[i] ;
			int st = i;
			for(int j = 0 , dx = -1 ; j < rem_back ; j++){
				st += dx ;
				cur += a[st] ;
				dx *= -1 ;
			}
			int rstep = k - i - rem_back ;
			if(rstep > 0){
				cur += pre[st + rstep] - pre[st] ;
			}
			sum = max(sum , cur) ;
		}
		cout << sum << '\n' ;
	}
	return 0 ;
}

