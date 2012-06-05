PROGRAM p1850;

VAR
        n,m     :longint;


FUNCTION flag(n,p,mi:longint):boolean;
var
        copymi  :longint;
        p2      :longint;
begin
copymi:=0;
p2:=p;
while n div p2>0 do
        begin
        copymi:=copymi+(n div p2);
        p2:=p*p2;
        if copymi>mi then
                begin
                flag:=true;
                exit;
                end;
        end;
if copymi<mi then
        flag:=false else flag:=true;
end;

FUNCTION check(n,m:longint):boolean;

var
        p       :longint;
        copym   :longint;
        mi      :longint;
begin
if m=0 then
        begin
        check:=false;
        exit;
        end;
if n=0 then
        begin
        if m=1 then check:=true else check:=false;
        exit;
        end;
if m mod 2=0 then
        begin
        mi:=0;
        while m mod 2=0 do
                begin
                inc(mi);
                m:=m div 2;
                end;
        if not flag(n,2,mi) then
                begin
                check:=false;
                exit;
                end;
        end;
if m<=n then
        begin
        check:=true;
        exit;
        end;
p:=3;
while (m>n)and(p<=trunc(sqrt(m))) do
        begin
        mi:=0;
        while m mod p=0 do
                begin
                inc(mi);
                m:=m div p;
                end;
        if not flag(n,p,mi) then
                begin
                check:=false;
                exit;
                end;
        p:=p+2;
        end;
if m>n then check:=false else check:=true;
end;


BEGIN
while not eof do
        begin
        readln(n,m);
        if check(n,m) then
                begin
                writeln(m,' divides ',n,'!');
                end else
                begin
                writeln(m,' does not divide ',n,'!');
                end;
        end;
END.