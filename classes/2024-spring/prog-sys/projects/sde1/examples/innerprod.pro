
% takes two lists of numbers, equal length
% multiples corresponding elemments and adds up products
% returns inner Product

inner_prod([],[],0).

inner_prod([A|B],[C|D],S) :- innerprod(B,D,S1), S is S1 + (A * C).

