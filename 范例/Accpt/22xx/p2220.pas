PROGRAM p2220;

TYPE
        Position=record
                x,y                     :Integer;
        end;

VAR
        stand                                   :array[0..40,0..40]of Boolean;
        part,p                                  :Integer;
        h,w,i                                   :Integer;
        wind                                    :array[1..50]of Position;


PROCEDURE Main;
var
        i,j,k                                   :Integer;
        long,a,b                                :Real;

begin
for i:=0 to h do
        for j:=0 to h do
                if stand[i,j] then
                begin
                long:=0;
                for k:=1 to w do
                        if Sqrt(sqr(wind[k].x-i)+sqr(wind[k].y-j))>long then
                        long:=Sqrt(sqr(wind[k].x-i)+sqr(wind[k].y-j));
                a:=i;b:=j;
                if (long<=a)and(long<=b)and(long<=h-a)and(long<=h-b) then
                        begin
                        writeln(i,' ',j);
                        exit;
                        end;
                end;
writeln('poodle');
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(h,w);
        fillchar(stand,sizeof(stand),1);
        for i:=1 to w do
                begin
                readln(wind[i].x,wind[i].y);
                stand[wind[i].x,wind[i].y]:=false;
                end;
        Main;
        end;
END.