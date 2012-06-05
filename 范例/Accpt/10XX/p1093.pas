PROGRAM p1093;


TYPE
        node=record
                x,y,z   :longint;
                end;

VAR
        n       :longint;
        pack    :array[1..180]of node;
        ans     :array[1..180]of longint;
        a,c,b   :longint;
        i       :longint;
        j       :longint;
        max     :longint;
PROCEDURE sort;
var
        i,j,k   :longint;
        temp    :node;
        flag    :boolean;
begin
for i:=1 to 6*n do
        for j:=i+1 to 6*n do
                begin
                flag:=false;
                if pack[i].x>pack[j].x then flag:=true
                        else
                        if pack[i].x=pack[j].x then
                                begin
                                if pack[i].y>pack[j].y then flag:=true
                                        else
                                        if (pack[i].y=pack[j].y)and(pack[i].z>=pack[j].z) then flag:=true;
                                end;
                if flag then
                        begin
                        temp:=pack[i];
                        pack[i]:=pack[j];
                        pack[j]:=temp;
                        end;
                end;
end;


PROCEDURE best;
var
        I,j     :longint;
begin
ans[1]:=pack[1].z;
for i:=2 to 6*n do
        begin
        ans[i]:=0;
        for J:=1 to i-1 do
                if (pack[j].x<pack[i].x) and (pack[j].y<pack[i].y) and (ans[j]>ans[i]) then
                        ans[i]:=ans[j];
        ans[i]:=ans[i]+pack[i].z;
        end;
end;

BEGIN
readln(n);
j:=0;
while n<>0 do
        begin
        inc(j);
        for I:=1 to n do
                begin
                readln(a,b,c);
                if (a=0)or(b=0)or(c=0) then
                        begin
                        a:=0;
                        b:=0;
                        c:=0;
                        end;
                with pack[6*i-5] do
                        begin
                        x:=a;
                        y:=b;
                        z:=c;
                        end;
                with pack[6*i-4] do
                        begin
                        x:=b;
                        y:=a;
                        z:=c;
                        end;
                with pack[6*i-3] do
                        begin
                        x:=c;
                        y:=b;
                        z:=a;
                        end;
                with pack[6*i-2] do
                        begin
                        x:=c;
                        y:=a;
                        z:=b;
                        end;
                with pack[6*i-1] do
                        begin
                        x:=a;
                        y:=c;
                        z:=b;
                        end;
                with pack[6*i] do
                        begin
                        x:=b;
                        y:=c;
                        z:=a;
                        end;
                end;
        sort;
        best;
        max:=0;
        for i:=1 to 6*n do if ans[i]>max then max:=ans[i];
        writeln('Case ',j,': maximum height = ',max);
        readln(n);
        end;
END.
