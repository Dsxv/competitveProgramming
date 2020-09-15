#include <bits/stdc++.h>
using namespace std ;

#define int long long

pair<int,int> dp[19][2][2][2] ;
int da[19] , db[19] ;
int ansd[19] ;

int power(int a  , int n ){
	return n ? a*power(a,n-1) : 1 ;
}

void maxset(int i , pair<int,int>& ans , pair<int,int> val , int j , bool check = true){
	if(j * val.first >= ans.first){
		ans.first = j*val.first ;
		ans.second = val.second + check*j*power(10 , 18-i) ;
	}
}

pair<int,int> solve(int i = 0 , bool small = false , bool big = false , bool taken = false){
	if(i == 19){
		return {1,0} ;
	}
	if(dp[i][small][big][taken].first != -1) return dp[i][small][big][taken] ;
	pair<int,int> ans(0,0) ;
	int temp = da[i] ;
	if(!big) da[i] = min(da[i]  , db[i]) ;
	for(int j = 1 ; j <= 9 ; j++){
		if(j == da[i] || j == db[i]){
			if(da[i] == db[i]) maxset(i , ans , solve(i+1,small,big,1) , j) ;
			else maxset(i , ans , solve(i+1 , small | (j != da[i]) , big | ( j != db[i]) , 1) , j) ; 
			continue ;
		}
		if(j < da[i] && small){
			maxset(i , ans , solve(i+1,small , 1 , 1) , j) ;
			continue ;
		}
		if(j > db[i] && big){
			maxset(i , ans , solve(i+1,1,big,1) , j) ;
			continue ;
		}
		if(j > da[i] && j < db[i]){
			maxset(i , ans , solve(i+1,1,1,1) , j) ;
			continue ;
		}
	}
	if(!taken && da[i] == 0) {
		maxset(i , ans , solve(i+1,small,big|db[i],0) , 1 , 0) ;
	}
	da[i] = temp ;
	return dp[i][small][big][taken] = ans ;
}
		
int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int a , b ; cin >> a >> b ;
	int cnt = 18 ;
	while(a){
		da[cnt--] = a%10 ;
		a /= 10 ;
	}
	cnt = 18 ;
	while(b){
		db[cnt--] = b%10 ;
		b /= 10 ;
	}
	cout << solve().second ;
	return 0 ;
}

