#include<stdio.h>
#include<unistd.h>

int main(){
    int p[2];
    int returnstattus;
    char writmsg[2][25] = {"Operating ", "System"};
    char readmsg[25];
    
    returnstattus = pipe(p);
    
    if(returnstattus ==1 ){
        printf("Pipe not created");
    }else{
        printf("Writing into pipe msg = %s\n ", writmsg[1]);
        write(p[1],writmsg[1], sizeof(writmsg[1]));
         printf("Writing into pipe msg = %s\n ", writmsg[0]);
        write(p[1],writmsg[0], sizeof(writmsg[0]));
        
        
        for(int i =0 ;i<2;i++){
            read(p[0], readmsg , sizeof(readmsg));
            printf("Reading from pipe - msg = %s\n", readmsg);
        }
        return 0;
    }
}
/*--------------------------------
Output
Writing into pipe msg = System
 Writing into pipe msg = Operating 
 Reading from pipe - msg = System
Reading from pipe - msg = Operating */
