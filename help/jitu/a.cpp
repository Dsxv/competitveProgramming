#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 998244353 ;
const int N = 1e3 + 10 ;
vector<vector<int>> g ;
vector<int> a ;
vector<int> ser ;

void solve(int x){
	queue<pair<int,int>> q ;
	q.push({1,1}) ;
	while(ser.size() <= N){
		auto [cur,sum] = q.front() ;
		ser.push_back(cur) ;
		q.pop() ;
		for(int i = 0 ; i < 10 ; i++){
			if(sum + i*i <= x){
				q.push({(cur*10 + i)%mod , sum + i*i}) ;
			}
		}
	}
}



int32_t main(){
	int n , m , x ;
	cin >> n >> m >> x ;
	solve(x) ;
	for(int i = 0 ; i  < n ; i++)
	// series stored in `ser`
	for(int i = 0 ; i < 10 ; i++) cout << ser[x] << '\n' ;
	return 0 ;
}

