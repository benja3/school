
apply_b([], _) :- true.
apply_b([H|T], P) :- call(P, H), apply_b(T, P).

apply_t([], _, []).
apply_t([H|T], P, [H2|T2]) :- call(P, H, H2), apply_t(T, P, T2).

apply_s([], _, 0).
apply_s([H|T], P, X) :- call(P, H, H2), apply_s(T, P, X2), X is H2 + X2.

complete(a).
complete(b).
complete(c).
complete(d).

list_complete(L) :- apply_b(L, complete).

stuff(a,0).
stuff(b,1).
stuff(c,2).

stufflist(L, L2) :- apply_t(L, stuff, L2).

stuffsum(L, X) :- apply_s(L, stuff, X).

