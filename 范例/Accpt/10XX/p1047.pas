PROGRAM p1047;

CONST
     change:array[1..8,1..2]of integer=(
     (-1,-1),(1,1),(-1,1),(1,-1),(0,-1),(0,1),(1,0),(-1,0));

VAR
   map  :array[1..100,1..100]of char;
   whether :array[1..100,1..100]of boolean;
   a,b  :integer;
   w,h  :integer;
   i,j  :integer;
   ans  :longint;

PROCEDURE search(x,y:integer);
var
   i,j  :integer;
   p,q  :integer;
begin
whether[x,y]:=true;
for I:=5 to 8 do
    begin
    p:=x+change[i,1];
    q:=y+change[i,2];
    if (p<1)or(q<1)or(p>h)or(q>w) then
       begin
       inc(ans);
       end else
       if map[p,q]='.' then
        begin
        inc(ans);  end;
    end;
for i:=1 to 8 do
    begin
    p:=x+change[i,1];
    q:=y+change[i,2];
    if (p>0)and(q>0)and(p<=h)and(q<=w)and(not whether[p,q])and (map[p,q]='X') then
       search(p,q);
    end;

end;


BEGIN
readln(h,w,a,b);
while(w<>0)or(h<>0)or(a<>0)or(b<>0) do
      begin
      fillchar(whether,sizeof(whether),false);
      for i:=1 to h do
          begin
          for j:=1 to w do read(map[i,j]);
          readln;
          end;
      ans:=0;
      search(a,b);
      writeln(ans);
      readln(h,w,a,b);
      end;
END.
