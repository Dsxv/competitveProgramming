#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(string s , int n){
	vector<int> ans(n) ;
	s += '>' ;
	int prev = -1 , k = n ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '<') continue ;
		for(int j = i; j > prev ; j--){
			ans[j] = k-- ;
		}
		prev = i ;
	}
	return ans; 
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n;
		cin >> n;
		string s ;
		cin >> s ;
		vector<int> ans1 =  solve(s,n) ;
		for(auto &i : s) i ^= ('<'^'>') ;
		vector<int> ans2 = solve(s,n) ;
		for(auto i : ans1) cout << i << " " ;
		cout << '\n' ;
		for(auto i : ans2) cout << n - i + 1 << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

