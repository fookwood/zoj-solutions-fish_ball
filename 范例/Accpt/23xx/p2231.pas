PROGRAM p2231;

CONST
        small=1e-6;


TYPE
        node=record
                name                    :String;
                a,b,c                   :Real;
        end;

VAR
        data                            :array[1..3]of Node;
        a,b,c                           :Real;
        flag                            :Boolean;
        i                               :Integer;

FUNCTION Check(p:Integer):Boolean;
begin
if (a<data[p].a+small)and(b>data[p].b-small)and(c>data[p].c-small) then check:=true else check:=false;
end;

PROCEDURE init;
begin
with data[1] do
        begin
        name:='Wide Receiver';
        a:=4.5;
        b:=150;
        c:=200;
        end;
with data[2] do
        begin
        name:='Lineman';
        a:=6.0;
        b:=300;
        c:=500;
        end;
with data[3] do
        begin
        name:='Quarterback';
        a:=5.0;
        b:=200;
        c:=300;
        end;
end;

BEGIN
Init;
readln(a,b,c);
while (a<>0)or(b<>0)or(c<>0) do
        begin
        flag:=false;
        for i:=1 to 3 do
                if check(i) then
                        begin
                        if flag then write(' ');
                        write(data[i].name);
                        flag:=true;
                        end;
        if flag then writeln;
        if not flag then
                writeln('No positions');
        readln(a,b,c);
        end;
END.