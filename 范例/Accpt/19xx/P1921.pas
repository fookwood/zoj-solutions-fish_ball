PROGRAM P1921;

type TTT = array[0..101,0..101] of char;
CONST
        change:array[1..4,1..2]of integer=((0,-1),(0,1),(1,0),(-1,0));

VAR
        m,n       :integer;
        k,step    :integer;
        i,j       :integer;
        c         :integer;
        map       :TTT;


FUNCTION win(p,q,r,s:integer):boolean;
var     a,b     :char;
begin
a:=map[p,q];b:=map[r,s];
win:=false;
if (a='R')and(b='S') then win:=true else
if (a='S')and(b='P') then win:=true else
if (a='P')and(b='R') then win:=true;
end;

PROCEDURE make;
var     copy      :TTT;
        i,j,t     :Integer;
        c       :integer;
begin
copy:=map;
for c:=1 to step do
begin
for i:=1 to m do
        for j:=1 to n do
                for t:=1 to 4 do
                begin
                if win(i,j,i+change[t,1],j+change[t,2]) then
                        begin
                        copy[i+change[t,1],j+change[t,2]]:=map[i,j];
                        end;
                end;
map:=copy;
end;
for i:=1 to m do
begin
for j:=1 to n do
write(map[i,j]);
writeln;
end;
end;

BEGIN
readln(k);
for c:=1 to k do
        begin
        readln(m,n,step);
        for I:=1 to m do
                begin
                for j:=1 to n do
                read(map[i,j]);
                readln;
                end;
        make;
        if ( c < k ) then writeln;
        end;
END.