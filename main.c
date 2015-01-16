#include <stdio.h>
#include "elo.h"

void print_report(double r, int n, double s, double *opponents, int m) {
    printf("============== REPORT ===============\n\n");

    double e_games = effective_games(r, n);
    double k = k_factor(e_games, m);

    printf("Effective Games:  %lf\n", e_games);
    printf("K Factor:         %lf\n\n", k);

    double e_score = 0;
    for(int i = 0; i < m; i++) {
        double win_chance = win_expectancy(r, opponents[i]);
        e_score += win_chance;
        printf("Opponent #%d Win Chance: %lf\n", i+1, win_chance);
    }
    printf("\n");

    printf("Expected Score: %lf\n", e_score);

    double initial_rating_change = rating_change(k, s, e_score);
    char sign = initial_rating_change >= 0 ? '+' : '\0';

    printf("Initial Rating Change: %c%lf\n", sign, initial_rating_change);

    double bonus = bonus_rating_change(initial_rating_change, m);

    printf("Bonus Rating Change: +%lf\n", bonus);
    printf("New Rating: %lf\n", initial_rating_change+bonus);

    printf("\n======================================\n\n");

    printf("Press Any Key to Exit...");
    while(getchar() == '\n');

    return;
}

int main() {
    printf("=======================================\n");
    printf("= = = =  Welcome to ELO Helper  = = = =\n");
    printf("=======================================\n\n");

    double r = -1;
    int n = -1;
    int m = -1;
    double s = -1;

    printf("Current Rating: ");
    scanf("%lf", &r);

    printf("Total Rated Games Played: ");
    scanf("%d", &n);

    printf("Tournament Score: ");
    scanf("%lf", &s);

    printf("Games at Tournament:");
    scanf("%d", &m);

    double opponents[m];

    for(int i = 0; i < m; i++) {
        printf("Opponent #%d Rating: ", i+1);
        scanf("%lf", &opponents[i]);
    }

    printf("\n");

    print_report(r, n, s, opponents, m);

    return 0;
}