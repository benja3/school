% item_index(item-to-search-for, 
%            list to search in,
%            position-of-item)
%
item_index(I,[I|_],0).
item_index(I,[_|T],X) :- item_index(I, T, X2), 
                         X is X2 + 1.

