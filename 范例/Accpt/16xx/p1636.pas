PROGRAM p1636;

VAR
        //f       :text;
        t,q     :integer;
        num     :array[1..500,1..500]of longint;
        sum     :array[0..500,0..500]of longint;
        n,m     :Integer;
        i,j     :Integer;
        total   :longint;
        p       :longint;
        a,b,c,d :Integer;




PROCEDURE first;
var
        i,j     :Integer;
        k       :integer;
        s       :longint;
begin
fillchar(sum,sizeof(sum),0);
for i:=1 to n do
        for j:=1 to m do
                begin
                sum[i,j]:=sum[i-1,j]+num[i,j]+sum[i,j-1]-sum[i-1,j-1];
                end;
end;


BEGIN
//assign(f,'p1636.in');
//reset(f);
readln(t);
for q:=1 to t do
        begin
        readln(n,m);
        writeln('Case ',q,':');
        for i:=1 to n do
                begin
                for j:=1 to m do
                        begin
                        read(num[i,j]);
                        num[i,j]:=sqr(num[i,j]);
                        end;
                readln;
                end;
        first;
        readln(total);
        for p:=1 to total do
                begin
                readln(a,b,c,d);
                writeln(sum[c,d]+sum[a-1,b-1]-sum[a-1,d]-sum[c,b-1]);
                end;
        end;
//close(f);
END.
