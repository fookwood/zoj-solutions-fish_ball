PROGRAM p1078;

VAR
        n       :longint;
        k       :longint;
        have    :boolean;
        ans     :array[1..16]of integer;
        t       :longint;


FUNCTION check(num,d:longint):boolean;
var     s       :packed array[1..10000]of char;
        i       :longint;
        l       :longint;
begin
l:=0;
while num>0 do
        begin
        inc(l);
        s[l]:=chr((num mod d)+48);
        num:=num div d;
        end;
check:=true;
for i:=1 to l div 2 do
        if s[i]<>s[l-i+1] then
        begin
        check:=false;
        exit;
        end;
end;

BEGIN
readln(n);
while n<>0 do
        begin
        have:=false;
        t:=0;
        for k:=2 to 16 do
                if check(n,k) then
                begin
                inc(t);
                ans[t]:=k;
                have:=true;
                end;
        if have then write('Number ',n,' is palindrom in basis')
        else write('Number ',n,' is not a palindrom');
        for k:=1 to t do write(' ',ans[k]);
        writeln;
        readln(n);
        end;
END.
