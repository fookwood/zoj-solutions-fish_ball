program p1180;

{$APPTYPE CONSOLE}
var
        temp    :array[1..1020000]of boolean;
        i       :longint;
        copy    :longint;
        sum     :longint;


begin
fillchar(temp,sizeof(temp),false);
i:=1;
while i<=1000000 do
        begin
        if not temp[i] then writeln(i);
        sum:=0;
        copy:=i;
        while copy>0 do
                begin
                sum:=sum+(copy mod 10);
                copy:=copy div 10;
                end;
        temp[i+sum]:=true;
        inc(i);
        end;
readln;
end.
