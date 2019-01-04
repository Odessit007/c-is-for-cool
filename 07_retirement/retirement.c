#include <stdio.h>
#include <stdlib.h>


struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};

typedef struct _retire_info retire_info;

double collect(int startAge, double initial, retire_info info) {
    double balance = initial;
    int age = startAge;
    for (int i = 0; i < info.months; i++) {
        int years = age / 12;
        int months = age % 12;
        printf("Age %3d month %2d you have $%.2lf\n", years, months, balance);

        double percent = balance * info.rate_of_return;
        balance += percent + info.contribution;
        age += 1;
    }
    return balance;
}

void retirement (int startAge,              // in months
                 double initial,            // initial savings in dollars
                 retire_info working,       // info about working
                 retire_info retired) {     // info about being retired
    double balance = collect(startAge, initial, working);
    startAge += working.months;
    collect(startAge, balance, retired);
}

int main(void) {
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045 / 12;

    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01 / 12;

    int age = 327;
    double savings = 21345;

    retirement(age, savings, working, retired);
    return EXIT_SUCCESS;
}

