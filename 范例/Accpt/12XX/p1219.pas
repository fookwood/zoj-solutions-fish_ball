PROGRAM p1219;

VAR
        step                    :Integer;
        total                   :Integer;
        num                     :array[0..15]of Byte;
        order                   :array[1..50,0..15,0..1]of Byte;
        find                    :Boolean;


PROCEDURE Readin;
var
        i,j                     :Integer;
        people                  :Integer;
        s                       :String;

begin
fillchar(order,sizeof(order),0);
readln(s);
total:=0;
while (s<>'.') do
        begin
        inc(total);
        while (length(s)>1) do
                begin
                people:=ord(s[2])-ord('A');

                if order[total][people][0]=0 then
                        begin
                        order[total][people][0]:=1;
                        if s[1]='+' then
                                order[total][people][1]:=1;
                        end else
                        begin
                        if (s[1]='+')and
                                (order[total][people][1]=0)
                                then
                                begin
                                dec(total);
                                break;
                                end;
                        if (s[1]='-') and
                                (order[total][people][1]=1) then
                                begin
                                dec(total);
                                break;
                                end;
                        end;
                delete(s,1,2);
                end;
        readln(s);
        end;

{for i:=1 to total do
        begin
        for j:=0 to 15 do write(order[i][j][0],' ');
        writeln;
        end; }

end;

FUNCTION Check:Boolean;
var
        i,j                     :Integer;
        satisfy                 :Boolean;

begin
for i:=1 to total do
        begin
        satisfy:=false;
        for j:=0 to 15 do
                if order[i][j][0]=1 then
                        if (order[i][j][1] = num[j]) then
                                begin
                                satisfy:=true;
                                break;
                                end;

        if not satisfy then
                begin
                check:=false;
                exit;
                end;
        end;
check:=true;
end;

PROCEDURE Print;
var
        i                       :Integer;
begin
if find then
        begin
        write('Toppings: ');
        for i:=0 to 15 do
                if num[i]=1 then
                        write(chr(i+ord('A')));
        writeln;
        end else
        writeln('No pizza can satisfy these requests.');
end;

PROCEDURE Search(dep:Integer);
var
        i                       :Integer;
begin
if dep=-1 then
        begin
        if check then
                begin
                find:=true;
                print;
                end;
        exit;
        end;

num[dep]:=0;
search(dep-1);

if find then exit;

num[dep]:=1;
search(dep-1);

end;

BEGIN
//assign(input,'p.in');
//reset(input);
while (not eof ) do
        begin
        find:=false;
        Readin;
        Search(15);
        fillchar(num,sizeof(num),0);
        if not find then print;
        end;
END.
