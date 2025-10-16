#include <stdio.h>
#include <string.h>

#define N_STUD 5
#define N_SUBJ 3
#define MAX_NAME 50

int main(void) {
    double notas[N_STUD][N_SUBJ] = {0};
    char est[N_STUD][MAX_NAME] = {{0}};
    char mat[N_SUBJ][MAX_NAME] = {{0}};
    int i, j, op;

    for (j = 0; j < N_SUBJ; j++) sprintf(mat[j], "Asignatura %d", j + 1);

    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Nombre estudiante\n");
        printf("2. Ingresar notas\n");
        printf("3. Resultados por estudiante\n");
        printf("4. Resultados por asignatura\n");
        printf("5. Cambiar nombre asignatura\n");
        printf("6. Salir\n");
        printf("Opción: ");
        scanf("%d", &op);
        while (getchar() != '\n');

        if (op == 1) {
            for (i = 0; i < N_STUD; i++)
                printf("%d. %s\n", i + 1, strlen(est[i]) ? est[i] : "(vacío)");
            printf("Número: ");
            scanf("%d", &i);
            while (getchar() != '\n');
            if (i >= 1 && i <= N_STUD) {
                printf("Nombre: ");
                fgets(est[i - 1], MAX_NAME, stdin);
                est[i - 1][strcspn(est[i - 1], "\n")] = 0;
            }
        }

        else if (op == 2) {
            for (i = 0; i < N_STUD; i++) {
                if (!strlen(est[i])) continue;
                printf("\nNotas para %s:\n", est[i]);
                for (j = 0; j < N_SUBJ; j++) {
                    double v;
                    do {
                        printf("%s (0-10): ", mat[j]);
                        if (scanf("%lf", &v) != 1) { while (getchar() != '\n'); v = -1; }
                    } while (v < 0 || v > 10);
                    notas[i][j] = v;
                }
                while (getchar() != '\n');
            }
        }

        else if (op == 3) {
            for (i = 0; i < N_STUD; i++) {
                if (!strlen(est[i])) continue;
                double s = 0, mx = -1, mn = 11;
                for (j = 0; j < N_SUBJ; j++) {
                    double v = notas[i][j];
                    s += v;
                    if (v > mx) mx = v;
                    if (v < mn) mn = v;
                }
                printf("%s: Prom %.2f Max %.2f Min %.2f\n", est[i], s / N_SUBJ, mx, mn);
            }
        }

        else if (op == 4) {
            for (j = 0; j < N_SUBJ; j++) {
                double s = 0, mx = -1, mn = 11; int apr = 0;
                for (i = 0; i < N_STUD; i++) {
                    double v = notas[i][j];
                    s += v;
                    if (v > mx) mx = v;
                    if (v < mn) mn = v;
                    if (v >= 6) apr++;
                }
                printf("%s: Prom %.2f Max %.2f Min %.2f Aprob %d Reprob %d\n",
                       mat[j], s / N_STUD, mx, mn, apr, N_STUD - apr);
            }
        }

        else if (op == 5) {
            for (j = 0; j < N_SUBJ; j++) printf("%d. %s\n", j + 1, mat[j]);
            printf("Número: ");
            scanf("%d", &j);
            while (getchar() != '\n');
            if (j >= 1 && j <= N_SUBJ) {
                printf("Nuevo nombre: ");
                fgets(mat[j - 1], MAX_NAME, stdin);
                mat[j - 1][strcspn(mat[j - 1], "\n")] = 0;
            }
        }

        else if (op == 6) {
            break;
        }

    } while (1);

    return 0;
}
