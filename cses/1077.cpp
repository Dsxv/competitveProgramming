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

pair<vector<int>,vector<int>> compress(int* a , int n){
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

int solve(int k , int n){
	k = (k+1) / 2 ;
	int lo = 0 , hi = n - 1;
	int ans = -1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		int x = bit.query(mid) ;
		if(x >= k){
			ans = mid ;
			hi = mid - 1 ;
		} else {
			lo = mid + 1 ;
		}
	}
	return ans ;
}

void solve2(int x , vector<int>& a , vector<int>& mp , int n , int k ,int sum){ 
	int rem = (k+1) / 2 - 1 - bit.query(x-1) ; // no. of elements = x left of median
	int smaller = bit2.query(x-1) + rem*mp[x] ;
	int bigger = sum - smaller - mp[x] ;
	// count smaller = (k+1)/2 - 1 , count bigger = k - (k+1) / 2
	cout << ((k+1)/2-1)*mp[x] - smaller + bigger - (k - (k+1)/2)*mp[x] << " " ;
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	int temp[n] ;
	for(int i = 0 ; i < n ; i++) cin >> temp[i] ;
	auto [a,mp] = compress(temp , n) ;
	int sum = 0 ;
	for(int i = 0 ; i < k ; i++){
		bit.update(a[i],1) ;
		bit2.update(a[i], mp[a[i]]) ;
		sum += mp[a[i]] ;
	}
	int md = solve(k,n) ; // solve(k,n) returns the a[i] of median
	solve2(md , a , mp , n , k , sum) ;
	for(int i = k ; i < n ; i++){
		bit.update(a[i-k],-1) ;
		bit.update(a[i],1) ;
		bit2.update(a[i],mp[a[i]]) ;
		bit2.update(a[i-k],-mp[a[i-k]]) ;
		sum -= mp[a[i-k]] ;
		sum += mp[a[i]] ;
		md = solve(k,n) ;
		solve2(md , a , mp , n , k , sum) ;
	}
	return 0 ;
}




