#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e5 + 10 ;
string s[N] ;
string ch[N] ;

void solve(int l , int r , int j = 0){
	for(int i = l ; i <= r ; i++){
		if(j >= ch[i].size()){
			l = i + 1;
		} else {
			if((i-l) && ch[i][j] < ch[i-1][j]) {
				l = i ;
			}
		}
	}
	int prev = l ;
	for(int i = l; i <= r ; i++){
		s[i] += ch[i][j];
		if((i-l) && ch[i][j] != ch[i-1][j]){
			solve(prev , i - 1 , j + 1) ;
			prev = i ;
		}
	}
	if(l <= r){
		solve(prev , r , j + 1) ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> ch[i] ;
	}
	solve(0,n-1) ;
	for(int i = 0 ; i < n ; i++) cout << s[i] << '\n' ;
	return 0 ;
}

