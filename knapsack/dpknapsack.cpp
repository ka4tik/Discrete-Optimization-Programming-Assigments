/*
 *Kartik Singal @ ka4tik
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<cassert>
using namespace std;
#define s(x) scanf("%d",&x)
#define MAXN 1011
#define MAXW 500011
int dp[MAXN][MAXW];
bool pick[MAXN][MAXW];
vector<int> knapSack(int W,vector<int> wt,vector<int> val,int n){

    assert(MAXW>W);
    assert(MAXN>n);
    
    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++){
            if (w==0||i==0)
                dp[i][w]=0;
            else if(wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
                if(val[i-1]+dp[i-1][w-wt[i-1]]>dp[i-1][w])
                    pick[i][w]=1;
            }
            else{ 
                dp[i][w]=dp[i-1][w];
            }
        }
     //cout<<"max values is "<<dp[n][W]<<endl;


    int current=n;
    vector<int> ret;
    while (current>0){
        if(pick[current][W]==1){
            ret.push_back(1);
            W=W-wt[current-1];
            current=current-1;
        }
        else{
            ret.push_back(0);
            current=current-1;

        }
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
int main(int argc,char *argv[])
{
    ifstream file(argv[1]);
    if(!file.is_open())
        cout<<"Could not open file\n";
    else
    {
        int n,capicity;
        file>>n>>capicity;
        vector<int> values(n),wt(n);
        //cout<<n<<" "<<capicity<<endl;
        for(int i=0;i<n;i++)
        {
          file>>values[i]>>wt[i];
          //cout<<values[i]<<" "<<wt[i]<<endl;
        }
        vector<int> ans=knapSack(capicity,wt,values,n);
        int value=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i])
                value+=values[i];
        }
        cout<<value<<" "<<1<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }


    return 0;
}

