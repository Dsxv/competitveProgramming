#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 2e5 + 10 ;
const int mod = 1e9 + 7 ;
map<int,int> BIT[2] ;
int n ;
void update(int ind , int val){
	while(ind <= mod){
		BIT[0][ind] = (val + BIT[0][ind])%mod ;
		BIT[1][ind]++;
		ind += -ind&ind ;
	}
}

pair<int,int> query(int ind){
	pair<int,int> sum ;
	while(ind > 0) {
		sum.first = (sum.first + BIT[0][ind])%mod ;
		sum.second = (sum.second + BIT[1][ind])%mod;
		ind -= -ind&ind ;
	}
	return sum ;
}

bool check(pair<int,int> a , pair<int,int> b){
	return a.second < b.second ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ; cin.tie(0) ;
	int n ;
	cin >> n ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i  < n ; i++) cin >> a[i].first ;
	for(int i = 0 ; i < n ; i++) cin >> a[i].second ;
	sort(a,a+n,check) ;
	int sum = 0 , ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		pair<int,int> p = query(a[i].first) ;
		int k =  (a[i].second*((a[i].first*p.second)%mod - p.first + mod))%mod ;
		ans += k ;
	    //cout << k << " " ;
		int count = i-p.second ;
	//	cout << p.first <<":"<<p.second << endl ;
		k = (a[i].second*(mod + sum - p.first - (count*a[i].first)%mod))%mod ;
		ans += k ;
		update(a[i].first,a[i].first) ;
		sum += a[i].first ;
	}
	cout << ans ;
	return 0 ;
}

