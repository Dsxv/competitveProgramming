#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int n){
	vector<int> ans(n) ;
	for(int i = 0 ; i < n ; i++){
		ans[i] = (i+1)*(n-i) ;
	}
	return ans ;
}

int32_t main(){
	int n;
	cin >> n ;
	vector<int> ans =  solve(n) ;
	for(auto i : ans) cout << i << ' ' ;

	return 0 ;
}

