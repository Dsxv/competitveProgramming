#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int presum[201][n];
		for(int i = 0 ; i < 201 ; i++){
			for(int j = 0 ; j < n ; j++) presum[i][j] = 0 ;
		}
		
		for(int i = 0 ; i < n ; i++){
			if(i){
				for(int j = 1 ; j <= 200 ; j++){
					presum[j][i] = presum[j][i-1];
				}
			}
			presum[a[i]][i]++;
		}

		int ans = 1 ;
		for(int x = 1 ; x <= 200 ; x++){
			int i = 0 , j = n-1 ;
			while(i < j){
				while(i < j && a[i] != x) i++ ;
				while(i < j && a[j] != x) j-- ;
				if(i < j){
					int d = presum[x][i]*2 ;
					int val = 0 ;
					if(i+1 <= j-1){
						for(int h = 1 ; h <= 200 ; h++){
							val = max(val,presum[h][j-1] - presum[h][i]) ;
							// presum indexed from 1 cuz
						}
					}
					ans = max(ans,val+d) ;
					i++ , j-- ;
				}
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}
