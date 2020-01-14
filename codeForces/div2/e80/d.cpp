#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
 
const int N = 3e5 + 10 , M = 9 ;
int b[N][M] ;
pair<int,int> p ;
 
bool check(int x , int n , int m){
	bitset<10> a[n] ;
	map<int,int> mp ;
	vector<pair<int,int>> v ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			a[i][j] = (b[i][j] >= x) ;
		}
		int y = a[i].to_ulong() ;
		if(mp.count(y)) continue ;
		mp[y] = 1 ;
		v.push_back({y,i}) ;
	}
	int t = (1<<m) - 1 ;
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v.size() ; j++){
			int f = v[i].first , s = v[j].first ;
			if((f|s) == t){
				p = {v[i].second+1,v[j].second+1} ;
				return true ;
			}
		}
	}
	return false ;
}
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	ordered_set s;
	int a[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
			s.insert(a[i][j]) ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			b[i][j] = s.order_of_key(a[i][j]) ;
		} 
	}
	int lo = 0 , hi = 1e9 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,n,m)){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	//cout << check(0,n,m) << endl ;
	cout << p.first << " " << p.second ;
	return 0 ;
}
 
