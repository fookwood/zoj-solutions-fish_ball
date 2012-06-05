PROGRAM p1260;

TYPE
        node=record
                s,t,w                   :Integer;
                lt                      :Boolean;
        end;

VAR
        n,m,i                           :Integer;
        data                            :array[1..100]of Node;
        small,big                       :array[0..100,0..100]of Longint;
        ch1,ch2,ch3                     :Char;

PROCEDURE Main;
var
        flag                            :Boolean;
        ans                             :Boolean;
        i,j,k,ci                        :Integer;
begin
for i:=0 to 100 do for j:=0 to 100 do
        begin
        small[i,j]:=-maxlongint;
        big[i,j]:=maxlongint;
        end;

for i:=1 to m do
        if data[i].lt then
                begin
                if big[data[i].s,data[i].t]>data[i].w then
                        big[data[i].s,data[i].t]:=data[i].w;
                end else
                begin
                if small[data[i].s,data[i].t]<data[i].w then
                        small[data[i].s,data[i].t]:=data[i].w;
                end;
cI:=0;

repeat
flag:=true;
inc(ci);
if ci>200 then break;
for i:=0 to n do
        for j:=i+1 to n do
                for k:=j+1 to n do
                        begin
                        if (small[i,j]<>-maxlongint)and(small[j,k]<>-maxlongint)and(small[i,j]+small[j,k]>small[i,k]) then
                                begin small[i,k]:=small[i,j]+small[j,k];flag:=false;end;
                        if (big[i,j]<>maxlongint)and(big[j,k]<>maxlongint)and(big[i,j]+big[j,k]<big[i,k]) then
                                begin big[i,k]:=big[i,j]+big[j,k];flag:=false;end;
                        if (small[i,j]<>-maxlongint)and(big[i,k]<>maxlongint)and(big[i,k]-small[i,j]<big[j,k]) then
                                begin big[j,k]:=big[i,k]-small[i,j];flag:=false;end;
                        if (big[i,j]<>maxlongint)and(small[i,k]<>-maxlongint)and(small[i,k]-big[i,j]<small[j,k]) then
                                begin small[j,k]:=small[i,k]-big[i,j];flag:=false;end;
                        end;

until flag;

ans:=true;
for i:=0 to n do
        for j:=i+1 to n do
                if small[i,j]>big[i,j] then ans:=false;
if ans then writeln('lamentable kingdom') else writeln('successful conspiracy');
end;

BEGIN
read(n);
while (n<>0) do
        begin
        readln(m);
        for i:=1 to m do
                begin
                read(data[i].s,data[i].t,ch1,ch2,ch3);
                readln(data[i].w);
                data[i].t:=data[i].s+data[i].t;
                dec(data[i].s);
                if ch2='l' then data[i].lt:=true else
                if ch2='g' then data[i].lt:=false else
                while true do ;
                if data[i].lt then dec(data[i].w) else inc(data[i].w);
                end;
        Main;
        read(n);
        end;
END.
