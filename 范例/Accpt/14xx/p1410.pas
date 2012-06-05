PROGRAM p2273;
{$APPTYPE CONSOLE}
VAR
        part    :longint;
        n       :longint;
        i       :longint;
        pos     :array[1..99999]of int64;

FUNCTION wei(n  :longint):int64;
begin
if n<=9 then wei:=n
else if n<=99 then wei:=9+(n-9)*2
else if n<=999 then wei:=189+(n-99)*3
else if n<=9999 then wei:=2889+(n-999)*4
else if n<=99999 then wei:=38889+(n-9999)*5
else if n<=999999 then wei:=488889+(n-99999)*6
else if n<=9999999 then wei:=5888889+(n-999999)*7
else if n<=99999999 then wei:=68888889+(n-9999999)*8
else if n<=999999999 then wei:=788888889+(n-9999999)*9
end;

procedure main;
var
        i       :longint;
        sum     :int64;
begin
sum:=0;
pos[1]:=1;
for i:=1 to 31268 do
        begin
        sum:=sum+wei(i);
        pos[i+1]:=sum+1;
        end;
end;


PROCEDURE  ans;
var
        p       :longint;
        last    :longint;
        i       :longint;
        num     :longint;
begin
num:=1;
while pos[num]<=n do inc(num);
p:=n-pos[num-1]+1;
        if p<=9 then
                write(p) else
                begin
                if p<=189 then
                        begin
                        last:=((p-10)div 2) +10;
                        case (p+1) mod 2 of
                                0       :write(last mod 10);
                                1       :write(last div 10);
                        end;{case}
                        end
                        else
                        if p<=2889 then
                                begin
                                last:=((p-190) div 3)+100;
                                case (p+1) mod 3 of
                                        1       :write(last mod 10);
                                        0       :write((last div 10) mod 10);
                                        2       :write(last div 100);
                                end;
                                end else
                                if p<=38889 then
                                begin
                                last:=((p-2890)div 4)+1000;
                                case p mod 4 of
                                        1       :write(last mod 10);
                                        0       :write((last div 10) mod 10);
                                        3       :write((last div 100) mod 10);
                                        2       :write(last div 1000);
                                end;
                                end else
                                     begin
                                     last:=((p-38890)div 5)+10000;
                                     case p mod 5 of
                                     0          :write(last div 10000);
                                     1          :write((last div 1000)mod 10);
                                     2          :write((last div 100)mod 10);
                                     3          :write((last div 10) mod 10);
                                     4          :write((last mod 10));
                                     end;
                                     end;
                end;
writeln;
end;

BEGIN
main;
readln(part);
for i:=1 to part do
        begin
        readln(n);
        ans;
        end;
END.