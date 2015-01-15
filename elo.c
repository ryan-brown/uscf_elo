#include "elo.h"
#include <math.h>

double effective_games(double r, int n) {

    double e_games = 50/sqrt(0.662+0.00000739*pow((2569-r),2));

    if(n < e_games) {
        return n;
    }
    else {
        return e_games;
    }
}

double win_expectancy(double r1, double r2) {
    return 1/(1+pow(10,-(r1-r2)/400));
}

double expected_score(double r, double *opponents, int size) {
    double e_score = 0;

    for(int i = 0; i < size; i++) {
        e_score += win_expectancy(r, opponents[i]);
    }

    return e_score;
}

double k_factor(double n, int m) {
    return 800/(n+m);
}

double rating_change(double k, double s, double e) {
    return k*(s-e);
}

double bonus_rating_change(double rating_change, int m) {
    if(m < 4) {
        m = 4;
    }

    double bonus = rating_change - 10*sqrt(m);

    if(bonus < 0) {
        return 0;
    }
    else {
        return bonus;
    }
}

double total_rating_change(double k, double s, double e, int m) {
    double r_change = rating_change(k, s, e);
    return r_change + bonus_rating_change(r_change, m);
}
