/*
 *Kartik Singal @ ka4tik
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<sstream>
using namespace std;
#define s(x) scanf("%d",&x)
int checkone(vector<int> sol,int index,int n)
{
    int  ret=0;
    for(int i=0;i<n;i++){
        if(i==index)
            continue;
        else if( sol[i] == sol[index]|| 
                sol[i] == sol[index] + (index-i)|| 
                sol[i] == sol[index] - (index-i))
            ret=ret+1;
    }
    return ret;
}
// checks if an assignment is feasible
bool checkit(vector<int> sol){
    int n=sol.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(sol[i] == sol[j]|| 
                    sol[i] == sol[j] + (j-i)|| 
                    sol[i] == sol[j] - (j-i))
                return false ;
        }
    }
    return true; 
}

int toint(string str)
{
    istringstream is(str);
    int x;
    is>>x;
    return x;
}
int main(int argc,char *argv[])
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);


    int n=toint(string(argv[1]));
    //cout<<n<<endl;
    //int n=1000;
    vector<int> sol;
    for(int i=0;i<n;i++) sol.push_back(i);

    while(checkit(sol)==0){
        vector<int> indexes;
        int m=0;
        for(int i=0;i<n;i++)//find the position with maximum voilations 
        {
            int d=checkone(sol,i,n);
            if(d>m)
                m=d;
        }
        for(int i=0;i<n;i++)//find the position with maximum voilations 
        {
            int d=checkone(sol,i,n);
            if(d==m)
                indexes.push_back(i);
        }
        int index=indexes[rand()%indexes.size()];
        int m2=checkone(sol,index,n);
        for(int i=0;i<n;i++)// find the position with minimum voilations  
        {
            sol[index]=i;
            int d=checkone(sol,index,n);
            if(d<m2)
                m2=d;
        }
        indexes.clear();
        for(int i=0;i<n;i++)// find the position with minimum voilations  
        {
            sol[index]=i;
            int d=checkone(sol,index,n);
            if( d==m2)
                indexes.push_back(i);
        }
        int index2=indexes[rand()%indexes.size()];
        sol[index]=index2;
        /*
         *for(int i=0;i<n;i++)
         *    cout<<sol[i]<<" ";
         * cout<<endl;
         */
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<sol[i]<<" ";
    cout<<endl;


    return 0;
}

