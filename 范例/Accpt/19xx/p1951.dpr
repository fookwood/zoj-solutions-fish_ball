program p1951;

{$APPTYPE CONSOLE}


var
        prime   :array[1..1020000]of boolean;
        n       :longint;

PROCEDURE makeprime;
var
        i,j     :Longint;
begin
fillchar(prime,sizeof(prime),true);
prime[1]:=false;
i:=2;
while (i<=1000000) do
        begin
        while not prime[i] do inc(i);
        for j:=2 to 1000000 div i do  prime[i*j]:=false;
        inc(i);
        end;
prime[2]:=false;
end;


PROCEDURE solve;
var
        i       :longInt;
begin
i:=2;
while (not prime[i])or(not prime[n-i]) do inc(i);
writeln(n,' = ',i,' + ',n-i);
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
makeprime;
readln(n);
while n<>0 do
        begin
        solve;
        readln(n);
        end;
end.
 