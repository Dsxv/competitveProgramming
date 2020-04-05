#include <bits/stdc++.h>
using namespace std ;

const int N = (1LL<<18) + 2 ;
long long dp[N][103] ;
long long n , mx;
int m ;
int val[20] ;

int ff(int& mod, int& i , int& x){
	int tp = mod + val[n-i-1]*x ;
	return tp%m ;
}

long long solve(vector<int>& a , int mask = 0 , int mod = 0 , int id = 0){
	if(mask == mx){
		return (mod == 0);
	}
	if(dp[mask][mod] != -1) return dp[mask][mod] ;
	dp[mask][mod] = 0 ;
	for(int i = 0 ; i < n ; i++){
		if((id == 0) && a[i] == 0) continue ;
		if(mask&(1LL<<i)) continue ;
		dp[mask][mod] += solve(a,mask|(1LL<<i),ff(mod,id,a[i]),id+1) ;
	}
	return dp[mask][mod] ;
}

int32_t main(){
	cin >> n >> m ;
	val[0] = 1 ;
	for(int i = 1 ; i < 20 ; i++){
		val[i] = (val[i-1]*10)%m ;
	}
	memset(dp,-1,sizeof(dp)) ;
	vector<int> a ;
	map<int,int> mp ;
	while(n){
		a.push_back(n%10) ;
		mp[n%10]++ ;
		n/=10; 
	}
	n = a.size() ;
	mx = (1<<n) - 1 ;
	long long val = solve(a) ;	
	for(auto i : mp){
		for(int j = 1 ; j <= i.second ; j++)
			val /= j ;
	}
	cout << val ;
	return 0 ;
}

