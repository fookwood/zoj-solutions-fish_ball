PROGRAM p1268;

CONST
        maxsize=1000;

VAR
        step,total,i            :Integer;
        whether                 :Boolean;
        a,b                     :Integer;
        name                    :array[1..maxsize]of Integer;
        father                  :array[1..maxsize]of Integer;
        num                     :array[1..maxsize]of Integer;
        have                    :array[1..maxsize]of Boolean;

PROCEDURE MakeNull;
var
        i,j                     :Integer;
begin
for i:=1 to maxsize do
        begin
        father[i]:=0;
        name[i]:=i;
        end;
end;

FUNCTION Find(x:Integer):Integer;
var
        i,j,p                   :Integer;
begin
i:=x;
while father[i]<>0 do i:=father[i];
Find:=name[i];
j:=x;
while father[j]<>0 do
        begin
        name[j]:=name[i];
        p:=j;
        j:=father[j];
        father[p]:=0;
        end;
end;

FUNCTION Unite(a,b:Integer):Boolean;
var
        p,q                             :Integer;
begin
p:=find(a);
q:=find(b);
if p=q then
        begin
        Unite:=false;
        exit;
        end;
father[q]:=p;
Unite:=true;
end;

BEGIN
read(a,b);
while (a<>-1)and(b<>-1) do
        begin
        inc(step);
        MakeNull;
        whether:=true;
        fillchar(have,sizeof(have),0);
        while (a<>0)or(b<>0) do
                begin
                if whether then whether:=Unite(a,b);
                have[a]:=true;have[b]:=true;
                read(a,b);
                end;
        total:=0;
        for i:=1 to maxsize do if have[i] then
                begin
                inc(total);
                num[total]:=i;
                end;
        for I:=2 to total do
                if find(num[i])<>find(num[i-1])  then whether:=false;
        if whether then writeln('Case ',step,' is a tree.')
                else writeln('Case ',step,' is not a tree.');
        read(a,b);
        end;
END.