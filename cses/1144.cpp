#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
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
} bit(N);

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

struct qt{
	char ch ;
	int a , b ;
} ;

int32_t main(){
	
	ios :: sync_with_stdio(0) ; cin.tie(0) ;
	int n , q ;
	cin >> n >> q ;
	vector<int> v ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		v.push_back(a[i]) ;
	}
	vector<qt> qr(q) ;
	vector<qt> mp(q) ;
	for(int i = 0 ; i < q ; i++){
		char ch ;
		int a , b ;
		cin >> ch >> a >> b ;
		qr[i].ch = ch ; qr[i].a = a ;
		qr[i].b = b ;
		if(ch == '!') {
			mp[i].b = v.size() ; v.push_back(b) ;
		} else {
			mp[i].a = v.size() ; v.push_back(a) ;
			mp[i].b = v.size() ; v.push_back(b) ;
		}
	}
	// compression
	auto [ans , mapped] = compress(v) ;
	for(int i = 0 ; i < n ; i++) a[i] = ans[i] ;
	for(int i = 0 ; i < q ; i++){
		if(qr[i].ch == '!'){
			qr[i].b = ans[mp[i].b] ;
		} else {
			qr[i].a = ans[mp[i].a] ;
			qr[i].b = ans[mp[i].b] ;
		}
	}
	// compression_end
	for(int i = 0 ; i < n ; i++){
		bit.update(a[i] , 1) ;
	}
	for(auto i : qr){
		if(i.ch == '!'){
			bit.update(a[i.a-1], -1) ;
			a[i.a - 1] = i.b ;
			bit.update(a[i.a-1], 1) ;
		} else {
			cout << bit.query(i.b) - bit.query(i.a-1) << '\n' ;
		}
	}
	return 0 ;
}


