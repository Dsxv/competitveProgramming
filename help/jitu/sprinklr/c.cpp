#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

struct q{
	int i , x ;
	q(){
		i = 0 , x = 0 ;
	}
	q(int i1 , int x1){
		i = i1 ;
		x = x1 ;
	}
} ;

int solve(vector<int>&ans , vector<q>* qsum , int* a , int n , int tp){
	for(int i = 1 ; i <= n ; i++){
		if(qsum[i].size()){
			int ca = (n/i)*qsum[i].size() ;
			if(ca > n){
				int dp[n] = {} ;
				for(int j = 0 ; j < n ; j++){
					dp[j] = tp ;
				}
				for(auto j : qsum[i]){
					dp[j.x] = a[j.x] ;
				}
				for(int j = n - 1 ; j >= 0 ; j--){
					if((j + i) <= n - 1){
						if(tp == 0) dp[j] = (dp[j] + dp[j+i]) % mod ;
						else dp[j] = (dp[j]*dp[j+i]) % mod ;
					}
				}
				for(auto j : qsum[i]){
					ans[j.i] = dp[j.x] ;
				}
			} else {
				for(auto j : qsum[i]){
					int val = tp ;
					for(int k = j.x ; k < n ; k += i) {
						if(tp == 0) val = (a[k] + val) % mod ;
						else val = (a[k]*val) % mod ; 
					}
					ans[j.i] = val ;
				}
			}
		}
	}
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		vector<q> qsum[n+1] ;
		vector<q> qmul[n+1] ;
		int qt ; cin >> qt ;
		vector<int> ans(qt) ;
		for(int i = 0 ; i < qt ; i++){
			int tp , x , y ;
			cin >> tp >> x >> y ;
			x-- ;
			q temp(i,x) ;
			if(!tp){
				qsum[y].push_back(temp) ;
			} else {
				qmul[y].push_back(temp) ;
			}
		}
		solve(ans , qsum , a  , n , 0) ;
		solve(ans , qmul , a , n , 1) ;
		for(auto i : ans) cout << i << '\n' ;
	}
	return 0 ;
}

