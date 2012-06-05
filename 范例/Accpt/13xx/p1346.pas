PROGRAM p1346;

CONST
        Maxn=16;

VAR
        n,total                 :Longint;
        name                    :array[1..maxn]of String;
        ans                     :array[0..65535]of Longint;
        ind,order               :array[1..maxn+1]of Longint;
        whether                 :array[1..maxn,1..maxn]of Boolean;

PROCEDURE MakeOrder;
var
        i                       :Longint;
begin
order[1]:=1;
for i:=2 to maxn+1 do order[i]:=order[i-1] shl 1;
end;

PROCEDURE Readin;
var
        i,p,q                   :Longint;
        s                       :String;

        Function number(t:String):Longint;
        var
                i               :Longint;
        begin
        for i:=1 to total do
                if name[i]=t then
                        begin
                        number:=i;
                        exit;
                        end;
        inc(total);
        name[total]:=t;
        number:=total;
        end;

begin
readln(n);
total:=0;
fillchar(ind,sizeof(ind),0);
fillchar(whether,sizeof(whether),0);

for i:=1 to n do
        begin
        readln(s);
        p:=number(copy(s,1,pos(' ',s)-1));
        q:=number(copy(s,pos(' ',s)+1,length(s)-pos(' ',s)));
        if whether[p][q] then continue;
        whether[p][q]:=true;
        inc(ind[q]);
        end;

while not eof and eoln do readln;

for i:=1 to order[total+1]-1 do ans[i]:=-1;
ans[0]:=1;
end;

FUNCTION Answer(p:Longint):Longint;
var
        i,j                             :Longint;
begin
if ans[p]>=0 then
        begin
        Answer:=ans[p];
        exit;
        end;

ans[p]:=0;
for i:=1 to total do
        if (ind[i]=0) and (p and order[i] = order[i]) then
                begin
                for j:=1 to total do
                        if whether[i][j] then dec(ind[j]);

                ans[p]:=ans[p] + Answer(p xor order[i]);

                for j:=1 to total do
                        if whether[i][j] then inc(ind[j]);
                end;

Answer:=ans[p];
end;

BEGIN
//assign(input,'p.in');
//reset(input);

makeOrder;
while not eof do
        begin
        Readin;
        writeln(Answer(order[total+1]-1));
        end;
END.
