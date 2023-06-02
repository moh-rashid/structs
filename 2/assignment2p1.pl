parent(bob,pamela).
parent(bob,tom).
parent(liz,tom).
parent(patricia,bob).
parent(ann,bob).
parent(jim,patricia).

female(pamela).
female(liz).
female(ann).
female(patricia).
male(tom).
male(bob).
male(jim).
offspring(Parent,Child) :- parent(Child,Parent).
mother(Child,Mother) :- parent(Child,Mother),female(Mother).
grandparent(Child,Grandparent) :- parent(Child,Parent), parent(Parent,Grandparent).
sister(Child,Sister) :- parent(Child,Parent), parent(Sister,Parent), female(Sister).
ancestor(Child,Ancestor) :- parent(Child,Ancestor).
ancestor(Child,Ancestor) :- parent(Child,Parent), ancestor(Parent,Ancestor).

