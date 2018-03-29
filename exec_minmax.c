#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

int main(int argc, char **argv) 
{
	pid_t pid = fork();

	if ( pid >= 0 ) {
	    if(pid==0){
    		int c = execv( "sequential_min_max", argv);
    		if(c == -1)
    		{
    		    printf("Exec error\n");
    		    return 1;
    		}
	   }
	}
	else {
	    printf("Fork fault\n");
	    return 1;
	}
	
    int status;
	wait(&status);
    if(!WIFEXITED(status)){
        printf("Error exiting child process\n");
        return 1;
    }
	return 0;
}