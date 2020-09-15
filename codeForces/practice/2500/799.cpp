#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
const int N = 2e5 + 10 ;

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
} bit(N) , bit2(N) ;

pair<vector<int>,vector<int>> compress(vector<int>& a){
	int n = a.size() ;
	map<int,vector<int>> mp;
	for(int i = 0 ; i < n ; i++){
		mp[a[i]].push_back(i) ;
	}
	vector<int> ans(n) , mapped(n) ;
	int cnt = 0 ;
	for(auto i : mp){
		for(auto j : i.second){
			ans[j] = cnt ;
		}
		mapped[cnt] = i.first ;
		cnt++ ;
	}
	return {ans,mapped} ;
}

int solve(int cnt , vector<int>& mp){
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
	return y + (cnt-x)*mp[ind] ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> temp(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> temp[i] ;
	}
	auto [ans, mp] = compress(temp) ;
	vector<vector<bool>> v(n,vector<bool>(2,0)) ;
	int p ; cin >> p ;
	while(p--){
		int x; cin >> x ;
		v[x-1][0] = 1 ;
	}
	cin >> p ;
	while(p--){
		int x ; cin >> x ;
		v[x-1][1] = 1;
	}
	vector<int> a , b , c , pa , pb , pc;
	for(int i = 0 ; i < n ; i++){
		int t = ans[i] , x = v[i][0] , y = v[i][1] ;
		if(x == 1 && y == 0){
			a.push_back(t) ;
			pa.push_back(mp[t]) ;
		}
		if(x == 0 && y == 1){
			b.push_back(t) ;
			pb.push_back(mp[t]) ;
		}
		if(x == 1 && y == 1){
			c.push_back(t) ;
			pc.push_back(mp[t]) ;
		}
		bit.update(t,1) ;
		bit2.update(t,mp[t]) ;
	}
	a.push_back(0) ; b.push_back(0) ; c.push_back(0) ;
	pa.push_back(0) ; pb.push_back(0) ; pc.push_back(0) ;
	sort(a.begin() , a.end()) ;
	sort(b.begin() , b.end()) ;
	sort(c.begin() , c.end()) ;
	sort(pa.begin() , pa.end()) ;
	sort(pb.begin() , pb.end()) ;
	sort(pc.begin() , pc.end()) ;
	int sum = 0 ;
	for(int i = 1 ; i < a.size() ; i++){
		pa[i] += pa[i-1] ;
	}
	for(int i = 1 ; i < b.size() ; i++){
		pb[i] += pb[i-1] ;
	}
	for(int i = 1 ; i < c.size() ; i++){
		pc[i] += pc[i-1] ;
	}
	int mx = 1e18 ;
	int l = 0 , r = 0 ; 
	for(int i = 1 ; i <= k ; i++){
		if(i < a.size()) {
			bit.update(a[i] , -1) ;
			bit2.update(a[i] , -mp[a[i]]) ;
			l = i ;
		}
		if(i < b.size()) {
			bit.update(b[i] , -1) ;
			bit2.update(b[i] , -mp[b[i]]) ;
			r = i ;
		}
	}
	int cnt = m - 2*k ;
	if(l == k && r == k && cnt >= 0){
		mx = pb[k] + pa[k] + solve(cnt , mp) ;
	}
	for(int i = 1 ; i < c.size() ; i++){
		int rem = k - i ; // rem type of each
		cnt = m - 2*rem - i ;
		bit.update(c[i] , -1) ;
		bit2.update(c[i] , -mp[c[i]]) ;
		if(rem < 0 || cnt < 0) continue ;
		while(l > rem){
			bit.update(a[l] , 1) ;
			bit2.update(a[l] , mp[a[l]]) ;
			l-- ;
		}
		while(r > rem) {
			bit.update(b[r] , 1) ;
			bit2.update(b[r] , mp[b[r]]) ;
			r-- ;
		}
		if(l == rem && r == rem){
			int val = pc[i] + pa[l] + pb[r] + solve(cnt , mp) ;
			mx = min(mx , val) ;
		}
	}

	cout << (mx == 1e18 ? -1 : mx) << '\n' ;
	
	return 0 ;
}



