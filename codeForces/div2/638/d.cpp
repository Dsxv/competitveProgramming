#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int x = 0 ;
		int sum = 0 ;
		vector<int> v ;
		while(sum + (1LL<<x) < n){
			v.push_back(1LL<<x) ;
			sum += 1LL<<x;
			x++ ;
		}
		if(n - sum > 0) v.push_back(n-sum) ;
		sort(v.begin() , v.end()) ;
		vector<int> dif ;
		for(int i = 1 ; i < v.size() ; i++){
			dif.push_back(v[i] - v[i-1]) ;
		}
		cout << dif.size() << '\n' ;
		for(auto i : dif) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

