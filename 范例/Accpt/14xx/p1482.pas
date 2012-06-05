PROGRAM p1482;

VAR
        n,i,avilueble,area                      :Integer;
        stay                                    :array[1..3000]of Boolean;
        next,total,col                          :array[1..3000]of Integer;
        map_1,map_2                             :array[0..3000]of 0..1;

FUNCTION Newup:Integer;
begin
Newup:=avilueble;
total[avilueble]:=1;
stay[avilueble]:=true;
avilueble:=next[avilueble];
end;

PROCEDURE Subtration(c:Integer);
begin
dec(total[c]);
if total[c]=0 then
        begin
        next[c]:=avilueble;
        avilueble:=c;
        stay[c]:=false;
        inc(area);
        end;
end;

PROCEDURE Unite(s:Integer);
var
        i                                       :Integer;
begin
if col[s]=col[s-1] then exit;
inc(total[col[s-1]],total[col[s]]);
total[col[s]]:=0;
next[col[s]]:=avilueble;
avilueble:=col[s];
stay[col[s]]:=false;
for i:=1 to n do
        if (i<>s)and(col[i]=col[s]) then col[i]:=col[s-1];
col[s]:=col[s-1];
end;


PROCEDURE Init;
var
        i                                       :Integer;
begin
for i:=1 to n do
        begin
        stay[i]:=false;
        map_1[i]:=1;
        next[i]:=i+1;
        total[i]:=0;
        col[i]:=0;
        end;
area:=0;
next[i]:=0;
avilueble:=1;
map_1[0]:=1;
end;

PROCEDURE Main;
var
        ch                                      :Char;
        i,j                                     :Integer;
begin
for i:=1 to n+1 do
        begin
        if I<=n then
                begin
                for j:=1 to n do
                        begin
                        read(map_2[j]);
                        if j<n then read(ch);
                        end;
                readln;
                end;

        if i=n+1 then for j:=1 to n do map_2[j]:=1;
        map_2[0]:=1;


        for j:=1 to n do
                begin

                if (map_1[j]=0)and(map_2[j]=1) then
                        begin
                        Subtration(col[j]);
                        col[j]:=0;
                        end;
                                //situation 1


                if (map_1[j]=1)and(map_2[j]=0)and(map_2[j-1]=1) then
                        begin
                        col[j]:=newup;
                        end;
                                //situation 2


                if (map_1[j]=1)and(map_2[j]=0)and(map_2[j-1]=0) then
                        begin
                        col[j]:=col[j-1];
                        inc(total[col[j-1]]);
                        end;
                                //situation 3

                if (map_1[j]=0)and(map_2[j]=0)and(map_2[j-1]=0) then
                        begin
                        unite(j);
                        end;
                                //situation 4

                end;



        map_1:=map_2;
        end;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n);
        Init;
        Main;
        writeln(area);
        end;
END.