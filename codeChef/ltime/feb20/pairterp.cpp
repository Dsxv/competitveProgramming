#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
int N ;
void update(int* BIT , int ind , int val){
    for(int i = ind ; i <= N ; i += i&-i){
        BIT[i] += val ;
    }
}
 
int query(int* BIT , int ind){
    int sum = 0 ;
    for(int i = ind ; i > 0 ; i -= i&-i){
        sum += BIT[i] ;
    }
    return sum ;
}

bool check(pair<int,int> a , pair<int,int> b){
	if(a.first != b.first) return a.first < b.first ;
	else return a.second < b.second ;
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		N = 2*n + 2 ;
		ordered_set s ;
		pair<int,int> p[n] ;
		int bit[N+10] = {} ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].first >> p[i].second ;
			p[i].first += 1e9 ;
			p[i].second += 1e9 ;
			s.insert(p[i].first) ;
			s.insert(p[i].second) ;
		}
		for(int i = 0 ; i < n ; i++){
			p[i].first = s.order_of_key(p[i].first) + 2;
			p[i].second = s.order_of_key(p[i].second) + 2;
		}
		sort(p,p+n,check) ;
		int ans = 0 ;
		pair<int,int> pr = {0,0};
		int mp[N+10] = {} ;
		for(int i = 0 ; i < n ; i++){
			if(p[i].first != pr.first) pr = {p[i].first,0} ;
			ans += query(bit,p[i].second-1) - query(bit,p[i].first) + 1 ;
			ans -= pr.second ;
			if(!mp[p[i].second]) {
				update(bit,p[i].second,1) ;
				mp[p[i].second] = 1 ;
			}
			pr.second++ ;
		}
		cout << ans + 1 << '\n' ;
	}
	return 0 ;
}

