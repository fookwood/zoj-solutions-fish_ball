PROGRAM p1118;

TYPE
        Point=record
        p                               :array[1..10]of Integer;
        end;

VAR
        s,t                             :Point;
        i,left,right,step               :Integer;
        total,n                         :Integer;
        a                               :Longint;
        temp                            :Point;
        data                            :array[1..200]of Point;
        whether                         :array[1..200,1..200]of Boolean;

FUNCTION Add(p:Point):Integer;
var
        equal                           :Boolean;
        i,j                             :Integer;
begin
for I:=1 to total do
        begin
        equal:=true;
        for j:=1 to n do
                if data[i].p[j]<>p.p[j] then
                        begin
                        equal:=false;
                        break;
                        end;
        if equal then
                begin
                Add:=i;
                exit;
                end;
        end;
inc(total);
data[total]:=temp;
Add:=total;
end;

PROCEDURE Main;
var
        i,j                                     :Integer;
        p,q,first,tail                          :Integer;
        line                                    :array[1..200]of Integer;
        reach                                   :array[1..200]of Boolean;
begin
i:=total;
p:=Add(s);
q:=Add(t);
if (p>i)or(q>i) then
        begin
        writeln('Maze #',step,' cannot be travelled');
        exit;
        end;
first:=1;
tail:=1;
line[1]:=p;
reach[p]:=true;
fillchar(reach,sizeof(reach),0);
for i:=1 to total do
        if whether[p,i] then
                begin
                inc(tail);
                line[tail]:=i;
                reach[i]:=true;
                end;
repeat
        for i:=1 to total do
                if not reach[i] and whether[line[first],i] then
                        begin
                        inc(tail);
                        line[tail]:=i;
                        reach[i]:=true;
                        end;
        inc(first);
until first>tail;



if reach[q] then
        writeln('Maze #',step,' can be travelled') else
        writeln('Maze #',step,' cannot be travelled');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
step:=0;
while (n<>0) do
        begin
        inc(step);
        total:=0;
        fillchar(data,sizeof(data),0);
        fillchar(temp,sizeof(temp),0);
        for i:=1 to n do read(s.p[i]);
        for i:=1 to n do read(t.p[i]);
        readln;
        read(temp.p[1]);
        fillchar(whether,sizeof(whether),0);
        while (temp.p[1]<>-1) do
                begin
                for i:=2 to n do read(temp.p[i]);
                left:=Add(temp);
                for i:=1 to n do read(temp.p[i]);
                right:=Add(temp);
                whether[left,right]:=true;
                whether[right,left]:=true;
                readln;
                read(temp.p[1]);
                end;
        readln;
        Main;
        readln(n);
        end;
END.