
highest(sky).
moving(car).

adj-to(car,road).
adj-to(road,grass).
adj-to(road,trees).
adj-to(sky,trees).
adj-to(grass,trees).

adjacent-to(X,Y) :- adj-to(X,Y).
adjacent-to(X,Y) :- adj-to(Y,X).

goal([R1,R2,R3,R4,R5,R6]) :-
	highest(R1),
	moving(R5),
	adjacent-to(R1,R2),
	adjacent-to(R2,R6),
	adjacent-to(R2,R3),
	adjacent-to(R3,R4),
	adjacent-to(R2,R4),
	adjacent-to(R4,R6),
	adjacent-to(R4,R5),
	write('region 1 is bound to    '),write(R1),nl,
	write('region 2 is bound to    '),write(R2),nl,
	write('region 3 is bound to    '),write(R3),nl,
	write('region 4 is bound to    '),write(R4),nl,
	write('region 5 is bound to    '),write(R5),nl,
	write('region 6 is bound to    '),write(R6),nl,nl,
	fail.

