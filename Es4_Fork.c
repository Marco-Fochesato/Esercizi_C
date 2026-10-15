
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;
    int numero;
    int status;
    int primo;
    int i;

    pid = fork();

    if (pid == 0) {
        // Processo figlio
        printf("Inserisci un numero intero: ");
        fflush(stdout);
        scanf("%d", &numero);

        // Controllo se il numero è primo
        primo = 1;

        if (numero < 2) {
            primo = 0;
        }
        else {
            for (i = 2; i < numero; i++) {
                if (numero % i == 0) {
                    primo = 0;
                }
            }
        }

        if (primo == 1) {
            return 1;
        }
        else if (numero % 2 == 0) {
            return 2;
        }
        else {
            return 3;
        }
    }
    else if (pid > 0) {
        // Processo padre
        wait(&status);

        int codice = WEXITSTATUS(status);

        if (codice == 1) {
            printf("Il numero inserito è primo ");
        }
        else if (codice == 2) {
            printf("Il numero inserito è pari ma non primo ");
        }
        else if (codice == 3) {
            printf("Il numero inserito è dispari ma non primo");
        }
    }
    else {
        printf("Errore nella fork().\n");
        return 1;
    }

    return 0;
}
