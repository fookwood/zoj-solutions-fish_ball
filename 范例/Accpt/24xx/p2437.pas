PROGRAM A;

VAR
        n,aa,bb , part , p              :Integer;
        ans,map                         :array[1..200,1..200]of Longint;

PROCEDURE Init;
var
        i,j                             :Integer;
begin
readln(n);
for i:=1 to n do
        begin
        for j:=1 to n do
                read(map[i,j]);
        readln;
        end;
end;

FUNCTION Check(x,y:Integer):Boolean;
begin
if (x<1)or(x>n)or(y<1)or(y>n) then
        begin
        check:=false;
        exit;
        end;
if map[x,y]<>0 then
        begin
        aa:=x;
        bb:=y;
        check:=true;
        end else check:=false;
end;

PROCEDURE Main;
var
        p,q,i,j,l,total                 :Integer;
begin
ans:=map;
for p:=1 to n do
        for q:=1 to n do
                if map[p,q]=0 then
                        begin
                        for l:=1 to 2*n do
                                begin
                                total:=0;
                                for i:=1 to l-1 do
                                        begin
                                        j:=l-i;
                                        if check(p+i,q+j) then inc(total);
                                        if check(p+i,q-j) then inc(total);
                                        if check(p-i,q+j) then inc(total);
                                        if check(p-i,q-j) then inc(total);
                                        if total>1 then break;
                                        end;
                                if check(p+l,q) then inc(total);
                                if check(p-l,q) then inc(total);
                                if check(p,q+l) then inc(total);
                                if check(p,q-l) then inc(total);
                                if total=1 then ans[p,q]:=map[aa,bb];
                                if total<>0 then break;
                                end;
                        end;

for i:=1 to n do
        begin
        for J:=1 to n-1 do write(ans[i,j],' ');
        writeln(ans[i,n]);
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);

readln ( part );
for p := 1 to part do
        begin
        Init;
        Main;
        if p < part then writeln;
        end;
END.
