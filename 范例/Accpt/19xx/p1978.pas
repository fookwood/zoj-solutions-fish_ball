PROGRAM p1978;

VAR

        num                     :array[0..3000]of Longint;

PROCEDURE MakeNum;
var
        flag                    :Boolean;
        i,j,t,k                 :Longint;
begin
num[1]:=2;
i:=2;
j:=3;
while (i<=3000) do
        begin
        t:=j-2;
        flag:=true;
        for k:=1 to i-1 do
                if t mod num[k]=0 then
                        begin
                        flag:=false;
                        break;
                        end else
                        t:=t-t div num[k]-1;
        if flag then
                begin
                num[i]:=j;
                inc(i);
                end;
        inc(j);
        end;

end;

PROCEDURE main;
var
        n                       :Integer;
begin
readln(n);
while (n<>0) do
        begin
        writeln(num[n]);
        readln(n);
        end;
end;

BEGIN
MakeNum;
Main;
END.
