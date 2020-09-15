#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> v ;
	int l = sqrt(n) ;
	for(int i = 1 ; i <= l ; i++){
			if(n%i) continue ;
			if(i*i == n){
				v.push_back(i) ;
			} else {
				v.push_back(i) ;
				v.push_back(n/i) ;
			}
	}
	int ans = 0 ;
	for(auto i : v){
		bool ok = i%25 == 0 || i%36 == 0 ;
		bool ok2 = i%25 == 0 && i%36 == 0 ;
		ans += (i%12 == 0 && (!ok || ok2)) ;
	}
	cout << ans ;
	return 0 ;
}

