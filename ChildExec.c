#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//Leslie McCarthy DNET3
int main (){   
    
    pid_t pid = getpid();
    pid_t childpid;   
    childpid = fork(); 
    
    if (childpid < 0){
        perror("\nfork failed");
    }  
    
    if(childpid == 0){
       
        printf("CHILD: PROCESS PID IS %d\n", pid);       
        execlp("Process to exe", "", (char *)0);
        
        
       //If the child process reaches this point, then 
        //execlp must have failed. 
       return 1;
   
    }    
    
    if (childpid != wait(NULL)){
        perror("\nParent failed to wait due to signal or error");
        
    } 
    else  
        printf("\nPARENT: PROCESS PID IS %d\n", pid);
        execlp("ls", "ls", "-al", "/bin", (char *)0);
       
    
    return 0;
}
