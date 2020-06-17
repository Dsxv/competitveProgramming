#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int p[n] ;
	for(int i = 0 ; i < n ;i++) cin >> p[i] ;
	int sum = accumulate(p,p+n,0LL) ;
	int mn = INT_MAX ;
	// 01011
	for(int i = 0 ; i < (1LL<<n) ; i++){
		int csum = 0 ;
		for(int j = 0 ; j < n ; j++){
			if((1LL<<j)&i){
				csum += p[j] ;
			}
		}
		mn = min(abs(sum - 2*csum) , mn) ;
	}
	cout << mn ;
	return 0 ;
}

