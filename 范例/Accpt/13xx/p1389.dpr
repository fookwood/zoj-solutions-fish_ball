PROGRAM p1389;

TYPE
        DataType=record
        joinin                          :Boolean;
        pos_,w                          :Longint;
        end;

VAR
        n,part,p                        :Longint;
        finish,total                    :Longint;
        data                            :array[1..100000]of DataType;

PROCEDURE Readin;
var
        i,a,b,c,d                       :Longint;
begin
readln(n);
total:=0;
for i:=1 to n do
        begin
        readln(a,b,c,d);
        with data[i+i-1] do
                begin
                joinin:=true;
                pos_:=a;
                w:=c * d;
                end;
        with data[i+i] do
               begin
               joinin:=false;
               pos_:=a+b;
               w:=c * d;
               end;
        total:=total + b * c * d;
        end;
readln(finish);
end;

PROCEDURE Sort(left,right:Integer);
var
        i,j                                     :Longint;
        key                                     :Longint;
        temp                                    :DataType;
begin
i:=left-1;
j:=right+1;
key:=data[left].pos_;
repeat
        repeat dec(j); until data[j].pos_<=key;
        repeat inc(i); until data[i].pos_>=key;
        if i<j then
                begin
                temp:=data[i];
                data[i]:=data[j];
                data[j]:=temp;
                end else break;
until false;
if j+1<right then Sort(j+1,right);
if left<i-1 then Sort(left,i-1);
end;

PROCEDURE Search;
var
        i                                       :Longint;
        count,reach                             :Longint;
        ans                                     :Extended;
begin
if total<finish then
        begin
        writeln('OVERFLOW');
        exit;
        end;

Sort(1,n+n);


count:=data[1].w;
reach:=0;

for i:=2 to n + n do
        begin
        reach:=reach + count * ( data[i].pos_ - data[i-1].pos_);
        if reach>=finish then break;

        if data[i].joinin then inc(count,data[i].w)
                else dec(count,data[i].w);
        end;

ans:=data[i].pos_;
if reach>finish then ans:=ans - (reach - finish) / count;
writeln(ans:0:2);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        Search;
        end;
END.
