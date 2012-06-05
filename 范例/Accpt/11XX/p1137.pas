{
        Using the Max Match
        Time    2005/04/21
}

program p1137;

{$APPTYPE CONSOLE}

const
        maxn=500;

var
        n                       :Integer;
        g,graph                 :array[1..maxn,1..maxn]of Boolean;
        link,boys,girls         :array[1..maxn]of Integer;
        cover                   :array[1..maxn]of Boolean;
        num_boys,num_girls      :Integer;

// It just for input the graph
PROCEDURE Readin;
var
        ch                      :Char;
        i,j,t,a,b               :Integer;
begin
readln(n);

fillchar(g,sizeof(g),0);

for i:=1 to n do
        begin
        a:=0;
        read(ch);
        while (ch<>':') do
                begin
                a:=a*10 + ord(ch)-48;
                read(ch);
                end;
        while (ch<>'(') do read(ch);
        t:=0;
        read(ch);
        while (ch<>')') do
                begin
                t:=t * 10  + ord (ch)-48;
                read(ch);
                end;
        for j:=1 to t do
                begin
                read(b);
                g[a+1][b+1]:=true;
                g[b+1][a+1]:=true;
                end;
        readln;
        end;
end;

PROCEDURE Init;
var
        i                       :Integer;

        Procedure Search(sex,point:Integer);
        var
                i               :Integer;
        begin

        cover[point]:=true;

        if sex=0 then
                begin
                inc(num_boys);
                boys[num_boys]:=point;
                end else
                begin
                inc(num_girls);
                girls[num_girls]:=point;
                end;

        for i:=1 to n do
                if not cover[i] and g[point][i] then Search((sex+1) mod 2,i);

        end;

begin
fillchar(cover,sizeof(cover),0);

num_boys:=0;
num_girls:=0;

for i:=1 to n do
        if not cover[i] then
                if num_boys > num_girls then Search(1,i)
                        else Search(0,i);
end;

FUNCTION Find(v:Integer):Boolean;
var
        i,j,t                   :Integer;
begin
Find:=true;

{for i:=v+1 to num_girls do
        begin
        if cover[i] and g[boys[v]][girls[i]] then
                begin
                t:=link[i];
                link[i]:=v;
                cover[i]:=false;
                if (t=0) or find(t) then exit;
                link[i]:=t;
                end;
        end;
}
//if num_girls < v then v:=num_girls;
for i:=1 to num_girls do
        begin
        if cover[i] and g[boys[v]][girls[i]] then
                begin
                t:=link[i];
                link[i]:=v;
                cover[i]:=false;
                if (t=0) or find(t) then exit;
                link[i]:=t;
                end;
        end;
find:=false;
end;

PROCEDURE Main;
var
        i                       :Integer;
        ans                     :Integer;
begin
fillchar(link,sizeof(link),0);

ans:=0;

for i:=1 to num_boys do
        begin
        fillchar(cover,num_girls,1);
        if find(i) then inc(ans);
        end;

writeln(n-ans);
end;

begin
//assign(input,'p.in');
//reset(input);
repeat
        Readin;
        Init;
        Main;
until eof;
end.
