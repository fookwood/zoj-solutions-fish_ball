PROGRAM p2448;


VAR
        part,p,n,m              :Integer;
        max,ansx,ansy           :Integer;
        data                    :array[1..60,1..60]of Integer;
        map                     :array[1..1000,1..1000]of Char;


PROCEDURE Readin;
var
        i,j                     :Integer;
begin
max:=0;
readln(n,m);
for i:=1 to n do
        begin
        for j:=1 to m do
                begin
                read(data[i][j]);
                if data[i][j]>max then max:=data[i][j];
                end;
        readln;
        end;
fillchar(map,sizeof(map),'.');
ansx:=0;
ansy:=0;
end;

PROCEDURE Make(x,y:Integer);
var
        i                               :Integer;
begin
map[x+6][y-1]:='+';
map[x][y]:='+'; map[x+4][y]:='+';
map[x][y-3]:='+'; map[x+4][y-3]:='+';
map[x+2][y+2]:='+'; map[x+6][y+2]:='+';

map[x+5][y-2]:='/';
map[x+1][y+1]:='/';map[x+5][y+1]:='/';

for i:=1 to 3 do
        begin
        map[x+2+i][y+2]:='-';
        map[x+i][y]:='-';
        map[x+i][y-3]:='-';
        map[x+i+1][y+1]:=' ';
        map[x+i][y-1]:=' ';
        map[x+i][y-2]:=' ';
        end;

for i:=1 to 2 do
        begin
        map[x][y-i]:='|';
        map[x+4][y-i]:='|';
        map[x+6][y-1+i]:='|';
        map[x+5][y-2+i]:=' ';
        end;
if x+6>ansx then ansx:=x+6;
if y+2>ansy then ansy:=y+2;
end;

PROCEDURE print;
var
        i,j                             :Integer;
begin
for i:=ansy downto 1 do
         begin
         for j:=1 to ansx do write(map[j][i]);
         writeln;
         end;
end;

PROCEDURE Main;
var
        i,j,k                           :Integer;
        dx,dy                           :Longint;

begin
for k:=1 to max do
        begin
        for i:=1 to n do
                for j:=1 to m do
                        if data[i][j]>=k then
                                begin
                                dx:=1;
                                dy:=4 + (k-1) * 3;
                                Make(dx + (j-1) * 4  + (n-i) * 2 ,dy + (n-i) * 2);
                                end;
        end;

print;

end;

BEGIN
assign(input,'p.out');
reset(input);
assign(output,'p.in');
rewrite(output);
readln(part);
for p:=1 to part do
        begin
        Readin;
        Main;
        if p<part then writeln;
        end;
close(output);
END.
