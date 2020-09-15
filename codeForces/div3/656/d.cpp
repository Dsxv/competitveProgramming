#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(string&s , int l , int r , char ch = 'a'){
	if(l == r){
		return s[l] != ch ;
	}
	int ca = 0 , cb = 0 ;
	int mid = (l+r) / 2 ;
	for(int i = l ; i <= mid ; i++){
		ca += s[i] != ch ;
	}
	for(int i = mid + 1; i <= r ; i++){
		cb += s[i] != ch ;
	}
	return min(ca + solve(s,mid+1,r,ch+1) , cb + solve(s,l,mid,ch+1)) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s; 
		cin >> s; 
		cout << solve(s,0,n-1) << '\n' ;
	}
	return 0 ;
}

