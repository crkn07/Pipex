# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

int main(int argc, char **argv, char **envp)
{
    if (!*envp && access(argv[1], X_OK) == -1)
        printf("Command is wrong\n");
    else
        printf("Command is right\n");
    return (0);
}