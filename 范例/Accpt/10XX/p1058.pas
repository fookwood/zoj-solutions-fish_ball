PROGRAM P1058;

CONST
        inf='p1058.in';

VAR
        f       :text;
        k       :Integer;
        team    :integer;
        change  :array[1..5,1..5]of real;
        puss    :array[1..10]of integer;
        i,j     :integer;
        n       :integer;
        money   :real;

FUNCTION ans:real;
var     ii      :integer;
        get     :real;
begin
get:=round(money*change[1,puss[1]]*100)/100;
for ii:=2 to n do
get:=round(get*change[puss[ii-1],puss[ii]]*100)/100;
get:=round(get*change[puss[n],1]*100)/100;
ans:=get;
end;


BEGIN
readln(k);
for team:=1 to k do
        begin
        for i:=1 to 5 do
                begin
                for J:=1 to 5 do
                read(change[i,j]);
                readln;
                end;
        read(n);
        while n<>0 do
                begin
                for I:=1 to n do
                        read(puss[i]);
                readln(money);
                writeln(ans:0:2);
                read(n);
                end;
        readln;
        if team<>k then writeln;
        end;
END.