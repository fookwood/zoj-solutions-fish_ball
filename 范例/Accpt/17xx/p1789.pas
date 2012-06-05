PROGRAM p1789;

VAR
	n,m			:Integer;
	pos			:array[0..30000]of Integer;
	whether		        :array[1..500,1..500]of Boolean;
	reach			:array[1..500]of Boolean;

PROCEDURE Readin;
var
i,j,t,a			:Integer;
begin
readln(n,m);
if (n=0)and(m=0) then halt;
fillchar(whether,sizeof(whether),0);
fillchar(reach,sizeof(reach),0);
fillchar(pos,sizeof(pos),0);
for i:=1 to m do
        begin
        read(t);
        for j:=1 to t do
                begin
                read(a);
                if pos[a]=0 then pos[a]:=i else
                        begin
                        whether[i,pos[a]]:=true;
                        whether[pos[a],i]:=true;
                        end;
                end;
        end;
end;

PROCEDURE Main;
var
        s,t,i,ans,j                       :Integer;
        line                            :array[1..500]of Integer;
begin
if pos[0]=0 then
        begin
        writeln(1);
        exit;
        end;
s:=1;
t:=1;
line[1]:=pos[0];
reach[pos[0]]:=true;
{for i:=1 to m do
        begin
        for j:=1 to m do write(whether[i,j],' ');
        writeln;
        end;  }
repeat
        for i:=1 to m do
                if not reach[i] and whether[line[s],i] then
                        begin
                        inc(t);
                        reach[i]:=true;
                        line[t]:=i;
                        end;
        inc(s);
until s>t;
ans:=0;
for i:=0 to n do
        if (pos[i]<>0)and(reach[pos[i]]) then inc(ans);
writeln(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
begin
Readin;
Main;
end;

END.
