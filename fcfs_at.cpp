#include<iostream>
using namespace std;

int main(){
    int m;
    cout<<"Enter number of processes: ";
    cin>>m;

    int i,j,n,bt[m],at[m],wt[m],tat[m],temp[m];
    float awt=0,atat=0;
    for(i=0;i<m;i++){
        cout<<"\nEnter burst time of Process "<<i+1<<": ";
        cin>>bt[i];
        cout<<"\nEnter arrival time of Process "<<i+1<<": ";
        cin>>at[i];
    }
    temp[0]=0;
    cout<<"\nP_ID\t\tBT\t\tAT\t\tWT\t\tTAT\n";
    for(i=0;i<m;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time: "<<awt/m;
    cout<<"\nAverage Turnaround Time: "<<atat/m;
    


}
