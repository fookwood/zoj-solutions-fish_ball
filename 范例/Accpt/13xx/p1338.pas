PROGRAM p1338;

VAR
        total                           :Integer;
        num                             :array[1..40]of Integer;

PROCEDURE Readin;
begin
total:=0;
while true do
        begin
        inc(total);
        read(num[total]);
        if num[total]=0 then break;
        end;

if total=1 then halt;
readln;
end;

PROCEDURE Main;
var
        up,down,num_up,num_down         :Integer;
        reach,i                         :Integer;
        ans_up,ans_down                 :Extended;

        Procedure add;
        var
                i,state                 :Integer;
        begin
        state:=0;
        i:=reach;

        if (reach>1) then
                begin
                dec(reach);
                if num[i]>num[i-1] then state:=1 else
                if num[i]<num[i-1] then
                        else state:=-1;
                end;

        if (state=0) then
                begin
                if i=1 then inc(i);
                while (i<total)and(num[i]=num[i-1]) do inc(i);
                if (i<total) and (num[i]<>num[i-1]) then
                        begin
                        if num[i]>num[i-1] then state:=1
                                else state:=-1;
                        end;
                end;

        if state=1 then
                begin
                while (i<total)and(num[i]>=num[i-1]) do inc(i);
                if true or (num[i]<num[i-1]) then
                        begin
                        inc(num_up);
                        inc(up,i-reach-1);
                        end;
                end else
        if state=-1 then
                begin
                while (i<total)and(num[i]<=num[i-1]) do inc(i);
                if true or (num[i]>num[i-1]) then
                        begin
                        inc(num_down);
                        inc(down,i-reach-1);
                        end;
                end;
        reach:=i;
        end;

begin
up:=0;
down:=0;
num_up:=0;
num_down:=0;
reach:=1;

//writeln('here are the number:');
//for i:=1 to total-1 do write(num[i],' '); writeln;

while reach<total do add;

if num_up=0 then ans_up:=0
        else ans_up:=up/num_up;
if num_down=0 then ans_down:=0
        else ans_down:=down/num_down;

writeln('Nr values = ',total-1,':  ',ans_up:0:6,' ',ans_down:0:6);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
        begin
        Readin;
        Main;
        end;
END.
