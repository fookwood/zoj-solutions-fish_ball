PROGRAM p1806;

TYPE
        Position=record
                x,y                     :Real;
        end;

VAR
        n,long,step                     :Integer;
        point                           :array[1..9]of Integer;
        data                            :array[1..8]of Position;

PROCEDURE Readin;
var
        i                               :Integer;
begin
for I:=1 to 4 do read(data[2*i-1].x,data[2*i-1].y);
for i:=1 to 3 do
        begin
        data[2*i].x:=(data[2*i-1].x+data[2*i+1].x)/2;
        data[2*i].y:=(data[2*i-1].y+data[2*i+1].y)/2;
        end;
data[8].x:=(data[7].x+data[1].x)/2;
data[8].y:=(data[7].y+data[1].y)/2;
readln;
end;

FUNCTION check_0:Boolean;
var
        i                               :Integer;
begin
for i:=1 to 4 do if (data[2*i-1].x<>0)or(data[2*i-1].y<>0) then
        begin
        check_0:=false;
        exit;
        end;
check_0:=true;
end;

FUNCTION quel(p:Integer):Real;
var
        temp                            :Real;
        i                               :Integer;
begin
temp:=0;
for i:=1 to p-1 do
        temp:=temp+(data[point[i]].x*data[point[i+1]].y-data[point[i]].y*data[point[i+1]].x)/2;
quel:=abs(temp);
end;

PROCEDURE Main;
var
        i,j,k                           :Integer;
        area,total,temp                 :Real;
begin
for i:=1 to 8 do point[i]:=i;
point[9]:=1;
total:=quel(9) / 2;
area:=1e10;
for i:=1 to 8 do
        for j:=i+2 to 8 do
                begin
                for k:=1 to i do point[k]:=k;
                for k:=j to 8 do point[1+k-j+i]:=k;
                point[10-j+i]:=1;
                temp:=quel(10-j+i);
                if abs(temp-total)<area then area:=abs(temp-total);
                end;
writeln('Cake ',step,': ',total-area:0:3,' ',total+area:0:3);
end;

BEGIN
Readin;
step:=0;
while not Check_0 do
        begin
        inc(step);
        Main;
        Readin;
        end;
END.