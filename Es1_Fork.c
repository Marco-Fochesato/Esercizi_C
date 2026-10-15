#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= 5; i++) {
            printf("Figlio: %d\n", i);
            sleep(1);
        }
    }
    else if (pid > 0) {
        wait(NULL);

        for (int i = 6; i <= 10; i++) {
            printf("Padre: %d\n", i);
            sleep(1);
        }

    }else {
        printf("Errore nella fork\n");
        return 1;
    }
    return 0;
}
    