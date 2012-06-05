PROGRAM P1025;

TYPE
        node=record
                a,b                     :Integer;
        end;

VAR
        n,part,p,i                      :Integer;
        data                            :array[1..5000]of Node;

PROCEDURE Sort;
var
        i,j,c                           :Integer;
        temp                            :Node;
begin
for I:=1 to n-1 do
        begin
        c:=i;
        for j:=i+1 to n do
                if data[c].a<data[j].a then c:=j else
                if (data[c].a=data[j].a)and(data[c].b<data[j].b) then c:=j;
        if c<>i then
                begin
                temp:=data[i];
                data[i]:=data[c];
                data[c]:=temp;
                end;
        end;
end;

PROCEDURE Main;
var
        i,j,ans,nowa,nowb                       :Integer;
        whether                                 :array[1..5000]of Boolean;
begin
fillchar(whether,sizeof(whether),0);
ans:=0;
for I:=1 to n do
        if not whether[i] then
                begin
                inc(ans);
                nowa:=data[i].a;nowb:=data[i].b;
                for j:=i+1 to n do
                        if (not whether[j])and(data[j].a<=nowa)and(data[j].b<=nowb) then
                                begin
                                whether[j]:=true;
                                nowa:=data[j].a;
                                nowb:=data[j].b;
                                end;
                end;
writeln(ans);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for P:=1 to part do
        begin
        readln(n);
        for I:=1 to n do read(data[i].a,data[i].b);
        Sort;
        Main;
        end;
END.