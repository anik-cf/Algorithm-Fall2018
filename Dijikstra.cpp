#include<bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define MAX 10000007
#define PI acos(-1)
#define pb(x) push_back(x)
#define inpll(a) scanf("%lld",&a)
#define vi vector<int>
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
 
/*
	Anik Chakrabortty
	Southeast University 
	Dhaka Bangladesh
	Preparation Set Fall 2018

*/ 


using namespace std;


// TEST CASE 

int V=9;

int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 



int minDistance(int dist[], bool sp[], int V){
	
	int mini = INT_MAX, min_idx; 

	for(int i=0; i<V; i++){
		if(sp[i]==false && dist[i]<=mini)
			mini=dist[i], min_idx=i; 
	}
	return min_idx; 

}


void printSolution(int arr[], int Size){
	for(int i=0; i<Size; i++){
		cout << "Vertex " << i << " --- Distance from source: " << arr[i] << endl; 
	}
}


void dijkstra(int src, int V)
{
	int distance[V];
	bool isProcessed[V];

	for(int i=0; i<V; i++)
		distance[i]=INT_MAX, isProcessed[i]=false; 

	distance[src]=0; 

	for(int i=0; i<V-1; i++){
		int u = minDistance(distance, isProcessed, V);

		isProcessed[u]=true; // now processed 

		for(int j=0; j<V; j++){
			if(graph[u][j] && distance[u]+graph[u][j]<distance[j]){
				distance[j]=distance[u] + graph[u][j]; 
			}
		} 
	}

	printSolution(distance, V); 
}

int main()
{
   
    //READ("in.txt");
    //WRITE("out.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);


    dijkstra(0, V); 

    return 0; 
}


