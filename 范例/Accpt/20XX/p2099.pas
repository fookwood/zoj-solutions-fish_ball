PROGRAM p2099;

VAR
        n,i,a,b,maxx,minx,
        maxy,miny                                       :Longint;

BEGIN
readln(a,b);
while (a<>0)or(b<>0) do
        begin
        minx:=maxlongint;
        maxx:=-maxlongint;
        miny:=maxLongint;
        maxy:=-maxlongint;
        while (a<>0)or(b<>0) do
                begin
                if a>maxx then maxx:=a;
                if a<minx then minx:=a;
                if b>maxy then maxy:=b;
                if b<miny then miny:=b;
                readln(a,b);
                end;
        writeln(minx,' ',miny,' ',maxx,' ',maxy);
        readln(a,b);
        end;
END.