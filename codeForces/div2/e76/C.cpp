#include <bits/stdc++.h>
using namespace std ;

#define int long long

int check(vector<int>& ans){
	int val = INT_MAX ;
	for(int i = 1 ; i < ans.size() ; i++){
		val = min(ans[i]-ans[i-1],val) ;
	}
	return val + 1 ;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n ;
		cin >> n ;
		vector<int> a[n+1] ;
		for(int i = 0 ; i < n ;i++){
			int x ;
			cin >> x ;
			a[x].push_back(i) ;
		}
		int minval = 1e6 + 5 ;
		int ind = -1 ;
		for(int i = 1 ; i <= n ; i++){
			if(a[i].size() > 1){
				int p = check(a[i]) ;
					if(p < minval){
						minval = p ;
						ind = i ;
					}
			}
		}
		if(minval == 1e6 + 5){
			cout << -1 << '\n';
		}else{
			cout << minval << '\n' ;
		}
	}
	return 0 ;
}

