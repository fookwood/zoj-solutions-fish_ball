program p1103;

{$APPTYPE CONSOLE}

type
        node=record
                p1,p2,p3        :integer;
                move            :longint;
        end;

var
        n               :integer;
        i,j             :Integer;
        s,t             :integer;
        col             :array[1..50,1..50]of char;
        data            :array[1..50,1..50,1..50]of boolean;
        line            :array[1..625000]of node;

PROCEDURE main;
var
        i               :integer;
        can             :set of 'a'..'z';
begin
fillchar(data,sizeof(data),false);
s:=1;
t:=1;
line[1].move:=0;
data[line[1].p1,line[1].p2,line[1].p3]:=true;
if (line[1].p1=line[1].p2)and(line[1].p1=line[1].p3) then
        begin
        writeln(0);
        exit;
        end;

repeat
        for i:=1 to n do
                if (not data[i,line[s].p2,line[s].p3] )and(col[line[s].p1,i]=col[line[s].p2,line[s].p3]) then
                        begin
                        inc(t);
                        line[t].p1:=i;
                        line[t].p2:=line[s].p2;
                        line[t].p3:=line[s].p3;
                        line[t].move:=line[s].move+1;
                        data[i,line[s].p2,line[s].p3]:=true;
                        if (line[t].p1=line[t].p2)and(line[t].p2=line[t].p3) then
                                begin
                                writeln(line[t].move);
                                exit;
                                end;
                        end;
        for i:=1 to n do
                if (not data[line[s].p1,i,line[s].p3])and(col[line[s].p2,i]=col[line[s].p1,line[s].p3]) then
                        begin
                        inc(t);
                        line[t].p1:=line[s].p1;
                        line[t].p2:=i;
                        line[t].p3:=line[s].p3;
                        data[line[s].p1,i,line[s].p3]:=true;
                        line[t].move:=line[s].move+1;
                        if (line[t].p1=line[t].p2)and(line[t].p2=line[t].p3) then
                                begin
                                writeln(line[t].move);
                                exit;
                                end;
                        end;

        for i:=1 to n do
                if (not data[line[s].p1,line[s].p2,i])and(col[line[s].p3,i]=col[line[s].p1,line[s].p2]) then
                        begin
                        inc(t);
                        line[t].p1:=line[s].p1;
                        line[t].p2:=line[s].p2;
                        line[t].p3:=i;
                        data[line[s].p1,line[s].p2,i]:=true;
                        line[t].move:=line[s].move+1;
                        if (line[t].p1=line[t].p2)and(line[t].p2=line[t].p3) then
                                begin
                                writeln(line[t].move);
                                exit;
                                end;
                        end;
        inc(s);
until s>t;
writeln('impossible');
end;

begin
//assign(input,'p.in');
//reset(input);
read(n);
while n<>0 do
        begin
        readln(line[1].p1,line[1].p2,line[1].p3);
        for i:=1 to n do
                begin
                read(col[i,1]);
                for j:=2 to n do read(col[i,j],col[i,j]);
                readln;
                end;
        main;
        read(n);
        end;
end.