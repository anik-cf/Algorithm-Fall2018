#include<bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define MAX 10000007
#define PI acos(-1)
#define pb(x) push_back(x)
#define inpll(a) scanf("%lld",&a)
#define vi vector<int>
#define pi(x, y) pair<x, y> 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
 
/*
	Anik Chakrabortty
	Southeast University 
	Dhaka Bangladesh
	Preparation Set Fall 2018

*/ 


using namespace std;
 

vector<pi(double, pi(int, int))>dataSet;


double fractional_knapsack(vector<pi(double, pi(int, int))>dataSet, 
						int target, int inputSize)

{

	int currWeight = 0; 
	double currValue = 0; 

	for(int i=inputSize-1; i>=0; i--){

		if(currWeight+dataSet[i].second.first <= target){
			currWeight += dataSet[i].second.first;
			currValue += dataSet[i].second.second;
		}
		else{

			int remain = target - currWeight; 
			currValue += dataSet[i].second.second * 
						((double)remain / dataSet[i].second.first); 
			currWeight += remain; 
			break; 

		}

	}
	//cout << currWeight << endl; 

	return currValue;
}



int main()
{
   
    //READ("in.txt");
    //WRITE("out.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);

    int S, N; 
    cin >> S >> N; 

    for(int i=0; i<N; i++){
    	int W, V; 
    	cin >> W >> V; 
    	dataSet.push_back(make_pair(((double)V/W), make_pair(W, V))); 
    }

    sort(dataSet.begin(), dataSet.end()); 

    for(int i=N-1; i>=0; i--)
    	cout << dataSet[i].first << " " << dataSet[i].second.first << " " << dataSet[i].second.second << endl; 

    cout << fractional_knapsack(dataSet, S, N) << endl; 


    return 0; 
}