#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm> //Use for the sort function
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
using namespace std;

int main(){
    int m;
    cout<<"Enter number of processes: ";
    cin>>m;

    int n,k=1,t,b=0,min,temp[m],bt[m],wt[m],at[m],pr[m],tat[m];
    float awt=0,atat=0;
    for(int i=0;i<m;i++){
        cout<<"\nEnter burst time of process"<<i+1<<": ";
        cin>>bt[i];
        cout<<"\nEnter arrival time of process"<<i+1<<": ";
        cin>>at[i];
        cout<<"\nEnter priority number of process"<<i+1<<": ";
        cin>>pr[i];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(at[i]<at[j]){
                t=at[j];
                at[j]=at[i];
                at[i]=t;

                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }

    for(int j=0;j<m;j++){
        b+=bt[j];
        min=bt[k];
        for(int i=k;i<m;++i){
            min=pr[k];
            if(b>=at[i]){
                if(pr[i]<min){
                    t=at[k];
                    at[k]=at[i];
                    at[i]=t;

                    t=bt[k];
                    bt[k]=bt[i];
                    bt[i]=t;

                    t=pr[k];
                    pr[k]=pr[i];
                    pr[i]=t;
                }
            }
        }
        k++;
    }
    temp[0]=0;
    cout<<"\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for(int i=0;i<m;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        cout<<i+1<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<pr[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time: "<<awt/m;
    cout<<"\nAverage Turnaround Time: "<<atat/m;
}
