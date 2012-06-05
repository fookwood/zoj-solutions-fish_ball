PROGRAM p1119;

{$APPTYPE CONSOLE}

CONST
        maxn=1000;

VAR
        g               :array[1..maxn,1..maxn]of Integer;
        stack           :array[1..maxn]of Integer;
        tot_s,tot_search,n,reach,j,x
                        :Integer;

        step            :Integer;
        haveone,firsttest
                        :Boolean;

        ans,cover       :array[1..maxn]of Boolean;
        number,minturch :array[1..maxn]of Integer;


PROCEDURE Showtime;
var
        i,j             :Longint;
begin
for i:=1 to 2000 do
        for J:=1 to 9999999 do ;
end;

PROCEDURE Push(v:Integer);
begin
inc(tot_s);
stack[tot_s]:=v;
end;

FUNCTION Pop:Integer;
begin
pop:=stack[tot_s];
dec(tot_s);
end;


PROCEDURE ReadIn;
var
        a,b             :Integer;
begin
fillchar(g,sizeof(g),0);
        // graph
fillchar(stack,sizeof(stack),0);
        // the stack
fillchar(ans,sizeof(ans),0);
        // if ans[i] then ans[i] is one of the answers
tot_s:=0;
        // the top of stack
x:=0;
fillchar(number,sizeof(number),0);
fillchar(minturch,sizeof(minturch),0);
n:=0;
tot_search:=1002;
read(a);
if a=0 then
        begin
        //writeln('finish input');
        //showtime;
        halt;
        end;

if not firsttest then writeln;

while (a<>0) do
        begin
        readln(b);
        g[a][b]:=1;
        g[b][a]:=1;
        if a>n then n:=a;
        if b>n then n:=b;
        if a<tot_search then tot_search:=a;
        if b<tot_search then tot_search:=b;
        read(a);
        end;

push(tot_search);
reach:=1;
number[tot_search]:=reach;
minturch[tot_search]:=reach;
end;

PROCEDURE algorithm(v:Integer);
var
        u                       :Integer;
begin
for u:=tot_search to n do
        if g[v][u]>0 then
                begin
                if number[u]=0 then
                        begin
                        inc(reach);
                        number[u]:=reach;
                        minturch[u]:=reach;
                        algorithm(u);
                        if minturch[u]<minturch[v] then minturch[v]:=minturch[u];
                        if minturch[u]>=number[v] then
                                begin
                                ans[v]:=true;
                                if v=tot_search then inc(x);
                                end;
                        end else
                        if number[u]<minturch[v] then minturch[v]:=number[u];
                end;
end;

FUNCTION check(v:Integer):Integer;
var
        i,j                     :Integer;
        procedure search(v:Integer);
        var
                i               :Integer;
        begin
        cover[v]:=true;
        for i:=tot_search to n do
                if (g[v][i]=1) and not cover[i] then Search(i);
        end;
begin
j:=0;
for i:=tot_search to n do
        if not cover[i] then
                begin
                inc(j);
                Search(i);
                end;
check:=j;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
firsttest:=true;
step:=0;
while true do
        begin
        inc(step);

        ReadIn;
        writeln('Network #',step);

        algorithm(tot_search);



        if x<=1 then ans[tot_search]:=false;

        haveone:=false;

        firsttest:=false;
        
        for j:=tot_search to n do
                begin
                fillchar(cover,n+n,0);
                cover[j]:=true;
                if ans[j] then
                        begin
                        haveone:=true;
                        writeln('  SPF node ',j,' leaves ',check(j),' subnets');
                        end;
                end;

        if not haveone then writeln('  No SPF nodes');

        end;
END.
