#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	vector<pair<int,int>> pos , neg ;
	int a[n] = {} ;
	for(int i = 0 ; i < m ; i++){
		int f , s , l ;
		cin >> f >> s >> l ;
		f-- , s-- ;
		a[f] -= l ;
		a[s] += l ;
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] < 0) neg.push_back({i,-a[i]}) ;
		if(a[i] > 0) pos.push_back({i,a[i]}) ;
	}
	vector<vector<int>> edges ;
	int i = 0 , j = 0 ;
	while(i < neg.size() && j < pos.size()){
		int mn = min(neg[i].second , pos[j].second) ;
		neg[i].second -= mn ;
		pos[j].second -= mn ;
		vector<int> temp = {neg[i].first , pos[j].first , mn} ;
		edges.push_back(temp) ;
		if(!neg[i].second) i++ ;
		if(!pos[j].second) j++ ;
	}
	cout << edges.size() << '\n' ;
	for(auto i : edges){
		cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] ;
		cout << '\n' ;
	}
	return 0 ;
}

