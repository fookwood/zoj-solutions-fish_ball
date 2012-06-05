PROGRAM p1811;

VAR
        find                    :Boolean;
        a,b,total,p,reach       :Integer;
        pass,stop,wait          :array[0..100]of Boolean;
        up,down                 :array[0..100]of Integer;
        die                     :array[0..1005]of Integer;
        pos                     :array[1.. 5]of Integer;

PROCEDURE LetGo(who:Integer);
var
        nothing                 :Boolean;
begin
inc(reach);
if pos[who]+die[reach]=100 then
        begin
        find:=true;
        writeln(who);
        exit;
        end;
if pos[who]+die[reach]<100 then
        begin
        pos[who]:=pos[who]+die[reach];
        repeat
        nothing:=true;
        if up[pos[who]]<>0 then
                begin
                pos[who]:=up[pos[who]];
                nothing:=false;
                end;
        if down[pos[who]]<>0 then
                begin
                pos[who]:=down[pos[who]];
                nothing:=false;
                end;
        if pass[pos[who]] then
                begin
                inc(reach);
                LetGo(who);
                exit;
                end;
        if stop[pos[who]] then
                begin
                wait[who]:=true;
                exit;
                end;
        until nothing;
        end;
end;

Procedure print;
var
i               :Integer;
begin
for I:=1 to p do write(pos[i],' ');  write('    ');
end;

PROCEDURE Main;
var

        i,who               :Integer;
begin
up[0]:=0;down[0]:=0;pass[0]:=false;stop[0]:=false;
fillchar(wait,sizeof(wait),0);
for i:=1 to p do pos[i]:=0;
reach:=0;
who:=1;
find:=false;
repeat
        if not wait[who] then
                begin
                LetGo(who);
                if find then break;
                end else wait[who]:=false;
        inc(who);
        if who=p+1 then  who:=1;
until false;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
read(a);
while a<>0 do
        begin
        inc(total);
        die[total]:=a;
        read(a);
        end;
readln;
readln(p);
while p<>0 do
        begin
        total:=0;
        readln(a,b);
        fillchar(up,sizeof(up),0);
        fillchar(down,sizeof(down),0);
        fillchar(pass,sizeof(pass),0);
        fillchar(stop,sizeof(stop),0);
        while (a<>0)or(b<>0) do
                begin
                if a>b then down[a]:=b;
                if a<b then up[a]:=b;
                readln(a,b);
                end;
        readln(a);
        while (a<>0) do
                begin
                if a<0 then stop[-a]:=true;
                if a>0 then pass[a]:=true;
                readln(a);
                end;
        Main;
        readln(p);
        end;
END.