program p1109;

{$APPTYPE CONSOLE}

type
        point=^node;
        node=record
                left,right      :point;
                pre,pri         :string[11];
                end;

var
        dic     :point;
        s       :string;
        t       :string;
        j       :integer;
        tp      :point;

FUNCTION find   :boolean;
begin
tp:=dic;
while (tp<>nil)and(tp^.pre<>s) do
        if s<tp^.pre then tp:=tp^.left
                else tp:=tp^.right;
if tp<>nil then
        begin
        find:=true;
        writeln(tp^.pri);
        end else find:=false;
end;


PROCEDURE pour;
var
        fp      :point;
begin
while s[j]<>' ' do inc(j);
t:=copy(s,1,j-1);
delete(s,1,j);
tp:=dic;
fp:=tp;
while tp<>nil do
        if s<tp^.pre then
                begin
                fp:=tp;
                tp:=tp^.left
                end
                else
                begin
                fp:=tp;
                tp:=tp^.right;
                end;
new(tp);
if s<fp^.pre then fp^.left:=tp else fp^.right:=tp;
j:=1;
tp^.pre:=s;
tp^.pri:=t;
tp^.left:=nil;
tp^.right:=nil;
end;


begin
new(dic);
readln(s);
if s<>'' then
        begin
        j:=1;
        while s[j]<>' ' do inc(j);
        t:=copy(s,1,j-1);
        delete(s,1,j);
        dic^.pre:=s;
        dic^.pri:=t;
        dic^.left:=nil;
        dic^.right:=nil;
        end else dic^.pre:='';

readln(s);
while s<>'' do
        begin
        pour;
        readln(s);
        end;


repeat
readln(s);
if not find then writeln('eh');
until eof ;
end.
