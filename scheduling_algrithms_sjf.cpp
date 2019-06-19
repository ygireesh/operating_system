
#include <iostream>
using namespace std;
int main() {
cout<<"Enter the number of processes\n";
int no_of_processes;
cin>>no_of_processes;
int i;
cout<<"\nEnter the names of processes\n";
char processes_names[no_of_processes];
for(i=0;i<no_of_processes;i++){
  cin>>processes_names[i];
}
cout<<"\n Enter their respective burst times\n";
int burst_time[no_of_processes];
for(i=0;i<no_of_processes;i++){
  cin>>burst_time[i];
}
//sorting the processes and their respective burst times
int j,bt,pn;
for(i=0;i<no_of_processes-1;i++){
  for(j=0;j<no_of_processes-1;j++){
    if(burst_time[j]>burst_time[j+1]){
      pn=processes_names[j];
      processes_names[j]=processes_names[j+1];
      processes_names[j+1]=pn;
      bt=burst_time[j];
      burst_time[j]=burst_time[j+1];
      burst_time[j+1]=bt;
    }
  }
} 
int waiting_time[no_of_processes];
waiting_time[0]=0;int sum=0;
float total_waiting_time=0,total_tt_time=0;
for(i=1;i<no_of_processes;i++){
  sum=sum+burst_time[i-1];
  waiting_time[i]=sum;
  total_waiting_time=total_waiting_time + waiting_time[i];
}
int turn_around_time[no_of_processes];
for(i=0;i<no_of_processes;i++){
  turn_around_time[i]=waiting_time[i]+burst_time[i];
  total_tt_time=total_tt_time + turn_around_time[i];
}
cout<<"\nThe gantt chat is: ";
for(i=0;i<no_of_processes;i++){
  cout<<processes_names[i]<<" ";
}
cout<<"\n Their respective waiting times are :\n";
for(i=0;i<no_of_processes;i++){
  cout<<waiting_time[i]<<" ";
}
cout<<"\n Their respective turn arround times are :\n";
for(i=0;i<no_of_processes;i++){
  cout<<turn_around_time[i]<<" ";
}
cout<<"\nThe average waiting time is "<<total_waiting_time/no_of_processes;
cout<<"\n The average tun around time is "<<total_tt_time/no_of_processes;
return 0;
}