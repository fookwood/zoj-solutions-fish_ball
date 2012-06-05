PROGRAM p1038;

CONST
        Maxn=3000;

TYPE
        NodeType=record
        child                   :array['a'..'z']of Longint;
        value,father            :Longint;
        name                    :Char;
        end;

VAR
        part,p,n,m              :Integer;
        availuble               :Integer;
        data                    :array[1..maxn]of NodeType;

        line                    :array[1..maxn]of Integer;

        total                   :array[2..9]of Integer;
        change                  :array[2..9,1..4]of char;

PROCEDURE MakeChange;
var
        i,j                     :Integer;
begin
for i:=2 to 8 do total[i]:=3; total[7]:=4; total[9]:=4;
for i:=2 to 7 do
        for j:=1 to 3 do
                change[i][j]:=char(i * 3 + j - 7 + ord('a'));

change[7][4]:='s';
change[8][1]:='t';
change[8][2]:='u';
change[8][3]:='v';
change[9][1]:='w';
change[9][2]:='x';
change[9][3]:='y';
change[9][4]:='z';
end;

PROCEDURE Add(var s:String; var price:Longint);
var
        i,p                     :Integer;
begin
p:=1;
for I:=1 to length(s) do
        begin
        if data[p].child[s[i]]=0 then
                begin
                inc(availuble);
                data[p].child[s[i]]:=availuble;
                fillchar(data[availuble],sizeof(NodeType),0);
                data[availuble].father:=p;
                data[availuble].name:=s[i];
                end;

        p:=data[p].child[s[i]];
        inc(data[p].value,price);
        end;
end;

PROCEDURE Readin;
var
        i                       :Integer;
        price,code              :Longint;
        s                       :String;
begin
fillchar(data,sizeof(NodeType),0);
availuble:=1;

readln(n);
for i:=1 to n do
        begin
        readln(s);
        val( copy(s,pos(' ',s)+1,length(s)-pos(' ',s)) , price , code);
        delete(s,pos(' ',s),length(s)-pos(' ',s)+1);
        Add(s,price);
        end;
end;

PROCEDURE Print(p:Integer);
begin
if p=1 then exit;
print(data[p].father);
write(data[p].name);
end;

PROCEDURE main;
var
        i,j                     :Integer;
        open,closed,stop        :Integer;
        ch                      :Char;

        Procedure KfsFor(p:Integer);
        var
                i               :Integer;
                max,point,temp  :Longint;
        begin
        stop:=closed;

        max:=-1;
        while open<=stop do
                begin
                for i:=1 to total[p] do
                        begin
                        temp:=data[line[open]].child[change[p][i]];
                        if temp<>0 then
                                begin
                                inc(closed);
                                line[closed]:=temp;

                                if data[temp].value>max then
                                        begin
                                        max:=data[temp].value;
                                        point:=temp;
                                        end;
                                end;
                                // has this point
                        end;

                inc(open);
                end;

        if max<0 then
                write('MANUALLY')
                        else
                print(point);

        writeln;
        end;

begin
readln(m);
for i:=1 to m do
        begin
        open:=1;
        closed:=1;
        line[1]:=1;

        read(ch);
        while (ch<>'1') do
                begin
                KfsFor(ord(ch)-48);
                Read(ch);
                end;
        readln;
        writeln;
        end;
end;


BEGIN
MakeChange;
//assign(input,'p.in');
//reset(input);
//assign(output,'p.out');
//rewrite(output);
readln(part);
for p:=1 to part do
        begin
        writeln('Scenario #',p,':');
        Readin;
        Main;
        writeln;
        //break;
        end;
//close(output);
END.