PROGRAM p1802;

VAR
        n,i,part                        :Integer;
        x,y                             :array[1..12]of Extended;
        whether,cover                   :array[1..12,1..12]of Boolean;
        down,le                         :array[1..12]of Integer;


FUNCTION Dis(a,b:Integer):Extended;
begin
dis:=sqrt(sqr(x[a]-x[b]) + sqr(y[a]-y[b]));
end;

PROCEDURE Main;
var
        i,j,col,k,max                  :Integer;
begin
fillchar(whether,sizeof(whether),0);
fillchar(down,sizeof(down),0);
fillchar(cover,sizeof(cover),0);
fillchar(le,sizeof(le),0);

for i:=1 to n do
        for j:=i+1 to n do
                if (dis(i,j)<20+1e-10) then
                        begin
                        whether[i][j]:=true;
                        whether[j][i]:=true;
                        end;

// make whether

col:=0;
for i:=1 to n do
        begin
        max:=-maxint;
        for j:=1 to n do
                if (le[j]=0) and (down[j]>max) then
                        begin
                        max:=down[j];
                        k:=j;
                        end;

        for j:=1 to n do if not cover[k][j] then break;
        le[k]:=j;
        if le[k]>col then col:=le[k];

        for j:=1 to n do
                if whether[k][j] and not cover[j][le[k]] then
                        begin
                        cover[j][le[k]]:=true;
                        inc(down[j]);
                        end;


        end;

writeln('The towers in case ',part,' can be covered in ',col,' frequencies.');

end;


BEGIN
//assign(input,'p.in');
//reset(input);

part:=0;
readln(n);
while (n<>0) do
        begin
        inc(part);
        for i:=1 to n do read(x[i],y[i]);
        readln;
        Main;
        readln(n);
        end;
END.