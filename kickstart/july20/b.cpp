#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n; 
	cin >> n; 
	int a[n] ;
	vector<int> v ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	v.push_back(a[0]) ;
	for(int i = 1 ; i < n ; i++){
		if(a[i] != v.back()) v.push_back(a[i]) ;
	}
	n = v.size() ;
	int cnt = 2 , ans = 0;
	if(n <= 4){
		cout << 0 << '\n' ;
		return ;
	}
	bool d = (a[1] - a[0]) > 0 ;
	for(int i = 2 ; i < n ; i++){
		bool c = (a[i] - a[i-1]) > 0 ;
		if(c != d) {
			d = c ;
			ans += (cnt-1) / 4 ;
			cnt = 1 ;
		}
		cnt++ ;
	}
	ans += (cnt-1) / 4 ;
	cout << ans << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


