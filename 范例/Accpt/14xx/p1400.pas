PROGRAM p1400;

TYPE
        arr=array[1..9]of Longint;


VAR
        n                       :Integer;
        step                            :Integer;
        time                    :array[1..100]of arr;
        name                    :array[1..100]of String;
        total                   :array[1..100]of Integer;


PROCEDURE Readin;
var
        i,j                             :Integer;
        sum                             :Longint;
        sum_float                       :Extended;
        ch                              :Char;
begin
for I:=1 to n do
        begin
        name[i]:='';
        read(ch);
        sum:=0;
        sum_float:=0;
        while (Ch<>' ') do
                begin
                name[i]:=name[i]+ch;
                read(ch);
                end;
        total[i]:=0;
        for j:=1 to 7 do
                begin
                read(time[i][j]);
                inc(sum,time[i][j]);
                if time[i][j]<>0 then
                        begin
                        sum_float:=sum_float + ln(time[i][j]);
                        inc(total[i]);
                        end;
                //writeln(time[i][j],' ',ln(time[i][j]):0:3,' ',sum_float);
                end;
        time[i][8]:=sum;
        if total[i]>0 then time[i][9]:=round(exp(sum_float/total[i]))
                else time[i][9]:=0;
        readln;
        end;
end;

PROCEDURE Sort;
var
        i,j                             :Integer;
        temp                            :arr;
        temps                           :String;
        temp_int                        :Integer;
begin
for i:=1 to n-1 do
        for j:=n-1 downto i do
                if (total[j]<total[j+1]) or
                ((total[j]=total[j+1]) and
                        ((time[j][8] > time[j+1][8]) or
                ( (time[j][8]=time[j+1][8])and
                        ((time[j][9]>time[j+1][9]) or
                                ((time[j][9]=time[j+1][9]) and (name[j]>name[j+1])
                                )))
                        ) )then
                begin
                temp:=time[j];
                time[j]:=time[j+1];
                time[j+1]:=temp;
                temps:=name[j];
                name[j]:=name[j+1];
                name[j+1]:=temps;
                temp_int:=total[j];
                total[j]:=total[j+1];
                total[j+1]:=temp_int;
                end;
end;

PROCEDURE Writeout;
var
        i,j,t                           :Integer;
begin
writeln('CONTEST ',step);
for i:=1 to n do
        begin
        if (i=1) or (
        (total[i]<>total[i-1]) or (time[i][8]<>time[i-1][8]) or (time[i][9]<>time[i-1][9]))  then
                begin
                if i<10 then write('0',i,' ',name[i]) else
                        write(i,' ',name[i]);
                t:=i;
                end else
                begin
                if t<10 then write('0',t,' ',name[i]) else
                        write(t,' ',name[i]);
                end;

        for j:=1 to 11-length(name[i]) do write(' ');
        write(total[i],' ',time[i][8]:4,time[i][9]:4);
        for j:=1 to 7 do write(time[i][j]:4);
        writeln;

        end;
end;

BEGIN
assign(output,'p.out');
rewrite(output);
assign(input,'p.in');
reset(input);
readln(n);
step:=0;
while (n<>0) do
        begin
        inc(step);
        Readin;
        Sort;
        WriteOut;
        readln(n);
//        break;
        end;
close(output);
END.
