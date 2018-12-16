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
 

int main()
{
   
    //READ("in.txt");
    //WRITE("out.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n=4; // number of items 
    int Target = 13; 
    int Weight[] = {5, 6, 8, 4};
    int Value[] = {5, 4, 7, 7}; 

    int dp[5][14];

    for(int i=0; i<=n; i++){
    	for(int M=0; M<=13; M++){
    		if(i==0 || M==0)
    			dp[i][M]=0; 
    		else if(i>0 && Weight[i]<M)
    			dp[i][M] = max(Value[i]+dp[i-1][M-Weight[i]], dp[i-1][M]); // hmm.
    		else
    			dp[i][M] = dp[i-1][M];  

    	}
    } 


    // printing the DP Table 
    for(int i=0; i<5; i++){
    	for(int j=0; j<14; j++)
    		cout << dp[i][j] << " "; 
    	cout << endl; 
    }
    cout << endl << endl; 

    // actual answer: 
    cout << "Max Value: " << dp[n][Target] << endl; 





    return 0; 
}