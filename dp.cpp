//
//  main.cpp
//  job-scheduling(DP)
//
//  Created by 黃瑋宸 on 2022/7/6.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
typedef struct activity{
 int time;
 int deadline;
 int order;
}activity;
bool compare(activity a ,activity b){
 return a.deadline<b.deadline;

}
void Scheduling(activity act[],vector<vector<int>> table,int i,int j){
 if (i==0 || j==0){
 return;
 }
 if(table[i][j]==table[i-1][j-1]+act[i-1].time){
 Scheduling(act,table,i-1,j-1);
 if(act[i-1].time<act[i-1].deadline){
 printf("%d ",act[i-1].order);
 }
 }else if(table[i][j]==INT_MAX){
 Scheduling(act,table,i,j-1);
 }
 else{
 Scheduling(act,table,i-1,j);
 }


}
void working(activity act[],int n){

 vector<int> answer;
 sort(act, act+ n,compare);
 vector<vector<int> > table(n+1,vector<int>(n+1,0));


 for(int i=0;i<=n;i++){
 for(int j=0;j<=n;j++){
 if(i<j){
 table[i][j]= INT_MAX;
 }
 }
 }
 for(int i=1;i<=n;i++){
 for(int j=1;j<=n;j++){
 if(table[i-1][j-1]+act[i-1].time<=act[i-1].deadline) {
 if(table[i-1][j-1]!=INT_MAX){
 table[i][j]=min(table[i-1][j],table[i-1][j-1]+act[i-1].time);
 }else{
 table[i][j]=INT_MAX;
 }
 }else{
 table[i][j]=table[i-1][j];
 }
 }
 }
 Scheduling(act,table,n,n);
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
 working(act, n);

 return 0;
}
