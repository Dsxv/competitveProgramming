#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int mn = INT_MAX , sum = 0 ;
		int neg = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int x ; cin >> x ;
				if(x < 0) neg++ ;
				x = abs(x) ;
				mn = min(mn , x) ;
				sum += x ;
			}
		}
		if(neg % 2 == 0) cout << sum << '\n' ;
		else cout << sum - 2*mn << '\n' ;
	}
	return 0 ;
}

