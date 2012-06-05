PROGRAM p1266;

VAR
        n,m,t,driver,posi               :Integer;
        whether                         :array[1..20,1..20]of Boolean;
        linenumber                      :Integer;
        line,total                      :array[1..50]of Integer;
        PToS                            :array[1..20,1..50]of Integer;

PROCEDURE Init;
var
        i,j,k                           :Integer;
begin
for i:=1 to m do
        for j:=1 to t do
                PToS[i,j]:=maxint;

fillchar(total,sizeof(total),0);
fillchar(whether,sizeof(whether),0);

for i:=1 to n do
        begin
        linenumber:=0;
        while not eoln do
                begin
                inc(linenumber);
                read(line[linenumber]);
                end;
        readln;
        while not eoln do
                begin
                read(posi,driver);
                total[driver]:=linenumber;
                for k:=1 to linenumber do if line[k]=posi then break;
                PToS[driver,line[k]]:=0;
                for j:=k+1 to linenumber do PToS[driver,line[j]]:=j-k;
                for j:=1 to k-1 do PToS[driver,line[j]]:=linenumber-k+j;
                end;
        readln;
        end;

end;

FUNCTION Gcd(a,b:Integer):Integer;
begin
if a<=b then
        begin
        if a=0 then Gcd:=b else Gcd:=Gcd(b mod a,a);
        end else
        Gcd:=Gcd(b,a);
end;

FUNCTION Check(a,b,c:Integer):Boolean;
var
        p                                       :Integer;
begin
if (PToS[a,c]=maxint) or (PToS[b,c]=maxint) then
        begin
        Check:=false;
        exit;
        end;

if PToS[a,c]=PToS[b,c] then
        begin
        Check:=true;
        exit;
        end;

p:=Gcd(Total[a],Total[b]);
if (PToS[a,c]-PToS[b,c]+p) mod p=0 then
        Check:=true else
        Check:=false;
end;

PROCEDURE SecondPart;
var
        i,j,k                                   :Integer;
        first,tail                              :Integer;
        line                                    :array[1..60]of Integer;
        reach                                   :array[1..50]of Boolean;
begin
for i:=1 to m do
        for j:=1 to m do
                if (i<>j) then
                for k:=1 to t do
                        if Check(i,j,k) then
                                begin
                                whether[i,j]:=true;
                                whether[j,i]:=true;
                                break;
                                end;
fillchar(reach,sizeof(reach),0);
first:=1;
tail:=1;
line[1]:=1;
reach[1]:=true;
repeat
        for i:=1 to m do
                if not reach[i] and whether[line[first],i] then
                        begin
                        inc(tail);
                        line[tail]:=i;
                        reach[i]:=true;
                        end;
        inc(first);
until first>tail;
for i:=1 to m do
        if not reach[i] then
                begin
                writeln('No');
                exit;
                end;
writeln('Yes');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n,m,t);
while (n<>0)or(m<>0)or(t<>0) do
        begin
        Init;
        SecondPart;
        readln(n,m,t);
        end;
END.
