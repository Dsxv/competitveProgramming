#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e4 + 10 ;
int dp[N][4] ;

int solve(int* v , int n , int i , int prev){
	if(i == n) return 0 ;
	if(~dp[i][prev]) return dp[i][prev] ;
	int val = INT_MAX ;
	
	if(v[i] == v[i-1]){
	    for(int j = 0 ; j < 4 ; j++){
	        if(j == prev) continue ;
	        val = min(val , solve(v , n , i + 1 , j) + 1) ;
	    }
	    val = min(val , solve(v , n , i + 1 , prev)) ;
	    return dp[i][prev] = val ;
	}
	if(v[i] > v[i-1]){
		for(int j = 0 ; j <= prev ; j++){
			val = min(val , solve(v , n , i + 1 , j) + 1) ;
		}
		for(int j = prev + 1 ; j < 4 ; j++){
			val = min(val , solve(v , n , i + 1 , j)) ;
		}
		return dp[i][prev] = val ;
	} else {
		for(int j = 0 ; j < prev ; j++){
			val = min(val , solve(v , n , i + 1 , j)) ;
		}
		for(int j = prev ; j < 4 ; j++){
			val = min(val , solve(v , n , i + 1 , j) + 1) ;
		}
		return dp[i][prev] = val ;
	}
}

void gogogo(){
	memset(dp , -1 , sizeof(dp)) ;
	int n; 
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	} 
	int mn = INT_MAX ;
	for(int i = 0 ; i < 4 ; i++){
		mn = min(mn , solve(a,n,1,i)) ;
	}
	cout << mn << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}



