/*
Flower garden 1D V4
Rules:
1) The garden consists of 1 row, each with N plantings (N is at least 4).
One flower species occupies each planting. The Row is horizontal
layed out with plantings from 0 at the left to N at the right. You
will use a Prolog list to represent the row.
3) Flowers have Name, Size, Wet/Dry, Color.
2) A given flower species can only be used once per row.
3) No two adjacent plantings can have the same color flower.
5) No two adjacent plantings can have flowers whose size is more than one
size difference. Sizes are small, med, tall so small next to small is
fine, small next to medium is fine, but small next to tall is not.
6) the two outermost plantings (1 and N) are dry, the two innermost are
wet, the ones in between (if there are any) can take either.
*/

flower(daisies, med, wet, yellow).
flower(roses, med, dry, red).
flower(petunias, med, wet, pink).
flower(daffodils, med, wet, yellow).
flower(begonias, tall, wet, white).
flower(snapdragons, tall, dry, red).
flower(marigolds, short, wet, yellow).
flower(gardenias, med, wet, red).
flower(gladiolas, tall, wet, red).
flower(bird_of_paradise, tall, wet, white).
flower(lilies, short, dry, white).
flower(azalea, med, dry, pink).
flower(buttercup, short, dry, yellow).
flower(poppy, med, dry, red).
flower(crocus, med, dry, orange).
flower(carnation, med, wet, white).
flower(tulip, short, wet, red).
flower(orchid, short, wet, white).
flower(chrysanthemum, tall, dry, pink).
flower(dahlia, med, wet, purple).
flower(geranium, short, dry, red).
flower(lavender, short, dry, purple).
flower(iris, tall, dry, purple).
flower(peonies, short, dry, pink).
flower(periwinkle, med, wet, purple).
flower(sunflower, tall, dry, yellow).
flower(violet, short, dry, purple).
flower(zinnia, short, wet, yellow).

size_valid(short,short).
size_valid(med,med).
size_valid(tall,tall).
size_valid(short,med).
size_valid(med,tall).
<<<<<<< HEAD
size_valid(tall,med).
size_valid(med,short).

color_valid(purple,pink).
color_valid(red,pink).
color_valid(yellow,pink).
color_valid(white,pink).

color_valid(pink,purple).
color_valid(red,purple).
color_valid(yellow,purple).
color_valid(white,purple).

color_valid(pink,red).
color_valid(purple,red).
color_valid(yellow,red).
color_valid(white,red).

color_valid(pink,yellow).
color_valid(purple,yellow).
color_valid(red,yellow).
color_valid(white,yellow).

color_valid(pink,white).
color_valid(purple,white).
color_valid(red,white).
color_valid(yellow,white).



=======
size_valid(med,short).
size_valid(tall,med).
>>>>>>> ddcf2b302e1d4010b34341649d66c31fdadd21df

/*
creates the lists for the plan while selecting a flower species for each
spot in the garden
*/

/*
Need to go through and add an appropriate flower to the list N times. This means that
*/

/* base case */
plantassign(0, []).
plantassign(N, [Head | Tail]) :-
    Ndec is N - 1,
    plantassign(Ndec, Tail),
    flower(Head, _, _, _)
.


/*
check to make sure the assignment hasn't violated rules about duplicate
flowers
*/
uniquecheck([]).
uniquecheck([Head | Tail]) :-
  \+ member(Head, Tail),
  uniquecheck(Tail)
.

<<<<<<< HEAD
=======

>>>>>>> ddcf2b302e1d4010b34341649d66c31fdadd21df
/*
check to make sure color rules are kept
*/
colorcheck([_]).
colorcheck([]).
<<<<<<< HEAD
colorcheck([Head, Next | Tail]) :-
  flower(Head,_,_,C),
  flower(Next,_,_,C1),
  color_valid(C,C1),
  colorcheck([Next | Tail])
.


/* check to be sure size rules are followed */
sizecheck([]).
sizecheck([_]).
sizecheck([Head, Next | Tail]) :-
  flower(Head,S,_,_),
  flower(Next,S1,_,_),
  size_valid(S,S1),
  sizecheck([Next | Tail])
.


wetcheck_first([Last]) :-
  flower(Last,_,W,_),
  W = dry
=======
colorcheck([Head | [Head1 | Tail]]) :-
  /*append(Tail, Head1, L),*/
  flower(Head,_,_,C),
  flower(Head1,_,_,C1),
  C = C1,
  colorcheck(Tail)
.


/*
check to be sure size rules are followed
*/
sizecheck([]).
sizecheck([Head | [Head1 | Tail]]) :-
  flower(Head,S,_,_),
  flower(Head1,S1,_,_),
  size_valid(S,S1).
  sizecheck(Tail)
.



/*
make sure wet/dry rules are followed
*/
wetcheck(0,[]).
wetcheck(N, [Head | Tail]) :-
  Ndec is N - 1,
  flower(Head,_,W,_),
  wetcheck(Ndec, Tail)
>>>>>>> ddcf2b302e1d4010b34341649d66c31fdadd21df
.

wetcheck_center(0, [Head | _]) :-
  flower(Head,_,wet,_)
.

/* M is the index to check */
wetcheck_center(N, [_ | Tail]) :-
  N > 0,
  Ndec is N - 1,
  wetcheck_center(Ndec,Tail)
.

wetcheck_end(_,[Last]) :-
  flower(Last,_,W,_),
  W = dry
.

wetcheck_end(N, [_ | Tail]) :-
  Ndec is N - 1,
  wetcheck_end(Ndec, Tail)
.

/* make sure wet/dry rules are followed */
wetcheck(_,[]).

wetcheck(N, [Head | Tail]) :-
  /* first */
  wetcheck_first([Head]),

  wetcheck_center(N - (N / 2), [Head | Tail]),
  wetcheck_center(N - (N / 2 + 1), [Head | Tail]),

  wetcheck_end(N, Tail)
.


/* write complete garden plan */
writegarden([]) :- write("|"), nl.
writegarden([Head | Tail]) :-
  write("|"), write(Head),
  writegarden(Tail)
.

/* assign plants and check rules, then print the plan. */
<<<<<<< HEAD
gardenplan(N,List) :-
=======
gardenplan(0,_).
gardenplan(N, List) :-
>>>>>>> ddcf2b302e1d4010b34341649d66c31fdadd21df
    write('Starting garden planner...'), nl,

    plantassign(N, List),
    uniquecheck(List),
    colorcheck(List),
    sizecheck(List),
<<<<<<< HEAD
    wetcheck(N,List),
=======
    /* wetcheck(N, List),*/
>>>>>>> ddcf2b302e1d4010b34341649d66c31fdadd21df
    writegarden(List)
.


/*
The list in each argument is the same. There is a list of N plantings.
The "plantassign" should fill in the flowers of a candidate plan, and then
the various "check" predicates verify the rules.
*/
