PROGRAM p2165;


CONST
        change  :array[1..4,1..2]of integer=(
                (-1,0),(0,1),(1,0),(0,-1));

VAR
        map     :array[1..20,1..20]of char;
        whether :array[1..20,1..20]of boolean;
        h,w     :integer;
        i,j     :Integer;
        p,q     :Integer;
        ans     :integer;

PROCEDURE search(a,b    :integer);
var     k       :integer;
        c,d     :integer;

begin
for k:=1 to 4 do
        begin
        c:=a+change[k,1];
        d:=b+change[k,2];
        if (c>0)and(c<=h)and(d>0)and(d<=w)and(map[c,d]='.')and(not whether[c,d])then
                begin
                inc(ans);
                whether[c,d]:=true;
                search(c,d);
                end;
        end;
end;


BEGIN
readln(w,h);
while (w<>0)or(h<>0) do
        begin
        fillchar(whether,sizeof(whether),false);
        ans:=1;
        for i:=1 to h do
                begin
                for j:=1 to w do
                        begin
                        read(map[i,j]);
                        if map[i,j]='@' then
                                begin
                                p:=i;
                                q:=j;
                                end;
                        end;
                readln;
                end;
        search(p,q);
        writeln(ans);
        readln(w,h);
        end;
END.