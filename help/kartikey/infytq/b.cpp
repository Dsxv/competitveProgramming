#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string str ;
	getline(cin , str) ;
	vector<int> v; 
    stringstream ss(str); 
    for (int i; ss >> i;) { 
        v.push_back(i); 
        if (ss.peek() == ',') 
            ss.ignore(); 
    } 
	sort(v.begin() , v.end()) ;
	map<int,int> mp ;
	vector<int> a;
	for(auto i : v){
		if(mp[i] < 4){
			mp[i]++ ;
			a.push_back(i) ;
		} 
	}
	int innum ; cin >> innum ; // innum
	int n = a.size() ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			for(int k = j+1 ; k < n ; k++){
				for(int l = k + 1 ; l < n ; l++){
					if(a[i] + a[j] + a[k] + a[l] == innum){
						count++ ;
					}
				}
			}
		}
	}
	if(count){
		cout << count ;
	} else {
		cout << -1 ;
	}
	return 0 ;
}

