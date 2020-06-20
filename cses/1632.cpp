#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	pair<int,int> start[n] , end[n] ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> start[i].first >> end[i].first ;
		start[i].second = end[i].second = i ;
		p[i] = {start[i].first , end[i].first} ;
	}
	sort(start , start+n) ;
	sort(end , end+n) ;
	multiset<pair<int,int>,greater<pair<int,int>>> active ;
	int i = 0 , j = 0 ;
	int count = 0 ;
	while(i < n && j < n){
		if(start[i].first < end[j].first){
			active.insert({p[start[i].second].second , start[i].second}) ;
			i++ ;
		} else {
			if(active.count(end[j])){
				active.erase(end[j]) ;
			}
			j++ ;
		}
		while((int)active.size() > k){
			active.erase(active.begin()) ;
			count++ ;
		}
	}
	cout << n-count ;
	return 0 ;
}

