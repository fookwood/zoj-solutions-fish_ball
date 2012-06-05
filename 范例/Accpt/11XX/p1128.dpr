program p1128;

{$APPTYPE CONSOLE}

type
        rectangle=record
                a,b,c,d         :real;
                end;

var
        i               :integer;
        n               :integer;
        rec             :array[1..100]of rectangle;
        px,py           :array[1..200]of real;
        step            :Integer;

PROCEDURE sort;
var
        i,j             :integer;
        temp            :real;
        c               :integer;
begin
for i:=1 to 2*n-1 do
        begin
        c:=i;
        for j:=i+1 to 2*n do
                if px[c]>px[j] then c:=j;
        if c<>i then
                begin
                temp:=px[c];
                px[c]:=px[i];
                px[i]:=temp;
                end;
        end;
for i:=1 to 2*n-1 do
        begin
        c:=i;
        for j:=i+1 to 2*n do
                if py[c]>py[j] then c:=j;
        if c<>i then
                begin
                temp:=py[c];
                py[c]:=py[i];
                py[i]:=temp;
                end;
        end;
end;

PROCEDURE main;
var
        i,j,k           :integer;
        s1,s2,t1,t2     :integer;
        whether         :array[1..200,1..200]of boolean;
        area            :real;

begin
for i:=1 to n do
        begin
        px[2*i-1]:=rec[i].a;
        px[2*i]:=rec[i].c;
        py[2*i-1]:=rec[i].b;
        py[2*i]:=rec[i].d;
        end;
sort;
area:=0;
fillchar(whether,sizeof(whether),false);
for i:=1 to n do
        begin
        j:=1;
        while px[j]<>rec[i].a do inc(j);
        while px[j]=rec[i].a do inc(j);
        s1:=j-1;
        dec(j);
        while px[j]<>rec[i].c do inc(j);
        t1:=j;
        j:=1;
        while py[j]<>rec[i].b do inc(j);
        while py[j]=rec[i].b do inc(j);
        s2:=j-1;
        dec(j);
        while py[j]<>rec[i].d do inc(j);
        t2:=j;
        for j:=s1 to t1-1 do
                for k:=s2 to t2-1 do
                        if not whether[j,k] then
                        begin
                        whether[j,k]:=true;
                        area:=area+(px[j+1]-px[j])*(py[k+1]-py[k]);
                        end;
        end;
writeln('Test case #',step);
writeln('Total explored area: ',area:0:2);
writeln;
end;

begin
step:=0;
readln(n);
while n<>0 do
        begin
        inc(step);
        for I:=1 to n do
                readln(rec[i].a,rec[i].b,rec[i].c,rec[i].d);
        main;
        readln(n);
        end;
end.
