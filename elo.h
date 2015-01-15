/* 
 * Calculate effective number of games for a player
 *
 * r:	Current rating
 * n:	Total rated games played
 */
double effective_games(double r, int n);

/* 
 * Calculate the probability a player with R1 rating beats a player with R2
 *
 * r1:  Player 1 rating
 * r2:  Player 2 rating
 */
double win_expectancy(double r1, double r2);

/* 
 * Calculate the expected score for a player
 *
 * r:           Current rating
 * opponents:   Pointer to array of opponents ratings
 * size:        Length of opponents array
 */
double expected_score(double r, double *opponents, int size);

/* 
 * Calculate the K factor used in rating change calculations
 *
 * n:   Effective games played
 * m:   Games in Event (equivalent to size of opponents array)
 */
double k_factor(double n, int m);

/* 
 * Calculate the rating change of a player
 *
 * k:   K factor
 * s:   Total score
 * e:   Expected score
 */
double rating_change(double k, double s, double e);

/* 
 * Calculate the bonus rating change of a player
 *
 * rating_change:	K factor
 * m:               Games in Event (equivalent to size of opponents array)
 */
double bonus_rating_change(double rating_change, int m);

/* 
 * Calculate the total rating change (normal + bonus) of a player
 *
 * rating_change:   K factor
 * m:               Games in Event (equivalent to size of opponents array)
 */
double total_rating_change(double k, double s, double e, int m);

