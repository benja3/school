
goal :- nl, write('symbol ASCII value'), nl, 
        showtable(32,126).

showtable(A,B) :- name(Symbol,[A]),
                  write(Symbol),
                  write('        '),write(A),
                  nl, C is A + 1, C =< B, 
                  showtable(C,B).

