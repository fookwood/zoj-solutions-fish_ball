PROGRAM p1160;

type
        node=record
                a,b,c   :integer;
                end;


VAR
        part,p    :integer;
        stay    :array[0..21252]of node;
        temp    :node;
        pos     :Integer;
        step    :integer;
        mini    :integer;

PROCEDURE makestay;
var
        i       :integer;
begin
stay[0].a:=0;stay[0].b:=0;stay[0].c:=0;
for I:=1 to 21252 do
        begin
        stay[i].a:=(stay[i-1].a+1) mod 23;
        stay[i].b:=(stay[i-1].b+1) mod 28;
        stay[i].c:=(stay[i-1].c+1) mod 33;
        end;
end;

BEGIN
makestay;
readln(part);
 step:=0;
for p:=1 to part do
        begin
        readln;
        step:=0;
        readln(temp.a,temp.b,temp.c,mini);
        while (temp.a<>-1)or(temp.b<>-1) do
                begin
                inc(step);
                temp.a:=(23-temp.a mod 23)mod 23;
                temp.b:=(28-temp.b mod 28)mod 28;
                temp.c:=(33-temp.c mod 33)mod 33;
                for pos:=0 to 21252 do
                        if (stay[pos].a=temp.a)and(stay[pos].b=temp.b)and(stay[pos].c=temp.c)
                        then break;
                write('Case ',step,': the next triple peak occurs in ');
                if 21252-pos-mini=0 then
                        write(21252) else
                        if 21252-pos-mini<0 then
                                write(21252-pos-mini+21252)
                                else write(21252-pos-mini);
                writeln(' days.');
                readln(temp.a,temp.b,temp.c,mini);
                end;
          if p<>part then writeln;
        end;
END.
