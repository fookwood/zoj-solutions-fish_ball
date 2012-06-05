PROGRAM p1707;

VAR
        n                       :integer;
        i                       :integer;
        pre,truth               :array[1..10]of string;
        willing                 :string;



PROCEDURE main;
var
        i,j                     :Integer;
begin
for I:=1 to n do
        begin
        while pos(truth[i],willing)<>0 do
                begin
                j:=pos(truth[i],willing);
                delete(willing,j,length(truth[i]));
                insert(pre[i],willing,j);
                end;
        end;
writeln(willing);
end;

BEGIN
readln(n);
while n<>0 do
        begin
        for I:=1 to n do
                begin
                readln(truth[i]);
                readln(pre[i]);
                end;
        readln(willing);
        main;
        readln(n);
        end;
END.