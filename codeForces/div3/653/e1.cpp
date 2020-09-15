#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	vector<int> a , b , c ;
	for(int i = 0 ; i < n ; i++){
		int t,  x , y ;
		cin >> t >> x >> y ;
		if(x == 0 && y == 1) {
			a.push_back(t) ;
		}
		if(x == 1 && y == 0){
			b.push_back(t) ;
		}
		if(x == 1 && y == 1){
			c.push_back(t) ;
		}
	}
	a.push_back(0) ; b.push_back(0) ; c.push_back(0) ;
	sort(a.begin() , a.end()) ;
	sort(b.begin() , b.end()) ;
	sort(c.begin() , c.end()) ;
	int sum = 0 ;
	for(int i = 1 ; i < (int)a.size() ; i++){
		a[i] += a[i-1] ;
	}
	for(int i = 1 ; i < (int)b.size() ; i++){
		b[i] += b[i-1] ;
	}
	for(int i = 1 ; i < (int)c.size() ; i++){
		c[i] += c[i-1] ;
	}
	int mx = 1e15 ;
	for(int i = 0 ; i < (int)c.size() ; i++){
		int rem = k - i + 1 ;
		if(rem <= 0) break ;
		if(((int)a.size() < rem) || ((int)b.size() < rem)) continue ;
		mx = min(mx , c[i] + a[rem-1] + b[rem-1]) ;
	}
	cout << (mx == (1e15) ? -1 : mx) ;
	return 0 ;
}

