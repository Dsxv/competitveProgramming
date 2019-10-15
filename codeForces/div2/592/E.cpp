#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		mp[x]++ ;
	}
	while(k){
		if(mp.size() == 1) {
			cout << 0 ;
			return 0 ;
		}
		pair<int,int> f = *mp.begin() , r = *mp.rbegin() ;
		if(f.second <= r.second){ // first el has lower freq
			mp.erase(mp.find(f.first)) ;
			pair<int,int> cur = *mp.begin() ;
			int dis = cur.first - f.first ;
			if(dis*f.second >= k){
				f.first += k/f.second ;
				mp.insert(f) ;
				k = 0 ;
			}else{
				k -= dis*f.second ;
				(*mp.begin()).second += f.second ;
			}
		}else{
			mp.erase(mp.find(r.first)) ;
			pair<int,int> cur = *mp.rbegin() ;
			int dis = r.first - cur.first ;
			if(dis*r.second >= k){
				r.first -= k/r.second ;
				mp.insert(r) ;
				k = 0 ;
			}else{
				k -= dis*r.second ;
				
				(*mp.rbegin()).second += r.second ;
			}
		}
	}
	int ans = (*mp.rbegin()).first - (*mp.begin()).first ;
	cout << ans ;
	return 0 ;
}

