PROGRAM p1729;


VAR
        n,i,l,j                         :Integer;
        c                               :Char;
        s                               :array[0..100000]of Char;

PROCEDURE Main;
var
        p1,p2,k                         :Integer;
begin
if length(s)=1 then
        begin
        writeln(1);
        exit;
        end;
p1:=0;
p2:=1;
repeat
        k:=0;
        while (k<=l)and(s[(p1+k) mod l]=s[(p2+k) mod l]) do inc(k);
        if k>l then break;
        if s[(p1+k) mod l]>s[(p2+k) mod l] then p1:=p1+k+1
                                        else p2:=p2+k+1;
        if p1=p2 then inc(p1);
        if p1>=l then
                begin
                if p2=0 then inc(p2);writeln(p2);
                exit;
                end;
        if p2>=l then
                begin
                if p1=0 then inc(p1);writeln(p1);
                exit;
                end;
until false;
if (p1=0)or(p2=0) then writeln(1) else
if p1>p2 then writeln(p2) else writeln(p1);
end;

BEGIN
readln(n);
for i:=1 to n do
        begin
        read(l);
        read(c);
        for j:=0 to l-1 do read(s[j]);
        readln;
        Main;
        end;
END.