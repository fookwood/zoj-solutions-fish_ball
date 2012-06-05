PROGRAM p2193;

VAR
        i,j                                     :Integer;
        s                                       :String;
        map                                     :array[1..4,1..4]of Char;

FUNCTION Check(n:Integer):Boolean;
var
        p,q,i,j                                 :Integer;
begin
p:=(n+2) div 3;
q:=n mod 3;
if q=0 then q:=3;
for i:=p to p+1 do
        for j:=q to q+1 do
                if (map[i,j]<>'.')and(map[i,j]<>char(n+48)) then
                begin
                check:=false;
                exit;
                end;
check:=true;
for i:=p to p+1 do
        for j:=q to q+1 do map[i,j]:='.';
end;

FUNCTION Ans:Boolean;
var
        find                                    :Boolean;
        i,j                                     :Integer;
        done                                    :array[1..9]of Boolean;
begin
fillchar(done,sizeof(done),false);
repeat
        find:=false;
        for i:=1 to 9 do
                if not done[i] and (check(i)) then
                        begin
                        done[i]:=true;
                        find:=true;
                        end;
until not find;
Ans:=true;
for i:=1 to 4 do
        for j:=1 to 4 do
                if map[i,j]<>'.' then
                        begin
                        ans:=false;
                        exit;
                        end;
end;


BEGIN
readln(s);
while (s<>'ENDOFINPUT') do
        begin
        for i:=1 to 4 do
                begin
                read(map[i,1]);
                for j:=2 to 4 do read(map[i,j],map[i,j]);
                readln;
                end;
        if Ans then writeln('THESE WINDOWS ARE CLEAN')
                else writeln('THESE WINDOWS ARE BROKEN');
        readln;
        readln(s);
        end;
END.