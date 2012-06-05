PROGRAM p1387;

CONST
        maxn=10000;

TYPE
        NodeType=record
        struct                  :Byte;
        left,right,w            :Integer;
        end;

VAR
        part,p,n,availue,t      :Integer;
        order                   :array['A'..'Z']of String[6];
        ans                     :array[0..maxn]of Int64;
        data                    :array[1..maxn]of Char;
        line                    :array[1..maxn * 200]of NodeType;


PROCEDURE MakeOrder;
begin
order['A']:='.-';
order['B']:='-...';
order['C']:='-.-.';
order['D']:='-..';
order['E']:='.';
order['F']:='..-.';
order['G']:='--.';
order['H']:='....';
order['I']:='..';
order['J']:='.---';
order['K']:='-.-';
order['L']:='.-..';
order['M']:='--';
order['N']:='-.';
order['O']:='---';
order['P']:='.--.';
order['Q']:='--.-';
order['R']:='.-.';
order['S']:='...';
order['T']:='-';
order['U']:='..-';
order['V']:='...-';
order['W']:='.--';
order['X']:='-..-';
order['Y']:='-.--';
order['Z']:='--..';
end;

PROCEDURE Add(var s:String);
var
        t                                       :String;
        i,p                                     :Integer;
begin
t:='';
for i:=1 to length(s) do
        t:=t + order[s[i]];

if length(t)>=254 then while true do ;

p:=1;
for i:=length(t) downto 1 do
        if t[i]='.' then
                begin
                if line[p].left=0 then
                        begin
                        line[p].left:=availue;

                        with line[availue] do
                                begin
                                struct:=0;
                                left:=0;
                                right:=0;
                                w:=0;
                                end;

                        p:=availue;
                        inc(availue);
                        end else
                        p:=line[p].left;
                end else
                begin
                if line[p].right=0 then
                        begin
                        line[p].right:=availue;

                        with line[availue] do
                                begin
                                struct:=0;
                                left:=0;
                                right:=0;
                                w:=0;
                                end;

                        p:=availue;
                        inc(availue);
                        end else
                        p:=line[p].right;
                end;

line[p].struct:=1;
inc(line[p].w);
end;

PROCEDURE Init;
var
        i                                       :Integer;
        s                                       :String;
begin
n:=0;
while not eoln do
        begin
        inc(n);
        read(data[n]);
        end;
readln;

availue:=2;
with line[1] do
        begin
        struct:=0;
        left:=0;
        right:=0;
        w:=0;
        end;

readln(t);
for i:=1 to t do
        begin
        readln(s);
        Add(s);
        end;

ans[0]:=1;
end;

PROCEDURE Search(a:Integer);
var
        p,b                             :Integer;
begin
p:=1;
b:=a;
while (b>0) do
        begin
        if data[b]='.' then
                p:=line[p].left
                        else
                p:=line[p].right;
        dec(b);
        if p=0 then break;
        if line[p].struct=1 then ans[a]:=ans[a]+ ans[b] * line[p].w;
        end;
end;

PROCEDURE Main;
var
        i                               :Integer;
begin
for i:=1 to n do
        begin
        ans[i]:=0;
        Search(i);
        end;
writeln(ans[n]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
makeorder;
readln(part);
for p:=1 to part do
        begin
        Init;
        Main;
        end;
END.