#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<bits/stdc++.h>
 
using namespace std;
char grid[51][51];
int h,w;
int dx[8] = {1, -1, 0, 0, 1,-1, 1, -1};
int dy[8] = {0, 0, 1, -1,-1, 1, 1, -1};
int vis[51][51];
int sum;

int dfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0 ; i < 8 ;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx>=0 && yy>=0 && xx < h && yy < w && vis[xx][yy] == 0 && grid[xx][yy] == (char)grid[x][y]+1){	
			sum++;
			dfs(xx, yy);
		}
	}
	return sum;
}

int main(){
	int k = 0;
	while(cin>>h>>w, h!=0, w!=0){
		k++;
		vector< pair <int, int> > vect;
		for(int i = 0 ; i < h ; i++)
			for(int j = 0; j < w; j++)
				vis[i][j] = 0;
				
		for(int i = 0 ;i < h ; i++){
			for(int j = 0 ; j < w ; j++){
				cin>>grid[i][j];
				if(grid[i][j] == 'A')
					vect.push_back(make_pair(i, j));
			}
		}
		int ans = 0;
		int i = 0;
		while(!vect.empty()){
			sum = 1;
			ans = max(ans, dfs(vect[i].first, vect[i].second));
			vect.pop_back();
			i++;
		}
		printf("Case %d: %d\n", k, ans);
	}	
	
}
