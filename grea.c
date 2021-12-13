#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/time.h>
#include<math.h>
#define fname "grea.csv"
int N;
int h=1;
int count=0;
typedef struct{
  int s;
  int e;
  int dis;
}node;
 

int connect_check(int s,int **adjacent){
  int i,j,*YetToVisit,now,pop;
    YetToVisit=(int *)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
    YetToVisit[i]=0;
    now=pop=s;
  for(i=0;i<=count;i++){ 
    YetToVisit[now]++;
    for(j=0;j<N;j++){
	if(adjacent[pop][j]==1 &&now!=j){
	  
	  now=pop;
	  pop=j;
	  break;
	
      }
    }
    if(YetToVisit[pop]==2 && N!=i+1)
	return 2;
  }
    for(i=0;i<N;i++){
      if(YetToVisit[i]==0)
	break;
    }
    if(i==N && YetToVisit[s]==2)
      h=0;
  
  free(YetToVisit);
  return(1);
  }

int main(void){
  int *loc;
  srand48(5);
  int s,e;
   node *nodes;
   int i=0,j,r,k=0,rr;
  struct timeval start,end;
  int *jisuu;
   node temp;
  int ansdis=0;
  double t,ta=0.0;
  int **adjacent;
   FILE *fp;
    int rad[254]={0};
 while(i<254){
   rr=(int)((drand48()*9999)+1);
    printf("%d\n",i);
   for(j=0;j<i;j++){
     if(rr==rad[j])
       break;
   }
   if(j==i){
     rad[i]=rr;
     i++;
 }
 }
     if((fp=fopen(fname,"w"))==NULL){
    printf("file open error\n");
    exit(1);
  }
      fprintf(fp,"都市数,平均処理時間,距離\n");
   for(N=4;N<255;N+=10){
    nodes=(node *)malloc(sizeof(node)*(N*(N-1)/2));
   loc=(int *)malloc(sizeof(int)*N);
   adjacent=(int **)malloc(sizeof(int *)*N);
   jisuu=(int *)malloc(sizeof(int)*N);
  for(i=0;i<N;i++){
    adjacent[i]=(int *)malloc(sizeof(int)*N);
    jisuu[i]=0;
    loc[i]=rad[i];
    for(j=0;j<N;j++){
        adjacent[i][j]=0;
        }
    }
  for(r=0;r<10;r++){
    h=1;
    for(i=0;i<N;i++){
      jisuu[i]=0;
      for(j=0;j<N;j++){
      adjacent[i][j]=0;
      }
    }
    count=k=ansdis=0;
   gettimeofday(&start,NULL);
  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      nodes[k].dis=sqrt(pow(loc[i]/100-loc[j]/100,2)+pow(loc[i]%100-loc[j]%100,2));
      nodes[k].s=i;
      nodes[k].e=j;
      k++;
    }
  }
  for(i=0;i<N*(N-1)/2;i++){
    for(j=i+1;j<N*(N-1)/2;j++){
      if(nodes[i].dis>nodes[j].dis){
	temp=nodes[i];
	nodes[i]=nodes[j];
	nodes[j]=temp;
      }
    } 
  }
  i=0;
  while(h!=0){
     h=1;
    
	 if(jisuu[nodes[i].s]<2 && jisuu[nodes[i].e]<2){
     
	  adjacent[nodes[i].s][nodes[i].e]=adjacent[nodes[i].e][nodes[i].s]=1;
	  jisuu[nodes[i].s]= jisuu[nodes[i].s]+1;
	  jisuu[nodes[i].e]=jisuu[nodes[i].e]+1;
	  ansdis+=nodes[i].dis;
	  count++;
    
	 if(connect_check(nodes[i].s,adjacent)!=1 &&h!=0){
        adjacent[nodes[i].s][nodes[i].e]=adjacent[nodes[i].e][nodes[i].s]=0;
	    jisuu[nodes[i].s]--;
	    jisuu[nodes[i].e]--;
	    ansdis-=nodes[i].dis;
	    count--;
	
        }
	}    
i++;   
}
      
gettimeofday(&end,NULL);
t=(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1.0E-6;
printf("%d\n",ansdis);
printf("処理時間は%f\n", (end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1.0E-6 );  
ta+=t; 
}  
ta=ta/10.0;
fprintf(fp,"%d,%f,%d\n",N,ta,ansdis);
ta=0.0;  
} 
 fclose(fp);
  return 0;
}