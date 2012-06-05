program p1337;

{$APPTYPE CONSOLE}

var
        n       :longInt;
        num     :array[1..50]of longint;
        d       :longint;
        same,total      :longint;
        i       :longint;
        j       :longint;
        temp    :longint;


FUNCTION gcd(a,b:longint):longint;
begin
if a=0 then gcd:=b else gcd:=gcd(b mod a,a);
end;

begin
readln(n);
while n<>0 do
        begin
        same:=0;total:=0;
        for I:=1 to n do readln(num[i]);
        for I:=1 to n-1 do for J:=i+1 to n do
                if num[i]>num[j] then
                        begin
                        temp:=num[i];
                        num[i]:=num[j];
                        num[j]:=temp;
                        end;
        for i:=1 to n-1 do
                for J:=i+1 to n do
                        if gcd(num[i],num[j])=1 then
                                begin
                                inc(same);
                                inc(total);
                                end  else
                                inc(total);
        if same>0 then writeln(sqrt(6*total/same):0:6) else
                writeln('No estimate for this data set.');
        readln(n);
        end;
end.
