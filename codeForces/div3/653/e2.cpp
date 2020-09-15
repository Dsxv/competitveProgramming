#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
const int N = 1e4 + 10 ;

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
} bit(N) , bit2(N) , trace(N);

int solve(int cnt){
	int lo = 1 , hi = N - 2 ;
	int ind = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		int x = bit.query(mid) ;
		int y = bit.query(mid-1) ;
		if(x >= cnt){
			if(y < cnt) {
				ind = mid ; break ;
			} else {
				hi = mid - 1 ;
			}
		} else {
			lo = mid + 1 ;
		}
	}
	int x = bit.query(ind-1) ;
	int y = bit2.query(ind-1) ;
	return y + (cnt-x)*ind ;
}


int32_t main(){
	int n , k , m ;
	cin >> n >> m >> k ;
	vector<int> a , b , c ;
	vector<pair<int,int>> p , q , s ;
	map<int,vector<int>> mp ;
	for(int i = 0 ; i < n ; i++){
		int t,  x , y ;
		cin >> t >> x >> y ;
		if(x == 0 && y == 1) {
			a.push_back(t) ;
			p.push_back({t,i}) ;
		}
		if(x == 1 && y == 0){
			b.push_back(t) ;
			q.push_back({t,i}) ;
		}
		if(x == 1 && y == 1){
			c.push_back(t) ;
			s.push_back({t,i}) ;
		}
		bit.update(t,1) ;
		bit2.update(t,t) ;
		trace.update(t,1) ;
		mp[t].push_back(i) ;
	}
	a.push_back(0) ; b.push_back(0) ; c.push_back(0) ;
	p.push_back({0,0}) ; q.push_back({0,0}) ; s.push_back({0,0}) ;
	sort(a.begin() , a.end()) ;
	sort(b.begin() , b.end()) ;
	sort(c.begin() , c.end()) ;
	sort(p.begin() , p.end()) ;
	sort(q.begin() , q.end()) ;
	sort(s.begin() , s.end()) ;
	int sum = 0 ;
	for(int i = 1 ; i < a.size() ; i++){
		a[i] += a[i-1] ;
	}
	for(int i = 1 ; i < b.size() ; i++){
		b[i] += b[i-1] ;
	}
	for(int i = 1 ; i < c.size() ; i++){
		c[i] += c[i-1] ;
	}
	int mx = 1e15 , ind = -1 ;
	int l = 1 , r = 1 ;
	for(int i = 0 ; i < c.size() ; i++){
		int rem = k - i;
		int cnt = m - i ; // remaining books to be taken
		if(rem <= 0) break ;
		if(a.size() < (rem + 1) || b.size() < (rem+1)) continue ;
		if(a.size() < (l+1) || b.size() < (r+1)) break ;
		cnt -= rem*2 ;
		bit.update(a[l] , -1) ; bit2.update(a[l] , -a[l]) ;
		bit.update(b[r] , -1) ; bit2.update(b[r] , -b[r]) ;
		l++ , r++ ;
		if(cnt < 0) continue ;	
		int val = c[i] + a[rem] + b[rem] + solve(cnt) ;
		if(val < mx){
			mx = val ;
			ind = i ;
		}
	}

	if(ind == -1){
		cout << -1 ;
		return 0 ;
	}
	vector<int> ans ;
	l = 1 , r = 1 ;
	for(int i = 0 ; i <= ind ; i++){
		if(ans.size() == m) break ;
		if(i) {
			ans.push_back(s[i].second) ;
			mp[s[i].first].pop_back() ;
		}
		int rem = k - i;
		if(a.size() < (rem + 1) || b.size() < (rem+1)) continue ;
		if(a.size() < (l+1) || b.size() < (r+1)) break ;
		trace.update(a[l] , -1) ;
		trace.update(b[r] , -1) ;
		if(ans.size() == m) break ;
		if(l){
			ans.push_back(p[l].second) ;
			mp[p[l].first].pop_back() ;
		}
		if(ans.size() == m) break ;
		if(r){
			ans.push_back(q[r].second) ;
			mp[q[r].first].pop_back() ;
		}
		l++ , r++ ;
	}
	for(int i = 1 ; i < N ; i++){
		while(trace.query(i) && ans.size() < m){
			ans.push_back(mp[i].back()) ;
			mp[i].pop_back() ;
			trace.update(i,-1) ;
		}
	}
	cout << mx << '\n' ;
	for(auto i : ans) cout << i + 1 << " " ;
	return 0 ;
}

