#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;
vector <vector <double> > dist;
int n;

int main()
{
	int d = 0;
	int t;
	cin >> t;
	while (t--){
		dist = vector < vector <double> > (105, vector <double> (105, INF));
		cin >> n;
		double x[105], y[105];
		
		for (int i = 0; i < n; i++)
			cin >>x[i] >>y[i];
		
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < n; j++){
		  	if (i == j) dist[i][j] = 0;
		  	else{
		  		double tmp = sqrt (pow(x[i]-x[j], 2) + pow(y[i] - y[j], 2));
		  		if (tmp <= 10) dist[i][j] = tmp;
			}
		  }
		
		for (int k = 0; k < n; k++)
	      for (int i = 0; i < n; i++)
	        for (int j = 0; j < n; j++)
		      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		cout <<"Case #"<<++d<<":"<<endl;
		
		double ans = 0;
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < n; j++)
		    ans = max(ans, dist[i][j]);
		
		if (ans == INF)
		  cout<<"Send Kurdy"<<endl;
		else
		  printf("%.4lf\n", ans);
		cout<<endl;
	}
	return 0;
}
