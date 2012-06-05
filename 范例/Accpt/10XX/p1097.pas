PROGRAM p1097;

VAR
        n                       :Integer;
        s                       :String;
        du,father,children,pa   :array[1..50]of Integer;
        whether                 :array[1..50,1..50]of Boolean;


PROCEDURE Init;
var
        t                               :String;
        i,j,k,code,point,long,fa,have   :Integer;
begin
i:=1;
while (i<=length(s)) do
        if s[i]=' ' then delete(s,i,1) else inc(i);
n:=0;
fillchar(du,sizeof(du),0);
fillchar(pa,sizeof(pa),0);
fillchar(father,sizeof(father),0);
fillchar(children,sizeof(children),0);
fillchar(whether,sizeof(whether),0);
for i:=length(s) downto 2 do
        if s[i]='(' then
                begin
                j:=i+1;long:=0;
                while (s[j]<>'(')and(s[j]<>')') do
                        begin
                        inc(long);
                        inc(j);
                        end;
                t:=copy(s,i+1,j-i-1);
                val(t,point,code);
                j:=i-1;
                have:=0;
                while not ((have=0)and(s[j]<>'(')and(s[j]<>')')) do
                        begin
                        if s[j]='(' then dec(have);
                        if s[j]=')' then inc(have);
                        dec(j);
                        end;
                k:=j-1;
                while (s[k]<>'(')and(s[k]<>')') do dec(k);
                t:=copy(s,k+1,j-k);
                val(t,fa,code);
                inc(du[fa]);
                inc(pa[point]);
                father[point]:=fa;
                whether[fa,point]:=true;
                if point>n then n:=point;
                end;
i:=2;
while (s[i]<>'(')and(s[i]<>')') do inc(i);
t:=copy(s,2,i-2);
val(t,point,code);
if point>n then n:=point;
end;

PROCEDURE Main;
var
        i,j,k                           :Integer;
begin
if n=1 then
        begin
        writeln;
        exit;
        end;
for i:=1 to n-1 do
        begin
        k:=n+1;
        for J:=1 to n do
                if (du[j]>=0) then
                begin
                if (du[j]=0)and(father[j]<>0)and(j<k) then k:=j;
                if (du[j]=1)and(father[j]=0)and(j<k) then k:=j;
                end;
        if du[k]=0 then
                begin
                dec(du[father[k]]);
                whether[father[k],k]:=false;
                du[k]:=-1;
                write(father[k]);
                end else
                begin
                for j:=1 to n do if whether[k,j] then break;
                du[k]:=-1;
                write(j);
                father[j]:=0;
                end;
        if i<>n-1 then write(' ');
        end;
writeln;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(s);
        init;
        Main;
        end;
END.
