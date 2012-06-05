PROGRAM p2362;

CONST
        maxn=400;

VAR
        n,part,p                        :Integer;
        whether                         :array[1..maxn,1..maxn]of Boolean;
        edge                            :array[1..maxn,0..maxn]of Integer;
        vector,link,w,ans,start         :array[0..maxn]of Integer;
        cover                           :array[1..maxn]of Boolean;


PROCEDURE Readin;
var
        i,j,k,temp                     :Integer;
begin
readln(n);
for i:=1 to n do read(w[i]);
readln;
fillchar(whether,sizeof(whether),false);
for i:=1 to n do
        begin
        vector[i]:=i;
        read(edge[i][0]);
        for j:=1 to edge[i][0] do
                begin
                read(k);
                whether[i,k]:=true;
                end;
        readln;
        end;
for i:=1 to n do
        begin
        start[i]:=1;
        edge[i][0]:=0;
        for j:=1 to n do
                if whether[i][j] then
                        begin
                        inc(edge[i][0]);
                        edge[i][edge[i][0]]:=j;
                        if j<i then start[i]:=edge[i][0];
                        end;
        end;
end;

PROCEDURE Sort(left,right:Integer);
var
        i,j,key,temp                   :Integer;
begin
i:=left-1;j:=right+1;
key:=w[vector[left]];
repeat
        repeat dec(j) until (w[vector[j]]>=key);
        repeat inc(i) until (w[vector[i]]<=key);
        if (i<j) then
                begin
                temp:=vector[i];
                vector[i]:=vector[j];
                vector[j]:=temp;
                end else break;
until false;
if (j>left) then Sort(left,j);
if (j+1<right) then Sort(j+1,right);
end;

FUNCTION Find(v:Integer):Boolean;
var
        t,i                             :Integer;
begin
find:=true;
for i:=start[v] to edge[v][0] do
        if cover[edge[v][i]] then
                begin
                t:=link[edge[v][i]];
                link[edge[v][i]]:=v;
                cover[edge[v][i]]:=false;
                if ((t=0) or find(t)) then exit;
                link[edge[v][i]]:=t;
                end;
for i:=1 to start[v]-1 do
        if cover[edge[v][i]] then
                begin
                t:=link[edge[v][i]];
                link[edge[v][i]]:=v;
                cover[edge[v][i]]:=false;
                if ((t=0) or find(t)) then exit;
                link[edge[v][i]]:=t;
                end;
find:=false;
end;

PROCEDURE Main;
var
        i,j                             :Integer;
begin
fillchar(link,sizeof(link),0);
for i:=1 to n do
        begin
        fillchar(cover,sizeof(cover),1);
        find(vector[i]);
        end;

fillchar(ans,sizeof(ans),0);
for i:=1 to n do ans[link[i]]:=i;
for i:=1 to n-1 do write(ans[i],' ');
writeln(ans[n]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        Sort(1,n);
        Main;
        end;
END.