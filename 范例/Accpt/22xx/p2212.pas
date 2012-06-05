PROGRAM p2212;

TYPE
        node=record
                year,per        :Integer;
                now             :Longint;
                end;

VAR
        total,code,n            :Integer;
        s                       :String;
        data                    :array[1..3000]of Node;

PROCEDURE Main;
var
        i,j,long                :Integer;

        Procedure Change(a,b:Integer);
        var
                temp            :Node;
        begin
        temp:=data[a];
        data[a]:=data[b];
        data[b]:=temp;
        end;

        Function Check(a,b:Integer):Boolean;
        begin
        if (data[a].now>data[b].now) then check:=true else
        if (data[a].now=data[b].now)and(data[a].year>data[b].year) then check:=true else
        check:=false;
        end;

        PROCEDURE Make(p:Integer);
        var
                j,min                   :Integer;
        begin
        if 2*p>long then exit;
        if 2*p+1>long then j:=2*p else
                begin
                if check(2*p,2*p+1) then j:=2*p+1 else j:=2*p;
                end;
        if check(p,j) then
                begin
                change(p,j);
                Make(j);
                end;
        end;

begin
long:=total;
for i:=total div 2 downto 2 do make(i);

for i:=1 to n do
        begin
        make(1);
        writeln(data[1].year);
        data[1].now:=data[1].now+data[1].per;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        total:=0;
        readln(s);
        while (s<>'#') do
                begin
                inc(total);
                with data[total] do
                        begin
                        delete(s,1,pos(' ',s));
                        val(copy(s,1,pos(' ',s)-1),year,code);
                        delete(s,1,pos(' ',s));
                        val(s,per,code);
                        now:=per;
                        end;
                readln(s);
                end;
        readln(n);
        Main;
        end;
END.