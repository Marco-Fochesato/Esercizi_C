
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    int pid;

    for (i = 0; i < 3; i++) {
        pid = fork();

        if (pid == 0) {
            // Processo figlio
            printf("Figlio con PID: %d\n", getpid());
            sleep(2);
            return 0;
        }
    }

    // Processo padre
    for (i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("Tutti i figli sono terminati. Padre terminato.\n");

    return 0;
}
