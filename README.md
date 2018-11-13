# MPG prediction software

## V0

### Data: 
- goals scored by each player: p_g
- matches played by each player: p_m
- total number of matches: M

### Calculations (players):
- average goals scored by each player: a_{p,g} := p_g / p_m
- playing probability: k_p := p_m / M
- scoring probability: s_p := a_{p,g} * k_p

### Calculations (teams):
- how many different players will score: given that each player has a goal scoring probability calculated, 
we can determine how many of them will score at the same time, 
i.e. what is the probability that exactly N of them will score \
algorithm used: \
P in R^{n x n}, where n is the number of players in the team \
P_{0,1} := 1 - s_1 \
P_{1,1} := s_1 \
for k=1..n { \
&nbsp;&nbsp;&nbsp;&nbsp; P_{0,k+1} := P_{0,k} * (1 - s_{k+1}) \
&nbsp;&nbsp;&nbsp;&nbsp; P_{k+1,k+1} := P_{k,k} * s_{k+1} \
&nbsp;&nbsp;&nbsp;&nbsp; j=1..k { \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; P_{j,k+1} := P_{j,k} * (1 - s_{k+1}) + P_{j-1,k} * s_{k+1} \
&nbsp;&nbsp;&nbsp;&nbsp; } \
} \
p := P_{i,n}, i=1..n \
(source: http://www.dtic.mil/dtic/tr/fulltext/u2/a283679.pdf)
- result: p in R^n, where p_i is the probability of exactly i player will score, and n is the number of players in the team

### Calculations (match):
- outcome probabilities, i.e. chance of home team or away team winning and chance of a draw: \
P(h) := sum(i=1..n, p_{i,h} * sum(j=1..(i-1), p_{j,a}) ) \
P(a) := sum(i=1..n, p_{i,a} * sum(j=1..(i-1), p_{j,h}) ) \
P(d) := sum(i=1..n, p_{i,h} * p_{i,a})
- probabilities of the exact results
E in R^{n x m}, where E_i,j corresponds to the probability that home team scores i, and the away team scores j goals, 
and where n and m is the number of players of the home and away team, respectively \
E_{i,j} := p_{i,h) * p_{j,a}
- searching most probable results: listing the 5 most probable exact outcomes: getting the 5 largest probabilities from E

## V1 - Current version

### Extra data:
- starting lineups

### Extra calculations: 
- probability of goal scoring is adjusted by the chance he will actually play in the fantasy team
- // TODO: document algorithm

## V2 - planned

### Extra data:
- average ratings for each player
- tactical substitutions

### Extra calculations: 
- probability of the player actually playing in the fantasy team is adjusted by the chances of tactical substitutions

## V3 - planned

### Extra calculations:
- average rating of each teams defenders, midfielders and strikers
- probability of each player scores a virtual goal

## V4 - planned

### Extra data:
- for all player his ratings at every match

### Extra calculations:
- instead of using average ratings, we can predict the next rating with a stochastic method
