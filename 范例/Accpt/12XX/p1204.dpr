program p1204;

{$APPTYPE CONSOLE}

const
        max=1000000;

var
        i       :Integer;
        data    :array[0..31]of longint;
        sum     :array[0..max]of longint;
        pos     :array[0..max]of integer;
        l,t     :longint;
        puss    :array[1..max]of longint;
        part,p  :Integer;
        m       :integer;
        have    :boolean;

PROCEDURE sort;
var
        i,j     :Integer;
        temp    :longint;
begin
for I:=1 to m-1 do
        for j:=i+1 to m do
        if data[i]>data[j] then
                begin
                temp:=data[i];
                data[i]:=data[j];
                data[j]:=temp;
                end;
end;

PROCEDURE output(w:longint);
begin
if puss[w]=0 then write(data[pos[w]]) else
        begin
        output(puss[w]);
        write('+',data[pos[w]]);
        end;
end;

PROCEDURE print;
begin
output(t);
writeln('=',sum[t]);
have:=true;
end;

FUNCTION check(p:longint):boolean;
var
        i       :integer;
begin
for I:=m downto 1 do
        if data[i]=p then
                begin
                check:=true;
                exit;
                end;
check:=false;
end;

PROCEDURE main;
var
        i       :integer;
begin
repeat
for i:=pos[l]+1 to m do
        begin
        inc(t);
        pos[t]:=i;
        puss[t]:=l;
        sum[t]:=sum[l]+data[i];
        if check(sum[t]) then print;
        if sum[t]>data[m] then dec(t);
        end;
inc(l);
until l>t;
end;

begin
readln(part);
for p:=1 to part do
        begin

        read(m);
        for I:=1 to m do read(data[i]);
        readln;
        //readin

        sort;
        have:=false;
        for i:=1 to m do begin puss[i]:=0; pos[i]:=i; sum[i]:=data[i] end;
        l:=1;t:=m;
        //first


        main;



        if not have then writeln('Can','''','t find any equations.');
        writeln;
        end;


end.
