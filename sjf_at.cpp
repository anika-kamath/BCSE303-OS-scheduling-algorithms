#include<iostream>
#include<climits>
using namespace std;

struct process{
    int pid;
    int at;
    int bt;
    int ct,wt,tat,start_time,rt;
}ps[100];

int findmax(int a,int b){
    return a>b?a:b;
}

int findmin(int a,int b){
    return a<b?a:b;
}

int main(){
    int n;
    bool iscomp[100]={false}, isfirst=true;
    int curr_time=0;
    int comp=0;
    cout<<"Enter number of processes: ";
    cin>>n;
    int sum_tat=0,sum_wt=0,prev=0,lc;
    int max_ct,min_at;

    for(int i=0;i<n;i++){
        cout<<"Enter Burst time for Process "<<i+1<<": ";
        cin>>ps[i].bt;
        cout<<"Enter Arrival time for Process "<<i+1<<": ";
        cin>>ps[i].at;
        ps[i].pid=i;
    }

    while(completed!=n){
        int min_index=-1;
        int min= INT_MAX;
        for(int i=0;i<n;i++){
            if(ps[i].at<=curr_time && iscomp[i]==0){
                if(ps[i].bt<min){
                    min=ps[i].bt;
                    min_index=i;
                }
                if(ps[i].bt==min){
                    if(ps[i].at<ps[min_index].at){
                        min=ps[i].bt;
                        min_index=i;
                    }   
                }
            }
        }
        if(min_index==-1){
            curr_time++;
        }
        else{
            ps[min_index].start_time=curr_time;
            ps[min_index].ct=ps[min_index].start_time+ps[min_index].bt;
            ps[min_index].tat=ps[min_index].ct-ps[min_index].at;
            ps[min_index].wt=ps[min_index].tat-ps[min_index].bt;

            sum_tat+=ps[min_index].tat;
            sum_wt+=ps[min_index].wt;

            comp++;
            iscomp[min_index]=true;
            curr_time=ps[min_index].ct;
            prev=curr_time;
            isfirst=false;
        }
    }

}