#include <bits/stdc++.h>
using namespace std ;
 
const int N = 1e6+10 ;

int BIT[N] ;
int total ;
void update(int ind , int val){
    for(int i = ind ; i <= N ; i += i&-i){
        BIT[i] += val ;
    }
}
 
int query(int ind){
    int sum = 0 ;
    for(int i = ind ; i > 0 ; i -= i&-i){
        sum += BIT[i] ;
    }
    return sum ;
}
int solve(int x){
    int lo = 1 , hi = N-1 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi)/2; 
		int q1 = query(mid) ;
		int q2 = query(mid-1) ;
		if(q1 >= x && q2 < x){
			ans = mid ;
			break ;
		} else if(q1 >= x){
			hi = mid - 1 ;
		} else {
			lo = mid + 1 ;
		}
	}
	return ans ;
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	for(int i = 0 ; i < n ; i++){
		int ind ; cin >> ind ;
		update(ind,1) ;
	}
	while(k--){
		int x ;
		cin >> x ;
		if(x < 0){
			int ind = solve(-x) ;
			update(ind,-1) ;
		} else {
			update(x,1) ;
		}
	}
	cout << solve(1) ;
	return 0 ;
}

