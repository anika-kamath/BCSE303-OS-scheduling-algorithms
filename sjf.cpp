#include<iostream>
using namespace std;

int main(){
    int m;
    cout<<"Enter number of processes: ";
    cin>>m;
    int i,j,t,p[m],bt[m],wt[m],tat[m];
    float awt=0,atat=0;
    for(i=0;i<m;i++){
        cout<<"Enter burst time of Process "<<i+1<<": ";
        p[i]=i+1;
        cin>>bt[i];
    }

    //bubble sort for burst time
    for(i=0;i<m;i++){
        for(j=0;j<m-i-1;j++){
            if(bt[j]>bt[j+1]){
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    cout<<"\nP_ID\t\tBT\t\tWT\t\tTAT\n";
    for(i=0;i<m;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time: "<<awt/m;
    cout<<"\nAverage Turnaround Time: "<<atat/m;
}