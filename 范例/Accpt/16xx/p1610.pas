PROGRAM p1610;

VAR
	col				:array[-1..8004]of Integer;
	n,i,j                           :Integer;
        a,b,c                           :array[1..8004]of Integer;
	ans				:array[0..8004]of Integer;
BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
begin
readln(n);
fillchar(col,sizeof(col),0);
fillchar(ans,sizeof(ans),0);
for i:=1 to n do readln(a[i],b[i],c[i]);

for i:=0 to 8000 do
        begin
        for j:=n downto 1 do
                if (i>=a[j])and(i<b[j]) then break;
        if (i>=a[j])and(i<b[j]) then col[i]:=c[j]
                else col[i]:=-1;
        end;

col[-1]:=-2;
for i:=0 to 8000 do if (col[i]<>col[i-1])and(col[i]>=0) then inc(ans[col[i]]);

for i:=0 to 8000 do
if ans[i]>0 then writeln(i,' ',ans[i]);
writeln;
end;
END.
