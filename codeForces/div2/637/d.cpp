#include <bits/stdc++.h>
using namespace std ;

#define int long long

string s[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"} ;

const int N = 2e3 + 10 ;

int dp[N][N] ;

int n , k ; 

bool ok(string&a , string&b){
	for(int i = 0 ; i < 7 ; i++){
		if(b[i] == '1' && a[i] == '0') return false ;
	}
	return true ;
}

int ans[N] = {} ;

bool solve(vector<pair<int,int>>* a , int i = 0 , int j = 0){
	if(j > k){
		return 0 ;
	}
	if(i == n){
		return j == k;
	}
	if(~dp[i][j]) return dp[i][j] ;
	bool ok = false ;
	for(int id = 0 ; id < a[i].size() ; id++){
		if(!ok && solve(a,i+1,j+a[i][id].second)){
			ok = true ;
			::ans[i] = a[i][id].first ;
		}
	}
	return dp[i][j] = ok ;
}

int32_t main(){
	cin >> n >> k ;
	memset(dp , - 1 , sizeof(dp)) ;
	vector<pair<int,int>> a[n] ;
	for(int i = 0 ; i < n ; i++){
		string temp ;
		cin >> temp ;
		for(int j = 0 ; j < 10 ; j++){
			if(ok(s[j],temp)) {
				int cnt = count(s[j].begin(),s[j].end(),'1') - 
							count(temp.begin(),temp.end(),'1') ;
				a[i].push_back({j,cnt}) ;
			}
		}
		sort(a[i].begin(),a[i].end(),greater<pair<int,int>>()) ;
	}
	if(solve(a)) {
		for(int i = 0 ; i < n ; i++) cout << ::ans[i] ;
	} else {
		cout << -1 ;
	}
	return 0 ;
}
