PROGRAM p1787;

VAR
        maxx,maxy               :Longint;
        num,maxget              :array[0..100,0..100]of Longint;

PROCEDURE Readin;
var
        total,i,p,q             :Longint;
begin
fillchar(num,sizeof(num),0);
readln(total);
if total=0 then
        begin
        writeln('*');
        halt;
        end;
maxx:=0;
maxy:=0;
for i:=1 to total do
        begin
        readln(p,q);
        inc(num[p][q]);
        if p>maxx then maxx:=p;
        if q>maxy then maxy:=q;
        end;
end;

PROCEDURE Main;
var
        i,j                     :Longint;
begin
fillchar(maxget,sizeof(maxget),0);
for i:=1 to maxx do
        for j:=1 to maxy do
                if maxget[i-1][j]>maxget[i][j-1] then
                        maxget[i][j]:=maxget[i-1][j]+num[i][j]
                                else
                        maxget[i][j]:=maxget[i][j-1]+num[i][j];
writeln(maxget[maxx][maxy]);
end;


BEGIN
while true do
        begin
        Readin;
        Main;
        end;
END.