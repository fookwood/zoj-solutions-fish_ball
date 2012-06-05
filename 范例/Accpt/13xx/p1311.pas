PROGRAM p1311;

VAR
        n                       :Integer;
        data                    :array[1..100,0..100]of Integer;
        whether                 :array[1..100,1..100]of Boolean;

PROCEDURE readin;
var
        a,b                     :Integer;
begin
readln(n);
if n=0 then halt ;

fillchar(whether,sizeof(whether),0);
for a:=1 to n do data[a][0]:=0;
read(a);
while a<>0 do
        begin
        while not eoln do
                begin
                read(b);
                if whether[a][b] then continue;
                inc(data[a][0]);
                data[a][data[a][0]]:=b;
                inc(data[b][0]);
                data[b][data[b][0]]:=a;
                end;
        readln;
        read(a);
        end;
readln;
end;

PROCEDURE Main;
var
        i,j,s,t,k,ans,total     :Integer;
        line                    :array[1..100]of Integer;
        reach                   :array[1..100]of Boolean;
begin
ans:=0;
for i:=1 to n do
        begin
        s:=1;
        t:=1;
        if i=1 then line[1]:=n else line[1]:=1;
        fillchar(reach,sizeof(reach),0);
        reach[line[1]]:=true;
        total:=0;
        repeat
                if line[s]<>i then
                        begin
                        //write(line[s],' ');
                        inc(total);
                        for j:=1 to data[line[s]][0] do
                                if not reach[data[line[s]][j]] then
                                        begin
                                        inc(t);
                                        line[t]:=data[line[s]][j];
                                        reach[line[t]]:=true;
                                        end;
                        end;
                inc(s);
        until s>t;
        //writeln('i',i);
        //for j:=1 to n do write(reach[i],' ');
        //writeln;
        if total<>n-1 then inc(ans);
        end;
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