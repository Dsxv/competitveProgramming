#include <bits/stdc++.h>
using namespace std ;

#define int long long

set<int> cnt[3005] ;

struct comp{
	bool operator () (int x , int y) const{
		if(cnt[x].size() == cnt[y].size()) return x < y ;
		return cnt[x].size() < cnt[y].size() ;
	}
} ;

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> v[n*m + 1] ;
	set<int , comp> s ;
	for(int i = 0 ; i < k ; i++){
		int x ; cin >> x ;
		for(int j = 0 ; j < x ; j++){
			int val ; cin >> val ;
			cnt[i].insert(val) ;
			v[val].push_back(i) ;
		}
		s.insert(i) ;
	}
	int ans = 0 ;
	while(s.size()){
		int x = *s.begin() ;
		if(!cnt[x].size()){
			s.erase(s.begin()) ;
			continue ;
		} else {
			int y = *(cnt[x].begin()) ;
			assert(v[y].size()) ;
			for(auto i : v[y]){
				if(s.count(i)){
					cnt[i].erase(y) ;
				}
			}
			s.erase(s.begin()) ;
			v[y].clear() ;
			ans++ ;
		}
	}
	cout << ans ;
	return 0 ;
}

