#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double periodFormula(double frequency) {
    double period = 1 / frequency;
    printf("The result of the period is %.2f seconds\n", period);
    return period;
}

void speedFormula(double frequency, double amplitude, double time) {
    double angularSpeed = 2 * M_PI * frequency;
    double linearSpeed = -amplitude * angularSpeed * sin(angularSpeed * time);

    printf("The angular speed is %.2f rad/seconds\n", angularSpeed);
    printf("The linear speed is %.2f meter/seconds\n", linearSpeed);
}


void pendulumFormula(double length_) {
    double angularSpeed = sqrt(9.8 / length_);
    double period = 2 * M_PI * sqrt(length_ / 9.8);

    printf("The angular speed is %.2f rad/seconds\n", angularSpeed);
    printf("The period is %.2f seconds\n", period);
}


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void pause() {
    printf("Press Enter to go back to the menu...");
    getchar();
}

int main() {
    double frequency, amplitude, time, length_;
    char option;
    int quit;

    while (1) {
        system("cls"); 

        printf("##### SIMPLE HARMONIC MOTION CALCULATOR #####\n");

        char list[3][100] = {
            "The object that you're working with is a:\n",
            "[A] regular object in Simple Harmonic Motion\n",
            "[B] object attached in a pendulum in Simple Harmonic Motion\n"
        };

        for (int i = 0; i < 3; i++) {
            printf("%s", list[i]);
        }

        printf("Choose an option [A] or [B]: ");
        scanf(" %c", &option);

        if (option == 'A') {
            printf("Please, insert the value of the frequency in Hz: ");
            scanf("%lf", &frequency);

            printf("Please, insert the value of the amplitude in meters: ");
            scanf("%lf", &amplitude);

            printf("Please insert the value of the time in seconds: ");
            scanf("%lf", &time);

            periodFormula(frequency);
            speedFormula(frequency, amplitude, time);

            clearBuffer(); 
            pause();
        } 
        else if (option == 'B') {
            printf("Please, insert the value of the pendulum length in meters: ");
            scanf("%lf", &length_);

            pendulumFormula(length_);

            clearBuffer();
            pause();
        } 
        else {
            printf("Type just 'A' or 'B'\n");
            continue;
        }

        printf("\nInsert '1' to quit or '2' to continue: ");
        scanf("%d", &quit);

        if (quit == 1) {
            break;
        } 
        else if (quit == 2) {
            continue;
        } 
        else {
            printf("Insert just '1' or '2'\n");
            continue;
        }
    }

    return 0;
}