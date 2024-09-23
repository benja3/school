
% define some colors asigned to some items

colorlist([red, green], [c, d, e]).
colorlist([blue, orange], [h, i]).
colorlist([white], [j, k]).
colorlist([red, yellow, purple], [c, i, k]).
colorlist([purple, blue], [x]).

% check if color X is asigned to item Y

color(X,Y) :- colorlist(P,C), member(X,P), member(Y,C).
