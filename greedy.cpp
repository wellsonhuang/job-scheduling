//
//  main.cpp
//  job-scheduling(Greedy)
//
//  Created by 黃瑋宸 on 2022/7/6.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct activity{
 int time;
 int deadline;
 int order;
}activity;
bool compare(activity a ,activity b){
 return a.deadline<b.deadline;

}
void Scheduling(activity a[], int n)
{
 vector<activity> answer;
 sort(a, a + n,compare);
 int totaltime=0;

 for(int i =0; i<n;i++){
 if(a[i].time>a[i].deadline){
 continue;
 }
 answer.push_back(a[i]);
 totaltime += a[i].time;

 if (totaltime >a[i].deadline) {

 int max=answer[0].time,index = 0;

 for(int j=1;j<answer.size();j++){
 if(answer[j].time>max){
 max=answer[j].time;
 index=j;
 }
 }

 totaltime-=max;
 answer.erase(answer.begin()+index);
 }
}
 for (int i=0; i<answer.size(); i++) {
 printf("%d ",answer[i].order);
 }
}
int main(int argc, const char * argv[]) {
 int n,p,d;
 scanf("%d",&n);
 activity *act=(activity*)calloc(n,sizeof(activity));
 for (int i=0; i<n; i++) {
 scanf("%d",&p);
 act[i].time=p;
 scanf("%d",&d);
 act[i].deadline=d;
 act[i].order=i+1;
 }
 Scheduling(act,n);
 return 0;
}
