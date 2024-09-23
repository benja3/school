
%% adjacent

adj_to(r1, r2).
adj_to(r1, r3).
adj_to(r2, r5).
adj_to(r3, r4).

adjacent(A, B) :- adj_to(A, B).
adjacent(A, B) :- adj_to(B, A).

trans_adjacent(A, C) :- adjacent(A, C).
trans_adjacent(A, C) :- adjacent(A, B), trans_adjacent(B, C).




