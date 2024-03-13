// Created: 2021-04-10 16:00:00
// Author: pmnv

/*
 * Name: La soustraction posée
 * Description: Ce petit programme en c effectue des soustractions en colonnes et permet à l'utilisateur d'utiliser la méthode de regroupement pour résoudre les problèmes.
 * ---------------------------------------------------------------
 * TODO #1: Add the ability to check the user's answer to the correct answer and to provide the explanantion of the correct answer if the user's answer is incorrect
 * TODO #2: Add the ability to allow the user to select the number of problems to generate and solve
 * TODO #3: include the regrouping method in the program (this is a method used to solve subtraction problems with larger numbers)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROBLEMS 5120

typedef struct {
    int top;
    int bottom;
    int userAnswer;
    int resultValue;
} SubtractionProblem;

SubtractionProblem problems[MAX_PROBLEMS];

int totalProblems = 0;
int correctAnswers = 0;
int incorrectAnswers = 0;

// Fonction pour obtenir la réponse de l'utilisateur
int GetUserAnswer() {
    char answer[10];
    while (1) {
        printf("\n==> Veuillez entrer votre réponse: ");
        fgets(answer, sizeof(answer), stdin);
        if (strcmp(answer, "\n") == 0) {
            continue;
        }
        if (strcmp(answer, "fin\n") == 0 || strcmp(answer, "q\n") == 0) {
            return -1;
        }
        int num = atoi(answer);
        if (num == 0 && answer[0] != '0') {
            printf("==> Veuillez entrer une chiffre dans votre réponse: ");
            continue;
        }
        return num;
    }
}

// Generate 5 random subtraction problems from range of 10 to 999 (top number is always greater than bottom number)
void GenerRan() {
    int i;
    for (i = 0; i < 5; i++) {
        problems[i].top = rand() % 999 + 1;
        problems[i].bottom = rand() % (problems[i].top - 1) + 1;
        problems[i].resultValue = problems[i].top - problems[i].bottom;
        problems[i].userAnswer = 0;
        totalProblems++;
    }
}

// print the generated subtraction problems from GenerRan into column format for the user to solve
void PrintProb() {
    int i;
    for (i = 0; i < 5; i++) {
        printf("\n\033[34m==> Problème %d\033[0m\n", i + 1);
        printf("\n");
        printf("   %d\n", problems[i].top);
        printf("-  %d\n", problems[i].bottom);
        printf("------\n");
        printf("   ");
        problems[i].userAnswer = GetUserAnswer();
        if (problems[i].userAnswer == -1) {
            break;
        }
        if (problems[i].userAnswer == problems[i].resultValue) {
            correctAnswers++;
            printf("\033[32m==> Correct!\033[0m\n");
        } else {
            incorrectAnswers++;
            printf("\033[31m==> Incorrect! La réponse correcte est: %d\033[0m\n", problems[i].resultValue);
        }
    }
}


int main() {
    
    srand(time(NULL));
    
    // Into block
    printf(".▄▄ ·       ▄• ▄▌.▄▄ · ▄▄▄▄▄▄▄▄   ▄▄▄·  ▄▄· ▄▄▄▄▄▪         ▐ ▄     \n");
    printf("▐█ ▀. ▪     █▪██▌▐█ ▀. •██  ▄  █·▐█ ▀█ ▐█ ▌▪•██  ██ ▪     •█▌▐█    \n");
    printf("▄▀▀▀█▄ ▄█▀▄ █▌▐█▌▄▀▀▀█▄ ▐█.▪▐▀▀▄ ▄█▀▀█ ██ ▄▄ ▐█.▪▐█· ▄█▀▄ ▐█▐▐▌    \n");
    printf("▐█▄▪▐█▐█▌.▐▌▐█▄█▌▐█▄▪▐█ ▐█▌·▐█•█▌▐█ ▪▐▌▐███▌ ▐█▌·▐█▌▐█▌.▐▌██▐█▌    \n");
    printf(" ▀▀▀▀  ▀█▄▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀ .▀  ▀ ▀  ▀ ·▀▀▀  ▀▀▀ ▀▀▀ ▀█▄▀▪▀▀ █▪    \n");
    printf("·▄▄▄▄  ▄▄▄ .     ▄▄·       ▄▄▌         ▐ ▄  ▐ ▄ ▄▄▄ ..▄▄ ·         \n");
    printf("██▪ ██ ▀▄.▀·    ▐█ ▌▪▪     ██•  ▪     •█▌▐█•█▌▐█▀▄.▀·▐█ ▀.         \n");
    printf("▐█· ▐█▌▐▀▀ ▄    ██ ▄▄ ▄█▀▄ ██▪   ▄█▀▄ ▐█▐▐▌▐█▐▐▌▐▀▀ ▄▄▀▀▀█▄        \n");
    printf("██. ██ ▐█▄▄▌    ▐███▌▐█▌.▐▌▐█▌▐▌▐█▌.▐▌██▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█        \n");
    printf("▀▀▀▀▀•  ▀▀▀     ·▀▀▀  ▀█▄▀▪.▀▀▀  ▀█▄▀▪▀▀ █▪▀▀ █▪ ▀▀▀  ▀▀▀▀         \n");
    printf("");



    // to limit the user input to only "oui" or "non" I set the buffer to 3 characters and then check if the input is "oui" or "non"
    char answer[5];
    do {
        printf("Bienvenue au programme de soustraction de colonnes!\n");
        printf("Pendant le jeu, vous pouvez toujours quitter le programme en tapant \"fin\" ou \"q\"\n");
        printf("Pour commencer, tapez : o / n (oui ou non)\n");
        if (fgets(answer, sizeof(answer), stdin) == NULL ){
            printf("Merci d'avoir utilisé le programme de soustraction de colonnes!\n");
            return 0;
        }
        if (strcmp(answer, "o\n") == 0) {
            // add an option to allow the user to choose the number of problems to generate and solve, if the user does not enter a number then the default number of problems is 5
            printf("Veuillez entrer le nombre de problèmes à resoudre (minimum 6) : ");
            GenerRan();
            PrintProb();
        } else if (strcmp(answer, "n\n") == 0) {
            printf("\nVous aves tapéz : non\nMerci d'avoir utilisé le programme de soustraction de colonnes!\n");
            return 0;
        } else {
            printf("\nVeuillez entrer une réponse valide! (o / n)\n");
        }
    } while (strcmp(answer, "o\n") != 0 && strcmp(answer, "n\n") != 0);

    printf("\nMerci d'avoir utilisé le programme de soustraction de colonnes!\n");
    printf("\033[34m==> %d : Problémes en totale\033[0m\n", totalProblems);
    printf("\033[31m==> %d : Mauvaises réponses.\033[0m\n", incorrectAnswers);
    printf("\033[32m==> %d : Bonnes réponses.\033[0m\n\n", correctAnswers);
    return 0;
}



//   ██████  ▒█████   █    ██   ██████ ▄▄▄█████▓ ██▀███   ▄▄▄       ▄████▄  ▄▄▄█████▓ ██▓ ▒█████   ███▄    █    
// ▒██    ▒ ▒██▒  ██▒ ██  ▓██▒▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒▒████▄    ▒██▀ ▀█  ▓  ██▒ ▓▒▓██▒▒██▒  ██▒ ██ ▀█   █    
// ░ ▓██▄   ▒██░  ██▒▓██  ▒██░░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▒██  ▀█▄  ▒▓█    ▄ ▒ ▓██░ ▒░▒██▒▒██░  ██▒▓██  ▀█ ██▒   
//   ▒   ██▒▒██   ██░▓▓█  ░██░  ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ░██▄▄▄▄██ ▒▓▓▄ ▄██▒░ ▓██▓ ░ ░██░▒██   ██░▓██▒  ▐▌██▒   
// ▒██████▒▒░ ████▓▒░▒▒█████▓ ▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒ ▓█   ▓██▒▒ ▓███▀ ░  ▒██▒ ░ ░██░░ ████▓▒░▒██░   ▓██░   
// ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ░▒ ▒  ░  ▒ ░░   ░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒    
// ░ ░▒  ░ ░  ░ ▒ ▒░ ░░▒░ ░ ░ ░ ░▒  ░ ░    ░      ░▒ ░ ▒░  ▒   ▒▒ ░  ░  ▒       ░     ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░   
// ░  ░  ░  ░ ░ ░ ▒   ░░░ ░ ░ ░  ░  ░    ░        ░░   ░   ░   ▒   ░          ░       ▒ ░░ ░ ░ ▒     ░   ░ ░    
//       ░      ░ ░     ░           ░              ░           ░  ░░ ░                ░      ░ ░           ░    
//                                                                 ░                                            
// ▓█████▄ ▓█████     ▄████▄   ▒█████   ██▓     ▒█████   ███▄    █  ███▄    █ ▓█████   ██████                   
// ▒██▀ ██▌▓█   ▀    ▒██▀ ▀█  ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██ ▀█   █ ▓█   ▀ ▒██    ▒                   
// ░██   █▌▒███      ▒▓█    ▄ ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ▀█ ██▒▓██  ▀█ ██▒▒███   ░ ▓██▄                     
// ░▓█▄   ▌▒▓█  ▄    ▒▓▓▄ ▄██▒▒██   ██░▒██░    ▒██   ██░▓██▒  ▐▌██▒▓██▒  ▐▌██▒▒▓█  ▄   ▒   ██▒                  
// ░▒████▓ ░▒████▒   ▒ ▓███▀ ░░ ████▓▒░░██████▒░ ████▓▒░▒██░   ▓██░▒██░   ▓██░░▒████▒▒██████▒▒                  
//  ▒▒▓  ▒ ░░ ▒░ ░   ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░ ▒░   ▒ ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░                  
//  ░ ▒  ▒  ░ ░  ░     ░  ▒     ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░░ ░░   ░ ▒░ ░ ░  ░░ ░▒  ░ ░                  
//  ░ ░  ░    ░      ░        ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒     ░   ░ ░    ░   ░ ░    ░   ░  ░  ░                    
//    ░       ░  ░   ░ ░          ░ ░      ░  ░    ░ ░           ░          ░    ░  ░      ░                    
//  ░                ░                                                                                          
