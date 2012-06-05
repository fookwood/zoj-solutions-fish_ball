PROGRAM p1107;

TYPE
        Node=record
                x,y,get         :Longint;
        end;

CONST
        change                  :array[1..4,1..2]of Integer=
        ((1,0),(0,1),(0,-1),(-1,0));

VAR
        n,k,i,j,nn              :Integer;
        data                    :array[1..10000]of Node;
        map,maxget              :array[1..100,1..100]of Longint;

PROCEDURE Sort;
var
        i,j,c                   :Integer;
        temp                    :Node;
begin
for i:=1 to nn-1 do
        begin
        c:=i;
        for j:=i+1 to nn do if data[c].get>data[j].get then c:=j;
        if i<>c then
                begin
                temp:=data[i];
                data[i]:=data[c];
                data[c]:=temp;
                end;
        end;
end;

PROCEDURE Main;
var
        ans                             :Longint;
        i,j,p,q,t                       :Integer;
begin
fillchar(maxget,sizeof(maxget),0);
ans:=0;
maxget[1,1]:=map[1,1];
for i:=1 to nn do
        if maxget[data[i].x,data[i].y]>0 then
        begin
        for j:=1 to 4 do
                 begin
                 for t:=1 to k do
                        begin
                        p:=data[i].x+change[j,1]*t;
                        q:=data[i].y+change[j,2]*t;
                        if (p<1)or(q<1)or(p>n)or(q>n) then break;
                        if (map[p,q]>map[data[i].x,data[i].y])and(maxget[data[i].x,data[i].y]+map[p,q]>maxget[p,q]) then
                                maxget[p,q]:=map[p,q]+maxget[data[i].x,data[i].y];
                        end;
                 end;
        if maxget[data[i].x,data[i].y]>ans then ans:=maxget[data[i].x,data[i].y];
        end;

writeln(ans);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(n,k);
while (n<>-1) do
        begin
        for i:=1 to n do
                begin
                for j:=1 to n do
                        begin
                        read(data[(i-1)*n+j].get);
                        map[i,j]:=data[(i-1)*n+j].get;
                        with data[(i-1)*n+j] do
                                begin
                                x:=i;y:=j;
                                end;
                        end;
                readln;
                end;
        nn:=sqr(n);
        Sort;
        Main;
        readln(n,k);
        end;
END.
