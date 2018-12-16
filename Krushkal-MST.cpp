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
 

class UnionFind{
private: vi p, rank; 

public: 
		// constructor
		UnionFind(int N){
			p.assign(N,0);
			rank.assign(N, 0); 
			for(int i=0; i<N; i++)
				p[i]=i; 
		}

		//methods 
		int findSet(int i){
			if(p[i]==i)
				return i; 
			else 
				return p[i]=findSet(p[i]); 
		} 

		bool isSameSet(int i, int j){
			int x = findSet(i), y = findSet(j);
			if(x==y) return true;
			else return false; 
		}

		void unionSet(int i, int j)
		{
			int x = findSet(i), y = findSet(j); 
			if(!isSameSet(i, j))
			{
				if(rank[x]>rank[y]){
					p[y]=x; 
				}else{
					p[x]=y;
					if(rank[x]==rank[y])
						rank[y]++; 
				}
			}

		}

};

int main()
{
   
    //READ("in.txt");
    //WRITE("out.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);

    /*
    Krushkal Input Set

    Graph vertices 
	Number of vertex = 5
    Vertex i, vertex j, cost 
	1           3        5
	1           2        5
	1           4        10
	2           4        5
	3           4        11


    minimum cost : 15
    */

    //[cost, [(u)edge info(v)]]
    vector<pair<int, pair<int, int>>>edgeList; 

    int n;
    cin >> n; 

    int x=n; 

    UnionFind UF(n);

    while(x--){
    	int cost, u, v; 
    	cin >> cost >> u >> v; 

    	edgeList.push_back(make_pair(cost, make_pair(u, v))); 
    }

    sort(edgeList.begin(), edgeList.end()); 

    int mstCost = 0; 

    for(int i=0; i<n; i++)
    {
    	if(!UF.isSameSet(edgeList[i].second.first, edgeList[i].second.second)){
    		UF.unionSet(edgeList[i].second.first, edgeList[i].second.second); 
    		mstCost += edgeList[i].first; 

    		cout << "connecting... " <<
    		edgeList[i].second.first << " and " << edgeList[i].second.second << endl; 
    	}
    }

    cout << mstCost << endl; 


    return 0; 
}