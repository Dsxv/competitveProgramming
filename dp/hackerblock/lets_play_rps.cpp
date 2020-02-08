#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 105 ;
double dp[N][N][N] ;

double solve(int r , int p , int s){
	if(r == 0 || s == 0){
		return 0 ;
	}
	if(p == 0 && r) return 1 ;
	if(dp[r][p][s] != -1) return dp[r][p][s] ;
	double ans = 0 ;
	double t = r*p + p*s  + r*s ;
	double x1 = solve(r-1,p,s) ;
	double x2 = solve(r,p-1,s) ;
	double x3 = solve(r,p,s-1) ;
	ans = x1*(r*p)/t + x2*(s*p)/t 
		+ x3*(r*s)/t ;
	return dp[r][p][s] = ans ;
}
	
int32_t main(){
	int  t;
	cin >> t;
	while(t--){
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				for(int k = 0 ; k < N ; k++) dp[i][j][k] = -1 ;
			}
		}
		int r , s , p ;
		cin >> r >> s >> p ;
		double x1 = solve(r,p,s) ;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				for(int k = 0 ; k < N ; k++) dp[i][j][k] = -1 ;
			}
		}

		double x2 = solve(s,r,p) ;
		cout <<fixed << setprecision(9) << x1 << " " << x2 
			<< " " << (1 - x1 - x2) << endl ;
	}
	return 0 ;
}

