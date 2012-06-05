PROGRAM p2130;

TYPE
        Graph=array[1..60,1..60]of Char;

VAR
        map,goal                        :Graph;
        ans                             :Integer;
        n,m,a,b                         :Integer;

PROCEDURE Readin;
var
        i,j                             :Integer;
begin
readln(n,m,a,b);
for i:=1 to n do
        begin
        for j:=1 to m do read(map[i,j]);
        readln;
        end;
for i:=1 to a do
        begin
        for J:=1 to b do read(goal[i,j]);
        readln;
        end;
end;

PROCEDURE Main;
var
        p,q                             :Integer;
        Function check:boolean;
        var
                i,j                     :Integer;
                begin
                check:=true;
                for i:=1 to a do
                        for j:=1 to b do
                                if ((goal[i,j]='O')and(map[p+i-1,q+J-1]='X'))
                                        or((goal[i,j]='X')and(map[p+i-1,q+J-1]='O'))then
                                        begin
                                        check:=false;
                                        exit;
                                        end;
                end;
begin
ans:=0;
for p:=1 to n-a+1 do
        for q:=1 to m-b+1 do
                if check then inc(ans);
writeln(ans);
end;

BEGIN
while not eof do
        begin
        readin;
        main;
        end;
END.