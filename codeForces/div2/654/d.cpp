#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n , k ;
		cin >> n >> k ;
		vector<vector<int>> a(n,vector<int>(n,1)) ;
		int cnt = n*n - k ;
		for(int l = 0 ; l < n ; l++){
			int i = l , j = 0  ;
			if(!cnt) break ;
			int x = n ;
			while(x--){
				if(i >= n) i = 0 ;
				if(j >= n) j = 0 ;
				a[i][j] = 0 ;
				cnt-- ;
				i++ , j++ ;
				if(!cnt) break ;
			}
		}
		int mxi = INT_MIN , mni = INT_MAX ;
		int mxj = INT_MIN , mnj = INT_MAX ;
		for(int i = 0 ; i < n ; i++){
			int c = 0 , b = 0 ;
			for(int j = 0 ; j < n ; j++){
				b += a[i][j] ;
				c += a[j][i] ;
			}
			mxi = max(b,mxi) ; mni = min(b,mni) ;
			mxj = max(c,mxj) ; mnj = min(c,mnj) ;
		}
		mxi -= mni ;
		mxj -= mnj ;
		cout << mxi*mxi + mxj*mxj << '\n' ;
		for(auto i : a){
			for(auto j : i) cout << j ;
			cout << '\n' ;
		}
	}
	return 0 ;
}

