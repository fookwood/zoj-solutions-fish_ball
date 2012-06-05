PROGRAM p1580;

CONST
        Maxn   =        1000;
        small  =        1e-14;

TYPE
        PosType=record
        x,y                     :Extended;
        end;

VAR
        n,ni                    :Integer;
        ans                     :Longint;
        data                    :array[1..maxn]of PosType;
        total                   :Longint;
        have,after              :array[1..maxn]of Extended;
        w                       :array[1..maxn]of Integer;

PROCEDURE Make(a,b,c:Integer);
var
        x,y                     :Extended;
begin
x:=data[b].x-data[a].x;
y:=data[b].y-data[a].y;

if abs(x)<small then
        begin
        if y>0 then have[c]:=pi / 2
                else have[c]:=pi * 1.5;
        exit;
        end;

if abs(y)<small then
        begin
        if x>0 then have[c]:=0
                else have[c]:=pi;
        exit;
        end;

if x>0 then
        begin
        if y>0 then have[c]:=arctan(y/x)
                else have[c]:=2 * pi +arctan(y/x);
        end else
        have[c]:=pi + arctan(y/x);
end;

PROCEDURE Sort(left,right:Integer);
var
        i,j                     :Integer;
        temp,key                :Extended;
begin
i:=left-1;
j:=right+1;
key:=have[left];
repeat
        repeat dec(j); until have[j] < key + small;
        repeat inc(i); until have[i] > key - small;
        if (i<j) then
                begin
                temp:=have[i];
                have[i]:=have[j];
                have[j]:=temp;
                end else break;
until false;
if j+1<right then Sort(j+1,right);
if left<i-1 then sort(left,i-1);
end;

PROCEDURE Main;
var
        i,j,p,q                 :Integer;
        left,right,mid          :Integer;
        goal                    :Extended;
begin
ans:=0;

if n<3 then
        begin
        writeln(ans);
        exit;
        end;

have[n]:=1e10;

for i:=1 to n do
        begin
        for j:=1 to n do
                if i>j then Make(i,j,j) else
                if i<j then make(i,j,j-1);



        Sort(1,n-1);

        total:=0;
        q:=1;
        p:=1;

        for j:=1 to n-1 do
                if have[j+1]-have[j]>small then
                        begin
                        inc(total);
                        after[total]:=have[p];
                        w[total]:=q;
                        p:=j+1;
                        q:=1;
                        end else inc(q);

        after[total+1]:=1e10;

        for j:=1 to total do
                begin
                goal:=after[j] + pi / 2;
                if goal + small > 2 * pi then goal:=goal - 2 * pi;

                left:=1;
                right:=total+1;
                while (left<=right) do
                        begin
                        mid:=(left + right) div 2;
                        if abs(after[mid]-goal)<small then
                                begin
                                left:=right+1;
                                ans:=ans + w[j] * w[mid];
                                //writeln('find ',j,' ',mid,' ',goal:0:4);
                                end else
                        if after[mid]>goal then right:=mid-1
                                else
                                left:=mid+1;
                        end;
                end;
        //writeln('i & ans ',i,' ',ans);
        end;
writeln(ans);
end;

BEGIN
while not eof do
        begin
        readln(n);
        for ni:=1 to n do readln(data[ni].x,data[ni].y);
        Main;
        end;
END.