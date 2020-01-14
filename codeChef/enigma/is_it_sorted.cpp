#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 10 ;
const int mod = 1e9 + 7 ;
int dp[N][N] ;
int n , k ;

int solve(int* a , int i = 0 , int j = 0){
	if(i == n){
		return j == k;
	}
	if(j > k) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	dp[i][j] = (solve(a,i+1,j) + solve(a,i+1,j+1)) % mod ;
	return dp[i][j] ;
}

int l[N][N] ; 

int modexp(int a,  int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int initialize() { 
  
    l[0][0] = 1; 
    for (int i = 1; i < N; i++) { 
        l[i][0] = 1; 
        for (int j = 1; j < i + 1; j++) { 
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % mod; 
        } 
    } 
} 

int32_t main(){
	cin >> n >> k ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= k ; j++) dp[i][j] = -1 ;
	}
	int a[n] ;
	for(int i = 0; i < n ; i++){
		cin >> a[i] ;
	}
	initialize() ;
	sort(a,a+n) ;
	int x = solve(a) ;
	int nck = l[n][k] ;
	cout << (x*modexp(nck,mod-2))%mod ;
	return 0 ;
}

