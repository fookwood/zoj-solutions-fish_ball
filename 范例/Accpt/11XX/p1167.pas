PROGRAM p1167;

TYPE
        Node=record
                value           :Integer;
                pos             :String;
        end;

VAR
        total                   :Integer;
        data                    :array[1..256]of Node;
        line,left,right         :array[1..256]of Integer;
        reach                   :array[1..256]of Byte;
        tree                    :Integer;


PROCEDURE Readin;
var
        i                       :Integer;
        ch                      :Char;
begin
total:=0;
read(ch);
while true do
        begin
        while (ch<>'(') do read(ch);
        read(ch);
        if ch=')' then break;
        inc(total);
        with data[total] do
                begin
                value:=0;
                while (ch<>',') do
                        begin
                        value:=value*10+ord(ch)-48;
                        read(ch);
                        end;
                read(ch);
                pos:='';
                while (ch<>')') do
                        begin
                        pos:=pos+ch;
                        read(ch);
                        end;
                end;
        end;
if eoln then readln;
//writeln('Here are the data:');
//for i:=1 to total do
//        writeln(i:3,data[i].value:5,data[i].pos:9);
end;

FUNCTION find(s:String):Integer;
var
        i                               :Integer;
begin
for i:=1 to total do
        if data[i].pos=s then
                begin
                find:=i;
                exit;
                end;
find:=0;
end;

PROCEDURE print(v:Integer);
begin
if v=0 then exit;
if left[v]<>0 then write(' ',data[left[v]].value);
if right[v]<>0 then write(' ',data[right[v]].value);
print(left[v]);
print(right[v]);
end;

PROCEDURE Dfs;
var
        open,closed,j                   :Integer;
        s                               :String;
begin


fillchar(reach,sizeof(reach),0);
fillchar(left,sizeof(left),0);
fillchar(right,sizeof(right),0);
open:=1;
closed:=1;
line[1]:=find('');
if line[1]=0 then
        begin
        writeln('not complete');
        exit;
        end;
reach[line[1]]:=1;
tree:=line[1];

repeat
        s:=data[line[open]].pos+'L';
        j:=find(s);

        if (j<>0) and (reach[j]=0) then
                begin
                reach[j]:=1;
                inc(closed);
                line[closed]:=j;
                left[line[open]]:=j;
                end;

        s:=data[line[open]].pos+'R';
        j:=find(s);
        if (j<>0) and (reach[j]=0) then
                begin
                reach[j]:=1;
                inc(closed);
                line[closed]:=j;
                right[line[open]]:=j;
                end;

        inc(open);
until open>closed;

//writeln('Here are the node reached:');
//for j:=1 to total do if reach[j]=1 then write(j,' ');
//writeln;

for j:=1 to total do
        if reach[j]=0 then
                begin
                writeln('not complete');
                exit;
                end;

fillchar(reach,sizeof(reach),0);
open:=1;
closed:=1;
line[1]:=tree;
write(data[tree].value);
repeat
        s:=data[line[open]].pos+'L';
        j:=find(s);
        if j<>0 then
                begin
                write(' ',data[j].value);
                inc(closed);
                line[closed]:=j;
                end;

        s:=data[line[open]].pos+'R';
        j:=find(s);
        if j<>0 then
                begin
                write(' ',data[j].value);
                inc(closed);
                line[closed]:=j;
                end;

        inc(open);
until open>closed;
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Dfs;
        end;
END.