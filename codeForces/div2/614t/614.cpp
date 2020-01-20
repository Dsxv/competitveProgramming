#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x0 , y0 , ax , ay , bx , by ;
	vector<pair<int,int>> v ;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by ;
	int xs , ys , t ;
	cin >> xs >> ys >> t ;
	v.push_back({x0,y0}) ;
	while(max((v.back().first)*ax + bx,(v.back().second*ay) + by) < (int)1e18) {
		v.push_back({v.back().first*ax + bx , v.back().second*ay + by}) ;
	}
	for(auto i : v) cout << i.first << " " << i.second << endl ;
	int count = 0 ;
	while((int)v.size()){
		vector<pair<int,int>> d ;
		for(int i = 0 ; i < v.size() ; i++){
			d.push_back({abs(xs-v[i].first) + abs(ys-v[i].second), i}) ;
		}
		sort(d.begin(),d.end()) ;
		int i = d[0].second ;
		int dis = abs(xs - v[i].first) + abs(ys - v[i].second) ;
		//cout << dis << ":" << t << " :: " << v[i].first << " " << v[i].second << endl ;
		if(t >= dis) {
			count++ ;
			xs = v[i].first ;
			ys = v[i].second ;
			v.erase(v.begin()+i) ;
			t -= dis ;
		} else {
			break ;
		}
	}
	cout << count ;
		return 0 ;
}

