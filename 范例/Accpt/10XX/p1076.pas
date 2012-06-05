PROGRAM p1076;

TYPE
    node=record
               a,b      :longint;
               ci       :Integer;
               end;

VAR
   n    :integer;
   data :array[0..1000]of node;
   long :array[0..1000]of integer;
   puss :array[0..1000]of integer;
   i    :Integer;
   temp :integer;

PROCEDURE output(b:integer);
begin
if puss[b]=0 then
   begin
   write(data[b].ci)
   end else
   begin
   output(puss[b]);
   write(' ',data[b].ci);
   end;
end;

PROCEDURE print;
var
   i    :integer;
   max:longint;
   point:integer;
begin
max:=0;
for i:=1 to n do if long[i]>max then
    begin
    max:=long[i];
    point:=i;
    end;
output(point);
writeln;
end;



PROCEDURE best;
var
   i,j  :Integer;
   max  :integer;
   point:integer;

begin
fillchar(long,sizeof(long),0);
data[0].b:=-1;
data[0].a:=-1;
long[0]:=0;
for i:=1 to n do
    begin
    max:=-1;
    for j:=0 to i-1 do
        begin
        if (long[j]>max)and(data[i].a>data[j].b) then
           begin
           max:=long[j];
           point:=j;
           end;
        end;
    long[i]:=max+1;
    puss[i]:=point;
    end;
end;


PROCEDURE sort;
var
   i,j  :integer;
   flag :boolean;
   temp :node;
begin
for I:=1 to n-1 do
    for j:=i+1 to n do
        begin
        flag:=false;
        if data[i].a>data[j].a then flag:=true else
           if (data[i].a=data[j].a)and(data[i].b>data[j].b) then flag:=true;
        if flag then
           begin
           temp:=data[i];
           data[i]:=data[j];
           data[j]:=temp;
           end;
        end;
end;

BEGIN
readln(n);
while n<>0 do
      begin
      fillchar(long,sizeof(long),0);
      fillchar(puss,sizeof(puss),0);
      for i:=1 to n do
        begin
        readln(data[i].a,data[i].b);
        if data[i].a>data[i].b then
                begin
                temp:=data[i].a;
                data[i].a:=data[i].b;
                data[i].b:=temp;
                end;
        data[i].ci:=i;
        end;
      sort;
      best;
      print;
      readln(n);
      end;
END.
