PROGRAM p2029;

VAR
        o                               :Boolean;
        need                            :Boolean;
        n,m,i,p                         :Longint;
        data                            :array[0..5000]of Longint;

PROCEDURE Find(l,r:Longint);
var
        mid                             :Longint;
begin
if l>r then exit;
if l=r then
        begin
        if (data[l]<=p)and(data[l+1]>p)and(l+1<=n) then
                begin
                o:=false;
                writeln('[',data[l],',',data[l+1],')');
                end;
        exit;
        end;
mid:=(l+r) div 2;
if data[mid]>p then Find(l,mid-1) else
if data[mid]=p then Find(mid,mid) else Find(mid,r-1);
end;

PROCEDURE Sort;
var
        i,j,c,temp                      :Longint;
begin
for i:=1 to n-1 do
        begin
        c:=i;
        for J:=i+1 to n do
                if (data[c]<=data[i-1])or ((data[c]>data[j])and(data[j]>data[i-1])) then c:=j;
        if data[c]>data[i-1] then
                begin
                temp:=data[c];
                data[c]:=data[i];
                data[i]:=temp;
                end else
                begin
                n:=i-1;
                break;
                end;
        end;
end;

BEGIN
while not eof do
        begin
        readln(n,m);
        data[0]:=-2000000000;
        need:=false;
        for i:=1 to n do
                begin
                read(data[i]);
                if data[i]<=data[i-1] then need:=true;
                end;
        readln;
        if need then Sort;
        for i:=1 to m do
                begin
                read(p);
                o:=true;
                Find(1,n);
                if o then writeln('no such interval');
                end;
        readln;
        writeln;
        end;
END.