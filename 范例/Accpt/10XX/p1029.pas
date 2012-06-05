PROGRAM p1029;

VAR
        n,part,p,i,temp                 :Integer;
        line                            :array[0..200,0..1]of Integer;

PROCEDURE Main;
var
        i,j,a                           :Integer;
        ans                             :Integer;
begin
ans:=0;
i:=1;
while (i<n) do
        begin
        while (i<n)and(line[i,0]=-1) do inc(i);
        if (line[i,0]<>-1) then
                begin
                j:=i;
                a:=-1;
                while j<=n do
                        if line[j,0]>a then
                                begin
                                line[j,0]:=-1;
                                a:=line[j,1];
                                end else inc(j);
                inc(ans);
                end;
        end;
writeln(ans*10);
end;

PROCEDURE Sort;
var
        i,j,temp                        :Integer;
begin
for i:=1 to n-1 do
        for j:=i+1 to n do
                if (line[i,0]>line[j,0]) or ((line[i,0]=line[j,0])and(line[i,1]>line[j,1])) then
                        begin
                        temp:=line[i,0];
                        line[i,0]:=line[j,0];
                        line[j,0]:=temp;
                        temp:=line[i,1];
                        line[i,1]:=line[j,1];
                        line[j,1]:=temp;
                        end;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        readln(n);
        for i:=1 to n do
                begin
                readln(line[i,0],line[i,1]);
                line[i,0]:=(line[i,0]-1) div 2;
                line[i,1]:=(line[i,1]-1) div 2;
                if line[i,0]>line[i,1] then
                        begin
                        temp:=line[i,0];
                        line[i,0]:=line[i,1];
                        line[i,1]:=temp;
                        end;
                end;
        Sort;
        Main;
        end;

END.
