program P1577;

{$APPTYPE CONSOLE}

var
        x,y     :longint;
        d       :longint;
        ans     :longint;
        max     :longint;
        i       :longint;
        num     :array[1..10000]of integer;

PROCEDURE output;
var
        i       :longint;
        l       :longint;
        j       :longint;
        temp    :integer;
begin
L:=1;
num[1]:=1;
for J:=1 to ans do
        begin
        temp:=0;
        for I:=1 to l do
                begin
                temp:=temp+2*num[i];
                num[i]:=temp mod 10;
                temp:=temp div 10;
                end;
        if temp<>0 then
                begin
                inc(l);
                num[l]:=temp;
                end;
        end;
for I:=l downto 1 do write(num[i]);
writeln;
end;


FUNCTION gcd(a,b:longint):longint;
begin
if a=0 then gcd:=b else gcd:=gcd(b mod a,a);
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }


while not eof do
        begin
        readln(x,y);
        if x>y then
                writeln(0) else
        if x=y then
                writeln(1) else
                begin
                d:=gcd(x,y);
                x:=x div d;
                y:=y div d;
                if x<>1 then writeln(0) else
                begin
                if x>y then max:=x else max:=y;
                ans:=0;
                for I:=2 to max do
                        begin
                        if x mod i=0 then
                                begin
                                inc(ans);
                                while x mod i=0 do x:=x div i;
                                end;
                        if y mod i=0 then
                                begin
                                inc(ans);
                                while y mod i=0 do y:=y div i;
                                end;
                        end;
                output;
                end;
                end;
        end;


end.
