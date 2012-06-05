PROGRAM p1497;

CONST
        L_      =       0;
        R_      =       1;

VAR
        n,step,a,b,touch        :Longint;
        think                   :array[0..29]of 0..1;
        catch                   :array[0..29]of Boolean;

PROCEDURE Readin;
var
        i                       :Integer;
        ch                      :Char;
begin
a:=0;
step:=0;
read(b);
b:=b-1;

for i:=0 to n-1 do
        begin
        read(ch);
        while (ch<>'L') and (ch<>'R') do read(ch);
        if ch='L' then think[i]:=L_ else think[i]:=R_;
        end;
readln;

touch:=1;
fillchar(catch,sizeof(catch),0);
catch[b]:=true;
end;

PROCEDURE Main;
var
        i,temp                            :Longint;
begin

while touch<n do
        begin
        inc(step);

        if think[b]=L_ then
                begin
                think[b]:=R_;

                if a = (b+1) mod n then
                        begin
                        a:=b;
                        b:=(b-1+n) mod n;

                        end else
                        begin
                        temp:=b;
                        b:=(a-1+n) mod n;
                        a:=temp;
                        end;
                end else
                begin
                think[b]:=L_;

                if (a+1) mod n=b then
                        begin
                        a:=b;
                        b:=(b+1) mod n;
                        end else
                        begin
                        temp:=b;
                        b:=(a+1) mod n;
                        a:=temp;
                        end;
                end;

        if not catch[b] then
                begin
                catch[b]:=true;
                inc(touch);
                end;
        end;

writeln('Classmate ',b+1,' got the ball last after ',step+1,' tosses.');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
read(n);
while (n<>0) do
        begin
        Readin;
        Main;
        read(n);
        end;
END.