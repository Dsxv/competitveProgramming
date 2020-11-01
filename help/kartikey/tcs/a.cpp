#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	if(n <= 0 || n > 1e8){
		cout << "Wrong Input" ;
		return 0 ;
	}
	vector<int> v ;
	int l = sqrt(n) ;
	for(int i = 1 ; i <= l ; i++){
		if(n % i) continue ;
		if(n / i == i){
			v.push_back(i) ;
		} else {
			v.push_back(n / i) ;
			v.push_back(i) ;
		}
	}
	sort(v.begin() , v.end()) ;
	for(auto i : v) cout << i << " " ;
	return 0 ;
}

