PROGRAM p1082;

VAR
        n,i,k,j,a               :Integer;
        whether                 :array[1..100,1..100]of Boolean;
        dis                     :array[1..100,1..100]of Integer;

PROCEDURE Main;
var
        i,j,k,cut               :Integer;
        win                     :Boolean;
        max,ans                 :Longint;

begin
for k:=1 to n do
        for i:=1 to n do
                if (i<>k)and whether[i,k] then
                for J:=1 to n do
                        if (i<>j)and(k<>j) and whether[k,j] and ((dis[i,k]+dis[k,j]<dis[i,j]) or (not whether[i,j])) then
                                begin
                                whether[i,j]:=true;
                                dis[i,j]:=dis[i,k]+dis[k,j];
                                end;


ans:=maxlongint;
for i:=1 to n do
        begin
        win:=true;
        max:=0;
        for j:=1 to n do
                if i<>j then
                begin
                if not whether[i,j] then
                        begin
                        win:=false;
                        break;
                        end;
                if dis[i,j]>max then
                        max:=dis[i,j];
                end;
        if win and (max<ans) then
                begin
                ans:=max;
                cut:=i;
                end;
        end;
if (ans<maxlongint) then writeln(cut,' ',ans) else writeln('disjoint');
end;

BEGIN
//assign(input,'p.in');
//reset(input);

readln(n);
while n<>0 do
        begin
        fillchar(whether,sizeof(whether),0);
        fillchar(dis,sizeof(dis),0);
        for i:=1 to n do
                begin
                read(k);
                for J:=1 to k do
                        begin
                        read(a);
                        whether[i,a]:=true;
                        read(dis[i,a]);
                        end;
                readln;
                end;
        Main;
        readln(n);
        end;
END.