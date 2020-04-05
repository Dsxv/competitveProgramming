#include <bits/stdc++.h>
using namespace std ;

#define int long long

int t , n ;

int dp[1005][1005] ;

struct job{
	int x , y , z ;
} ;

int solve(int* a , int* b , int* c , int i = 0 , int j = 0){
	if(i == n || j == t){
		return 0 ;
	}
	if(~dp[i][j]){
		return dp[i][j] ;
	}
	int t1 = 0 , t2 = 0 ;
	t1 = solve(a,b,c,i+1,j) ;
	if(a[i] + j <= t && a[i] + j <= b[i]){
		t2 = solve(a,b,c,i+1,j+a[i]) + c[i] ;
	}
	return dp[i][j] = max(t1 , t2) ;
}

int32_t main(){
	cin >> t >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	job j[n] ;
	int a[n] , b[n] , c[n] ;
	for(int i = 0 ; i < n ; i++) cin >> c[i] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	// sort(j,j+n,[](job a , job b){
	// 	if(a.z != b.z) return a.z < b.z ;
	// 	else return a.y < b.y ;
	// }) ;
	// for(int i = 0 ; i < n ; i++){
	// 	a[i] = j[i].y ;
	// 	b[i] = j[i].z ;
	// 	c[i] = j[i].x ; 
	// }
	cout << solve(a,b,c) ;
	return 0 ;
}
