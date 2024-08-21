
parent(a,b).
parent(b,c).
parent(c,d).
parent(d,e).
parent(e,f).

ancestor(A, P) :- parent(A, P).
ancestor(A, P) :- parent(X, P), 
                  ancestor(A, X).

ancestor_count(A, P, C) :- parent(A, P), C is 1.
ancestor_count(A, P, C) :- parent(X, P), 
                           ancestor_count(A, X, CX), 
                           C is CX + 1.

