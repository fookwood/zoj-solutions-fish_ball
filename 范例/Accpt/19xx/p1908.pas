PROGRAM p1908;

VAR
        map                     :array[1..3,1..3]of Char;
        part,p                  :Integer;
        c,o                     :Integer;

FUNCTION check:Boolean;
var
        ch                      :Char;
        lc,lo                   :Integer;
        total                   :Integer;
        i,j                     :Integer;
begin
total:=0;
lc:=0;
lo:=0;
for j:=1 to 3 do
        begin
        inc(total);
        ch:=map[1,j];
        for i:=2 to 3 do
                if (map[i,j]='.')or(map[i,j]<>map[i-1,j]) then
                        begin
                        ch:=' ';
                        dec(total);
                        break;
                        end;
        if ch='X' then inc(lc);
        if ch='O' then inc(lo);
        inc(total);
        ch:=map[j,1];
        for i:=2 to 3 do
                if (map[j,i]='.')or(map[j,i]<>map[j,i-1]) then
                        begin
                        ch:=' ';
                        dec(total);
                        break;
                        end;
        if ch='X' then inc(lc);
        if ch='O' then inc(lo);
        end;
inc(total);
ch:=map[1,1];
for i:=2 to 3 do
        if (map[1,1]='.') or (map[i,i]<>map[i-1,i-1]) then
                begin
                ch:=' ';
                dec(total);
                break;
                end;

if ch='X' then inc(lc);
if ch='O' then inc(lo);


ch:=map[1,3];
inc(total);
for i:=2 to 3 do
        if (map[1,3]='.') or (map[i,4-i]<>map[i-1,5-i]) then
                begin
                ch:=' ';
                dec(total);
                break;
                end;

if ch='X' then inc(lc);
if ch='O' then inc(lo);

check:=true;
if (total=2) and (abs(lc-lo)<2) then check:=false;

if not ((c>=o)and(c<=o+1)) then check:=false;
if (c=o+1) and (lo=1) then check:=false;
if (c=o) and(lc=1) then check:=false;
end;

FUNCTION Readin:Integer;
var
        i,j                     :Integer;
begin
c:=0;
o:=0;
for i:=1 to 3 do
        begin
        for j:=1 to 3 do
                begin
                read(map[i,j]);
                if map[i,j]='X' then inc(c);
                if map[i,j]='O' then inc(o);
                end;
        readln;
        end;

readin:=0;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        if check then writeln('yes') else writeln('no');
        if p<part then readln;
        end;
END.