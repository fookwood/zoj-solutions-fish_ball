PROGRAM p1639;

VAR
        n,step                  :Integer;
        name                    :array[1..16]of String;
        order,cost              :array[1..17]of Longint;
        get                     :array[0..65535]of Longint;
        whether                 :array[0..65535]of Boolean;

PROCEDURE MakeOrder;
var
        i                       :Integer;
begin
order[1]:=1;
for i:=2 to 17 do order[i]:=order[i-1] shl 1;
end;

FUNCTION Find(var s:String):Integer;
var
        i                       :Integer;
begin
for i:=1 to n do if name[i]=s then begin find:=i; exit end;
end;

PROCEDURE Separate(v:Longint);
var
        i                       :Integer;
begin
for i:=1 to n do
        if v and order[i] = order[i] then write(i, ' ');
        writeln;
end;


PROCEDURE Readin;
var
        i,code,p,m,j            :Integer;
        d                       :Longint;
        s,t                     :String;
begin
readln(n);
if n=0 then halt;
inc(step);
write('System ',step,': ');
for i:=1 to n do
        begin
        readln(s);
        name[i]:=copy(s,1,pos(' ',s)-1);
        delete(s,1,pos(' ',s));
        val(s,cost[i],code);
        end;
readln(m);
fillchar(whether,sizeof(whether),1);
for i:=1 to m do
        begin
        readln(s);
        d:=0;
        j:=pos(' ',s);
        while (j>0) do
                begin
                t:=copy(s,1,j-1);
                delete(s,1,j);
                j:=pos(' ',s);
                p:=find(t);
                d:=d or order[p];
                end;
        d:=d or order[find(s)];
        whether[d]:=false;
        end;
end;


PROCEDURE Main;
var
        i,j,k,max                       :Longint;
begin
max:=0;
fillchar(get,sizeof(get),0);
for i:=1 to n do if whether[order[i]] then
        begin
        get[order[i]]:=cost[i];
        if get[order[i]]>max then max:=get[order[i]];
        end;

for i:=1 to order[n+1]-1 do
        if whether[i] and (get[i]>=0) then
                begin
                for j:=1 to n do
                        if (i or order[j] <> order[j])and(i and order[j]=order[j]) then
                                if get[i xor order[j]]+cost[j]>get[i] then
                                        begin
                                        get[i]:=get[i xor order[j]] +cost[j];
                                        if get[i]>max then max:=get[i];
                                        end
                end else
        for j:=1 to n do
                get[i or order[j]]:=-1;

writeln(max);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrder;
step:=0;
while true do
        begin
        Readin;
        Main;
        end;
END.