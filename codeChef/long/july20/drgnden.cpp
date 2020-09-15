#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
const int N = 1e6 ;

struct BIT{
	int n ;
	vector<int> v; 
	BIT(int n){
		this->n = n ;
		v.resize(n) ;
	}
	void update(int ind , int val){
		ind++ ;
		for(int i = ind ; i < n ; i += i&-i){
			v[i] += val ;
		}
	}
	int query(int ind){
		ind++ ;
		int sum = 0 ;
		for(int i = ind ; i > 0 ; i -= i&-i){
			sum += v[i] ;
		}
		return sum ;
	}
} ;

vector<int> prev_g(vector<int> & h){
	stack<int> s ;
	vector<int> ans(h.size()) ;
	for(int i = h.size() - 1 ; i >= 0 ; i--){
		while(h[i] > h[s.top()]){
			ans[s.top()] = i ;
			s.pop() ;
		}
		s.insert(i) ;
	}
	while(s.size()){
		ans[s.top()] = -1 ;
		s.pop() ;
	}
	return ans ;
} 

vector<int> a , h , acomp , hcomp;

void solve(int start , vector<int>& visited ,  vector<int> euler , vector<pair<int,int>> rng){
	visited[start] = true ;
	rng[start].first = euler.size() ;
	euler.push_back(start) ;
	for(auto i : g[start]){
		solve(i,visited,euler,rng) ;
	}
	rng[start].second = euler.size() ;
	euler.push_back(start) ;
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	int n , q ;
	cin >> n >> q ;
	vector<vector<int>> g , gcomp ;
	g.resize(n) ; gcomp.resize(n) ;
	a.resize(n) ; h.resize(n) ;
	a_comp.resize(n) ; h_comp.resize(n) ;
	for(int i = 0 ; i < n ; i++) cin >> h[i] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	a_comp = a ; h_comp = h ;
	reverse(a_comp.begin() , a_comp.end()) ;
	reverse(h_comp.begin() , h_comp.end()) ;
	auto tp = prev_g(h) ;
	vector<int> reach(n) , reach_comp(i) ;
	for(int i = 0 ; i < n ; i++){
		reach[i] = i ;
	}
	for(int i = 0 ; i < n ; i++){
		if(~tp[i]){
			g[tp[i]].push_back(i) ;
			reach[tp[i]] = max(reach[tp[i]] , i) ;
		}
	}
	vector<int> visited(n) ;
	vector<int> euler;
	vector<pair<int,int>> rng(n) ;
	for(int i = 0 ; i < n ; i++){
		if(visited[i]) continue ;
		if(~tp[i]) continue ;
		solve(i,visited,euler,rng) ;
	}
	visited.clear() ; visited.resize(n) ;
	BIT bit(2*n + 10) , bit_comp(2*n + 10) ;
	for(int i = 0 ; i < n ; i++){
		bit.update(rng[i].first , a[i]) ;
		bit.update(rng[i].second + 1, -a[i]) ;
	}
	while(q--){
		int t , b , x;
		cin >> t >> b >> x;
		if(t == 1){
			b-- ;
			bit.update(rng[b].first , -a[b] + x) ;
			bit.update(rng[b].second + 1 , a[b] - x) ;
			a[b] = x ;
		} else {
			b-- , x-- ;
			// check for connectivity of b and x
			if(x >= b){
				if(reach[b] >= reach[x]){
					cout << bit.query(x) - bit.query(b) + a[b]<< '\n' ;
				} else cout << -1 << '\n' ;
			} else {

		}
	}

	return 0 ;
}


