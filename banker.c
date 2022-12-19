#include <stdio.h>

struct process{
    int A,B,C;
};

int main()
{
    int n ,A,B,C ;
    printf("Enter no of process");
    scanf("%d",&n);
    
   struct process allocated[n];
   struct process required[n];
   struct process need[n];
   
   int isexe[n];
   for(int i= 0;i<n;i++) isexe[i]=0;
   int ans[n];
   
   for(int i =0 ;i< n;i++){
       printf("Enter required and allocated resources of p %d : " ,i);
       scanf("%d%d%d", &required[i].A,&required[i].B,&required[i].C);
        scanf("%d%d%d", &allocated[i].A,&allocated[i].B,&allocated[i].C);
        
        need[i].A = required[i].A - allocated[i].A;
        need[i].B = required[i].B - allocated[i].B;
        need[i].C = required[i].C - allocated[i].C;
   }
   
   printf("Enter available resources : ");
   scanf("%d%d%d", &A,&B,&C);
   
   int idx =0;
   for(int i =0 ;i<n;i++){
       for(int j=0;j<n;j++){
           if(isexe[j]==0){
               if(need[j].A<=A, need[j].B<=B,need[j].B<=B){
               
                   A+= allocated[j].A;
                   B+= allocated[j].B;
                   C+= allocated[j].C;
                   
                   ans[idx] = j;
                   idx++;
                   isexe[j] = 1;
                   break;
               }
           }
       }
   }
   
   for(int i = 0 ; i < n ; i++)
    {
        if(isexe[i] == 0)
        {
            printf("No Safe Sequence is Possible");
            return 0;
        }
    }

     printf("The Safe Sequence is - ");
    for(int i = 0 ; i < n-1 ; i++)
    {
        printf("P %d -> ", ans[i]);
    }
    printf("P %d", ans[n-1]);
    return 0;
}


/*--------------------------------------------------------
output:
Enter no of process4
Enter required and allocated resources of p 0 : 7 5 2 4 3 1
Enter required and allocated resources of p 1 : 6 4 3 2 2 2
Enter required and allocated resources of p 2 : 2 8 1 2 2 0
Enter required and allocated resources of p 3 : 5 6 4 2 1 3
Enter available resources : 3 3 2
The Safe Sequence is - P 0 -> P 1 -> P 2 -> P 3
*/
