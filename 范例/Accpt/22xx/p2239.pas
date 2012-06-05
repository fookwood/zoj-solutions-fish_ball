PROGRAM p2239;

VAR
        n                       :Int64;
        s                       :Extended;

FUNCTION Ans(s,t,step:Extended;which:Integer):Extended;
var
        have                    :Extended;
begin
if s=t then Ans:=s else
        begin
        have:=(t-s) / step +1 ;
        if which=1 then
                begin
                if not (frac(have/2)=0) then
                        Ans:=Ans(s+step,t-step,step*2,2) else
                        Ans:=Ans(s+step,t,step*2,1);
                end else
                begin
                if not (frac(have/2)=0) then
                        Ans:=Ans(s,t,step*2,1) else
                        Ans:=Ans(s,t-step,step*2,2);
                end;
        end;
end;

BEGIN
readln(s);
while (s<>0) do
        begin
        writeln(ans(1,s,1,2):0:0);
        readln(s);
        end;
END.
