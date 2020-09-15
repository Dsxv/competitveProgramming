#include <bits/stdc++.h> 
using namespace std; 
  
map<int , string> mp = { { 1 , "MON"} ,
	{2 , "TUE"} , {3 , "WED"} , {4 , "THU"} ,
	{5 , "FRI"} , {6 , "SAT"} , {7 , "SUN"} } ;

int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}  
  
int main()  
{ 
	
	int x , y ;
	cin >> x >> y ;
    int day = dayofweek(y, x, 2020); 
	cout << mp[day] ;
    return 0;  
}  

