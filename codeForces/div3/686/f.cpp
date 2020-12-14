#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(pair<int,int> *p , int *a , int n){
	stack<int> st ;
	vector<int> nxs(n) , pvs(n) ;
	for(int i = 0 ; i < n ; i++){
		while(st.size() && a[i] < a[st.top()]){
			nxs[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	while(st.size()){
		nxs[st.top()] = n ;
		st.pop() ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		while(st.size() && a[i] < a[st.top()]){
			pvs[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	while(st.size()){
		pvs[st.top()] = -1 ;
		st.pop() ;
	}
	for(int i = 0 ; i < n ; i++){
		p[i].first = pvs[i] + 1 ;
		p[i].second = nxs[i] - 1 ;
	}
}

void setval(map<int,int> &mxf , map<int,int> &mxs , int *a , int n){
	int cmax = 0 , cr = 0 ;

	for(int i = 0 ; i < n ; i++){
		mxf[a[i]] = mxs[a[i]] = -1 ;
	}

	for(int i = 0 ; i < n ; i++){
		cmax = max(cmax , a[i]) ;
		mxf[cmax] = i ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		cr = max(cr , a[i]) ;
		mxs[cr] = i ;
	}
}

int g1(vector<int>& v , int l , int r){
	int lo = 0 , hi = v.size() - 1 ;
	while(lo <= hi){
		int mid = lo + hi >> 1 ;
		if(v[mid] <= r){
			return 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	return 0 ;
}

int g2(vector<int>& v , int l , int r){
	int lo = 0 , hi = v.size() - 1 ;
	while(lo <= hi){
		int mid = lo + hi >> 1 ;
		if(v[mid] >= l){
			return 1 ;
		} else {
			lo = mid + 1 ;
		}
	}
	return 0 ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int a[n] ;
		map<int , vector<int>> mp ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			mp[a[i]].push_back(i) ;
		}
		map<int , int> mxf , mxs ;
		pair<int,int> p[n] ;
		solve(p , a , n) ;
		setval(mxf , mxs , a , n) ;
		pair<int,int> ans(-1 , -1) ;
		for(int i = 1 ; i < n - 1 ; i++){
			int x = p[i].first , y = p[i].second ;
			int lmax = mxf[a[i]] , rmax = mxs[a[i]] ;
			if(lmax == -1 || rmax == -1) continue ;
			if(x > (lmax + 1) || y < (rmax - 1)) continue ;
			int id1 = g1(mp[a[i]] , 0 , min(i - 1 , lmax)) ;
			int id2 = g2(mp[a[i]] , max(i + 1 , rmax) , n - 1) ;
			if(id1 && id2){
				ans = {min(i - 1 , lmax) , max(i + 1 , rmax)} ;
				break ;
			}
		}
		if(~ans.first){
			cout << "YES\n" ;
			cout << ans.first + 1 << " " << ans.second - ans.first - 1 << " " << n - ans.second << '\n' ;
		} else {
			cout << "NO\n" ;
		}
	}
	return 0 ;
}

