PROGRAM p1409;

VAR
        minsum,temp            :array[1..500]of Integer;
        n,x,y,part,p           :Integer;


PROCEDURE Work;
var
        i,t,j,k                :Integer;
        ans                    :Extended;
begin
readln(n);
fillchar(minsum,sizeof(minsum),0);
for i:=1 to n do
        begin
        read(t);
        fillchar(temp,sizeof(temp),0);
        for j:=1 to t do
                begin
                read(x,y);
                for k:=1 to x do
                        if temp[k]=0 then temp[k]:=y
                                else
                        if y<temp[k] then temp[k]:=y;
                end;
        for k:=1 to 500 do
                if temp[k]=0 then minsum[k]:=-maxint
                        else inc(minsum[k],temp[k]);
        readln;
        end;
ans:=0;
for i:=1 to 500 do
        if i/minsum[i]>ans then ans:=i/minsum[i];
writeln(ans:0:3);
end;

BEGIN
readln(part);
for p:=1 to part  do
        Work;
END.