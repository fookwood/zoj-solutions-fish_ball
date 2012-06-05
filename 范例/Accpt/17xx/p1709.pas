PROGRAM p1709;


CONST
        change:array[1..8,1..2]of integer=((-1,0),(-1,-1),(-1,1),(0,1),(0,-1),(1,0),(1,-1),(1,1));

VAR
        map     :array[0..101,0..101]of char;
        h,w     :integer;
        part    :integer;
        i,j     :Integer;
        whether :array[0..101,0..101]of boolean;

PROCEDURE search(x,y:integer);
var
        i,j     :integer;
begin
whether[x,y]:=true;
for i:=1 to 8 do
        if (map[x+change[i,1],y+change[i,2]]='@')and(not whether[x+change[i,1],y+change[i,2]]) then
                search(x+change[i,1],y+change[i,2]);
end;

BEGIN
readln(h,w);
while (h<>0)and(w<>0) do
        begin
        for i:=0 to 101 do
                for j:=0 to 101 do
                        map[i,j]:='^';
        for i:=1 to h do
                begin
                for j:=1 to w do
                        read(map[i,j]);
                readln;
                end;
        part:=0;
        fillchar(whether,sizeof(whether),false);
        for i:=1 to h do
                for j:=1 to w do
                if (not whether[i,j])and(map[i,j]='@') then
                        begin
                        search(i,j);
                        inc(part);
                        end;
        writeln(part);
        readln(h,w);
        end;
END.