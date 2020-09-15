#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n; 
	vector<int> ans;
	int val = 1 ;
	while(true){
		if(n == 1){
			ans.push_back(val) ;
			break ;
		}
		if(n == 2) {
			ans.push_back(val) ; ans.push_back(2*val) ; 
			break ;
		} 
		if(n == 3){
			ans.push_back(val) ; ans.push_back(val) ; ans.push_back(3*val) ;
			break ;
		}
		for(int i = 0 ; i < (n+1) / 2 ; i++) ans.push_back(val) ;
		n /= 2 ; val *= 2 ;
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

