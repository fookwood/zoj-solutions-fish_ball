program p1312;

{$APPTYPE CONSOLE}

var
        sn      :Integer;
        t       :integer;
        n       :integer;
        c       :longint;
        prime   :array[1..10000]of integer;
        have    :integer;


PROCEDURE cut;
var
        left,right      :integer;
        i       :integer;
begin
if n mod 2=0 then
        begin
        left:=(n div 2)-c+1;
        right:=(n div 2)+c;
        if left<=0 then left:=1;
        if right>n then right:=n;
        end else
        begin
        left:=(n div 2)-c+2;
        right:=(n div 2)+c;
        if left<=0 then left:=1;
        if right>n then right:=n;
        end;
write(sn,' ',c,':');
for i:=left to right do write(' ',prime[i]);
writeln;
end;


PROCEDURE makeprime;
var
        i,j     :integer;
        pri     :boolean;
begin
have:=1;
prime[1]:=1;
for i:=2 to 10000 do
        begin
        pri:=true;
        for J:=2 to trunc(sqrt(i)) do
                if i mod j=0 then
                        begin
                        pri:=false;
                        break;
                        end;
        if pri then
                begin
                inc(have);
                prime[have]:=i;
                end;
        end;
end;

begin
makeprime;
while not eof do
        begin
        readln(sn,c);
        n:=0;
        t:=1;
        while prime[t]<=sn do begin inc(t);inc(n);end;
        cut;
        writeln;
        end;
end.
 