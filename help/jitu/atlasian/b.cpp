#include <bits/stdc++.h>
using namespace std ;

int n , dis , cnt ;
const int mod = 1e5 + 7 ;
const int N = 20 , M = 20 ;
int dp[N][N][M][M][2] ;

int solve(int i , int j , int sum , int k , bool prev , bool t1 = 0 , bool t2 = 0){
	if(k < 0 || sum > dis || (i > n+1) || (j > n+1)){
		return 0 ;
	}
	if(i == (n+1) && j == (n+1)){
		if(!t1 || !t2) {
			sum += cnt*2*n ;
		}
		//if(sum > dis) return 0 ;
		cout << "here"  << endl ;
		return ((dis-sum)%(2*n) == 0) && (k == 0) ;
	}
	if(~dp[i][j][sum][k][prev]) return dp[i][j][sum][k][prev] ;
	int ans = 0 ;
	if(prev){
		ans = (solve(i+1,j,sum+2*i,k-1,0 ,1,t2) + solve(i+1,j,sum,k,1,t1,t2)) % mod ;
	} else {
		ans = (solve(i,j+1,sum+2*j,k-1,1,t1,1) + solve(i,j+1,sum,k,0,t1,t2)) % mod ;
	}
	return dp[i][j][sum][k][prev] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> dis >> n >> cnt ;
	cout << solve(1,1,0,cnt,1) ;
	return 0 ;
}

