#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x ;
	cin >> x ;
	vector<int> f ;
	int l = sqrt(x) ;
	if(x == 1){
		cout << 1 << " " << 1 ;
		return 0 ;
	}
	for(int i = 1 ; i <= l ; i++){
		if(x%i) continue ;
		if(x/i == i){
			f.push_back(i) ;
		} else {
			f.push_back(i) ;
			f.push_back(x/i) ;
		}
	}
	int n = f.size() ;
	sort(f.begin(),f.end()) ;
	pair<int,int> p(INT_MAX,INT_MAX) ;
	for(int i = 0 , j = n - 1 ; i < j ; i++ , j--){
		if(__gcd(f[i],f[j]) == 1) {
			p = {f[i],f[j]} ;
		}
	}
	cout << p.first << " " << p.second ;
	return 0 ;
}

