#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;

void sieve(int* a){
	int n = N-1 ;
	a[0] = 0 ;
	a[1] = 1 ;
	for(int i =2 ; i*i <= n ; i++){
		if(a[i] >= i){
			a[i] = min(a[i],i) ;
			for(int j = i*i ; j <= n ; j+=i){
				a[j] = min(a[j],i) ;
			}
		}
	}
}
set<int> fac(int n){
	map<int,int> mp ;
	while(n > 1){
		mp[a[n]]++ ;
		n/=a[n] ;
	}
	set<int> s ;
	for(auto i : mp){
		if(i.first&1){
			s.insert(i.first) ;
		}
		if(s.size() == 0) s.insert(1) ;
	}
}

int32_t main(){
	int a[N] ;
	for(int i = 0 ; i < N ; i++) a[i] = i ;
	solve(a) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		bool up[N] , down[N] , left[N] , right[N] ;
		map<set<int>,vector<int>> mpx , mpy 
		vector<int> mnx , mny ;
		int px = 0 , py = 0 ;
		bool z = 0 ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			if(x < 0) {
				mnx.insert(-x) ;
				left[-x] = 1 ;
			} else if( x > 0) {
				mpx[x] = 1 ;
				right[x] = 1 ;
				px++ ;
			} else z = 1 ;
		}
		for(int i = 0 ; i < m ; i++){
			int y ; cin >> y ;
			if(y < 0) {
				mny.insert(-y) ;
				down[-y] = 1 ;
			} else if( y > 0) {
				mpy[y] = 1 ;
				up[y] = 1 ;
				py++ ;
			} else z = 1 ;
		}
		int ans = 0 ;
		if(z){
			px += mnx.size() ;
			py += mny.size() ;
			ans += px*py ;
		}
		vector<pair<int,int>> v ;
		for(auto i : mnx){
			set<int> temp = fact(i) ;
			if(mpx.count(temp)) {
				for(int item : mpx[temp]){
					v.push_back({item,i}) ;
				}
			}
		}
		for(auto  i : v){
			int sq = sqrt(i.first*i.second) ;
			if(sq < N){
				if(up[sq]) ans++ ;
				if(down[sq]) ans++ ;
			}
		}
		v.clear() ;
		for(auto i : mny){
			int temp = fact(i) ;
			if(mpy.count(temp)){
				for(auto item : mpy[temp]) { 
					v.push_back({item,i}) ;
				}
			}
		}
		for(auto i : v){
			int sq = sqrt(i.first*i.second) ;
			if(sq < N){
				if(right[sq]) ans++ ;
				if(left[sq]) ans++ ;
			}
		}
		cout << ans ;
	}
	return 0 ;
}

