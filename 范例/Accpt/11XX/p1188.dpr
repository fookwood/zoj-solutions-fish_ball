program p1188;

{$APPTYPE CONSOLE}
type
        node=record
                s       :string;
                back    :longint;
                pos     :integer;
                end;

var
        data    :array[1..100]of node;
        n,m     :Integer;
        part,p  :Integer;
        i,j     :Integer;
        k       :integer;

PROCEDURE sort;
var
        i,j     :Integer;
        flag    :boolean;
        temp    :node;
begin
for i:=1 to n-1 do
        for J:=i+1 to n do
                begin
                flag:=false;
                if data[i].back>data[j].back then flag:=true
                        else
                        if (data[i].back=data[j].back)and(data[i].pos>data[j].pos) then flag:=true;
                if flag then
                        begin
                        temp:=data[i];
                        data[i]:=data[j];
                        data[j]:=temp;
                        end;
                end;
end;

begin
readln(part);
readln;
for p:=1 to part do
        begin
        readln(m,n);
        for i:=1 to n do
                begin
                readln(data[i].s);
                data[i].back:=0;
                for J:=1 to m-1 do for k:=j+1 to m do
                        if data[i].s[j]>data[i].s[k] then inc(data[i].back);
                data[i].pos:=i;
                end;
        sort;
        for i:=1 to n do
                writeln(data[i].s);
        if p<>part then writeln;
        if p<>part then readln;
        end;
end.
 