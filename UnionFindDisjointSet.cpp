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
private:
	vi p, rank;
public:
	// constructor

	UnionFind(int N)
	{
		rank.assign(N, 0); 
		p.assign(N, 0);
		for(int i=0; i<N; i++)
		{
		p[i]=i;  // everyone is parent of their own. 
		}

	} // end of constructor 

	// methods
	int findSet(int i){
		if(p[i]==i)
			return i; 
		else 
			return p[i] = findSet(p[i]); 
	}

	bool isSameSet(int i, int j){
		int x = findSet(i);
		int y = findSet(j); 

		if(x==y) return true; 
		else return false; 
	}

	void unionSet(int i, int j)
	{
		if(!isSameSet(i, j)) // only need to join if they are not sameSet
		{
			int x = findSet(i); int y=findSet(j); 

			if(rank[x]>rank[y])
			{
				p[y]=x; 
			}
			else
			{
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

    int N;  

    cin >> N; 
    UnionFind UF(N); 

    while(N--)
    {
    	int x, y; 
    	cin >> x >> y; 
    	UF.unionSet(x, y); 
    }

    int q; 

    cin >> q; 

    while(q--){
    	int x, y; 
    	cin >> x >> y; 

    	if(UF.isSameSet(x, y))
    		cout << x << " " << y << " are same set" << endl; 
    	else 
    	cout << "not same set" << endl; 
    }


    return 0; 
}