PROGRAM p1411;

VAR
        part,p                  :Integer;
        s,n                     :Integer;
        area,total_area         :Longint;
        state                   :Integer;
        line,data               :array[1..16]of Integer;
        col,puts                :array[1..160,1..160]of Boolean;

PROCEDURE Readin;
var
        i                       :Integer;
begin
read(s,n);
total_area:=0;
area:=s * s;
fillchar(line,sizeof(line),0);
for i:=1 to n do
        begin
        read(data[i]);
        inc(total_area,sqr(data[i]));
        inc(line[data[i]]);
        end;
end;

PROCEDURE print;
begin
if state=0 then writeln('KHOOOOB!') else writeln('HUTUTU!');
end;

procedure writeout;
var
        i,j                             :Integer;
begin
for i:=1 to s do
        begin
        for J:=1 to s do
                write(ord(col[i][j]));
        writeln;
        end;
end;

PROCEDURE GetSpace(var x,y:Integer);
var
        i,j                             :Integer;
begin
for i:=1 to s do
        for j:=1 to s do
                if not col[i][j] then
                        begin
                        x:=i;
                        y:=j;
                        exit;
                        end;

x:=s+1;y:=s+1;
end;

PROCEDURE Search(dep:Integer);
var
        x,y,i,p,q                       :Integer;
        pass                            :Boolean;
begin
getspace(x,y);
if (x=s+1) then state:=0;

for i:=10 downto 1 do
        if line[i]>0 then
                begin
                if (s-x+1<i) or (s-y+1<i) then continue;

                pass:=true;

                for p:=x to x+i-1 do
                        begin
                        if pass then
                                for q:=y to y+i-1 do
                                        if col[p][q] then
                                                begin
                                                pass:=false;
                                                break;
                                                end;
                        if not pass then break;
                        end;


                if pass and (state=1) then
                        begin
                        for p:=x to x+i-1 do for q:=y to y+i-1 do col[p][q]:=true;
                        dec(line[i]);
                        Search(dep+1);
                        inc(line[i]);
                        for p:=x to x+i-1 do for q:=y to y+i-1 do col[p][q]:=false;
                        end;

                end;

end;

PROCEDURE Main;
var
        i,j,temp                        :Integer;
begin
state:=1;

for i:=1 to n do
        for j:=i+1 to n do
                if data[i]<data[j] then
                        begin
                        temp:=data[i];
                        data[i]:=data[j];
                        data[j]:=temp;
                        end;

if (area<>total_area) then
        begin
        print;
        exit;
        end;

if (n>1) and (data[1]+data[2]>s) then
        begin
        print;
        exit;
        end;

fillchar(col,sizeof(col),0);

Search(1);

print;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        Main;
        end;
END.
