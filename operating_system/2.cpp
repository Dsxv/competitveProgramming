#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct process{
	int id , burst_time , arv_time , turn_around ;
}

bool check(process p1 , process p2){
	if(p1.arv_time != p2.arv_time) return p1.arv_time < p2.arv_time ;
	else return p1.burst_time < p2.burst_time ;
}

int32_t main(){
	int n ;
	cout << "Enter no. of process: "; cin >> n;
	process p[n] ;
	for(int i = 0 ; i < n ; i++){
		cout << "Enter id , arrival time  and burst_time : " ;
		cin >> p[i].id >> p[i].burst_time >> p[i].arv_time ;
	}
	int current_time =  0 ;
	sort(p,p+n,check) ;
	cout << "Process id 	| 	Arrival_Time 	|	Burst_Time	|	Turn_Around_Time	| Waiting_time
	return 0 ;
}

