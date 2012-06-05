PROGRAM p1704;

TYPE
        PosType=record
        x,y                     :Integer;
        end;

VAR
        n                       :Integer;
        ans                     :String;
        data                    :array[1..15]of PosType;
        area                    :array[1..15,1..15,1..15]of Extended;

PROCEDURE Readin;
var
        i                       :Integer;
        ch                      :Char;
begin
for i:=1 to n do
        begin
        read(ch);
        readln(data[i].x,data[i].y);
        end;
end;

PROCEDURE makearea;
var
        i,j,k                   :Integer;
begin
for i:=1 to n-2 do
        for j:=i+1 to n-1 do
                for k:=j+1 to n do
                        begin
                        area[i][j][k]:=abs((data[k].y-data[i].y) * (data[j].x-data[i].x)
                                - (data[j].y-data[i].y) * (data[k].x-data[i].x));
                        area[i][k][j]:=area[i][j][k];
                        area[j][i][k]:=area[i][j][k];
                        area[j][k][i]:=area[i][j][k];
                        area[k][i][j]:=area[i][j][k];
                        area[k][j][i]:=area[i][j][k];
                        end;
end;

FUNCTION Separate(a,b,c:Integer):Boolean;
var
        i                               :Integer;

        Function PointIn(p:Integer):Boolean;
        var
                i                       :Integer;
        begin
        if area[a][b][p] + area[b][c][p] + area[a][c][p] > area[a][b][c] + 1e-10 then PointIn:=false
                else PointIn:=true;
        end;

begin
Separate:=false;
for i:=1 to n do
        if (i<>a) and (i<>b) and (i<>c) and PointIn(i) then exit;
Separate:=true;
end;

PROCEDURE Main;
var
        i,j,k                           :Integer;
        max                             :Extended;
begin
max:=0;
for i:=1 to n-2 do
        for j:=i+1 to n-1 do
                for k:=j+1 to n do
                        if (area[i][j][k]>max) and Separate(i,j,k) then
                                begin
                                max:=area[i][j][k];
                                ans:=chr(i+ ord('A') -1 )
                                        +chr(j + ord('A') -1 )
                                        +chr(k + ord('A') -1 );
                                end;
writeln(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
while n<>0 do
        begin
        readin;
        MakeArea;
        Main;
        readln(n);
        end;
END.