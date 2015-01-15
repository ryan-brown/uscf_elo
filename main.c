#include <stdio.h>
#include "elo.h"
 
int main() {
	double r;
	int n;
	int m;
	double s;

	printf("Current Rating: ");
   	scanf("%lf", &r);

   	printf("Total Rated Games Played: ");
   	scanf("%d", &n);

   	printf("Total Score: ");
   	scanf("%lf", &s);

   	printf("Games at Event: ");
   	scanf("%d", &m);

   	double opponents[m];

   	for(int i = 0; i < m; i++) {
   		printf("Opponent #%d Rating: ", i+1);
   		scanf("%lf", &opponents[i]);
   	}

	//double opponents[] = {1430, 1424, 1451, 1502, 1488};

	double e_games = effective_games(r, n);
	double e = expected_score(r, opponents, m);
	double k = k_factor(e_games, m);
	double r_change = rating_change(k, s, e);
	double bonus = bonus_rating_change(r_change, m);

	printf("--------------------\n");

	printf("K Factor: %lg\n", k);
	printf("Expected Score: %lg\n", e);

	char sign = r_change >= 0 ? '+' : '\0';
	printf("New Rating: %lg (%c%lg)", r+r_change+bonus, sign, r_change);
	if(bonus > 0) {
		printf("(+%lg)\n", bonus);
	}
	else {
		printf("\n");
	}

	return 0;
}