#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;
#define int long long 
#define f first
#define s second
 const int mod = 1e9 + 7 ;
int n , k ;

int dp[2002][2002] ;
int32_t main(){
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i++) dp[1][i] = 1 ;
	for(int i = 1 ; i < k ; i++){
		for(int j = 1 ; j <= n ; j++){
			for(int fac = j ; fac <= n ; fac += j){
				dp[i+1][fac]  = ( dp[i+1][fac] + dp[i][j] )%mod;
			}

		}
	}
	int sum = 0 ;
	for(int i = 1 ; i <= n ; i++) sum  = (dp[k][i] + sum ) %mod ;
	cout << sum ;
	return 0 ;
}

