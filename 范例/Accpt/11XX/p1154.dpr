program p1154;

{$APPTYPE CONSOLE}
var
        temp    :array[1..10000]of longint;
        n       :integer;
        p       :integer;
        sum     :longint;
        ch      :char;
        have    :longint;
        part    :Integer;

FUNCTION check:boolean;
var
        i       :integer;
        d       :longint;
begin
d:=0;
for i:=1 to have do
        d:=(d*n+temp[i]) mod sum;
if d=0 then check:=true else check:=false;
end;

begin
readln(part);
readln;
for p:=1 to part do
        begin
        read(n);
        while n<>0 do
                begin
                read(ch);
                while ch=' ' do read(ch);
                sum:=ord(ch)-48;
                have:=1;
                temp[have]:=sum;
                while not eoln do
                        begin
                        read(ch);
                        inc(have);
                        temp[have]:=ord(ch)-48;
                        inc(sum,temp[have]);
                        end;
                if check then writeln('yes') else writeln('no');
                readln;
                read(n);
                end;
        if p<>part then writeln;
        readln;
        end;
end.
 