

% create a value from a list
addit(A, B, C) :- C is A + B.

a([], 0).
a([H | T], V) :- a(T, V2), addit(H, V2, V).

% a([1,2,3,4,5], X).



% create a list fro another list
conv(V1, V2) :- V2 is V1 + 10.

b([], []).
b([H | T], [H2 | T2]) :- conv(H, H2), b(T, T2).

% b([1,2,3,4], L).



%create a partial list from a list
testit(V) :- V is V // 2 * 2.

c([],[]).
c([H | T], [H | L]) :- testit(H), c(T, L).
c([H | T], L) :- c(T, L).

% :q
