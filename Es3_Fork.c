
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;

    printf("Nonno: inizio. PID = %d\n", getpid());
    fflush(stdout);

    pid = fork();

    if (pid == 0) {
        // Processo Padre
        printf("Padre: inizio. PID = %d\n", getpid());
        fflush(stdout);

        pid = fork();

        if (pid == 0) {
            // Processo Nipote
            printf("Nipote: inizio. PID = %d\n", getpid());
            fflush(stdout);

            printf("Nipote: termino.\n");
            return 0;
        }
        else if (pid > 0) {
            // Il Padre aspetta il Nipote
            wait(NULL);
            printf("Padre: termino.\n");
        }
    }
    else if (pid > 0) {
        // Il Nonno aspetta il Padre
        wait(NULL);
        printf("Nonno: termino.\n");
    }

    return 0;
}
