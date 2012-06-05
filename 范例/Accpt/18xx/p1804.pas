PROGRAM p1804;

VAR
        step                    :Integer;
        n,i,h,w,a,b             :Integer;
        s                       :String;
        num,code                :Integer;
        whether                 :array[0..20,0..20]of Boolean;


PROCEDURE Print;
var
        i,j                             :Integer;
begin
for I:=0 to h do
        begin
        for J:=0 to w do write(ord(whether[i,j]));
        writeln;
        end;
end;

PROCEDURE Changeup;
var
        max,have                  :Integer;
        i,j,many                  :Integer;
begin
max:=0;
for i:=0 to w do
        begin
        many:=0;
        for j:=0 to h do if whether[j,i] then inc(many);
        if (many+num-h-1>max) then max:=many+num-h-1;
        end;
dec(num,max);
for i:=0 to w do
        begin
        have:=0;
        for j:=h downto h-num+1 do
                if whether[j,i] then
                        begin
                        whether[j,i]:=false;
                        inc(have);
                        end;
        j:=h-num;
        while have>0 do
                begin
                if not whether[j,i] then
                        begin
                        whether[j,i]:=true;
                        dec(have);
                        end;
                dec(j);
                end;
        end;
end;

PROCEDURE Changedown;
var
        max,have                        :Integer;
        i,j,many                        :Integer;
begin
max:=0;
for i:=0 to w do
        begin
        many:=0;
        for j:=0 to h do if whether[j,i] then inc(many);
        if many+num-h-1>max then max:=many+num-h-1;
        end;
dec(num,max);
for i:=0 to w do
        begin
        have:=0;
        for j:=0 to num-1 do
                if whether[j,i] then
                        begin
                        whether[j,i]:=false;
                        inc(have);
                        end;
        j:=num;
        while have>0 do
                begin
                if not whether[j,i] then
                        begin
                        whether[j,i]:=true;
                        dec(have);
                        end;
                inc(j);
                end;
        end;
end;

PROCEDURE Changeleft;
var
        i,j                             :Integer;
        many,max,have                   :Integer;
begin
max:=0;
for i:=0 to h do
        begin
        many:=0;
        for j:=0 to w do
                if whether[i,j] then inc(many);
        if many+num-w-1>max then max:=many+num-w-1;
        end;
dec(num,max);
for i:=0 to h do
        begin
        have:=0;
        for j:=w downto w-num+1 do
                if whether[i,j] then
                        begin
                        whether[i,j]:=false;
                        inc(have);
                        end;
        j:=w-num;
        while have>0 do
                begin
                if not whether[i,j] then
                        begin
                        whether[i,j]:=true;
                        dec(have);
                        end;
                dec(j);
                end;
        end;
end;

PROCEDURE Changeright;
var
        i,j,many                        :Integer;
        max,have                        :Integer;
begin
max:=0;
for i:=0 to h do
        begin
        many:=0;
        for j:=0 to w do if whether[i,j] then inc(many);
        if many+num-w-1>max then max:=many+num-w-1;
        end;
dec(num,max);
for i:=0 to h do
        begin
        have:=0;
        for J:=0 to num-1 do
                if whether[i,j] then
                        begin
                        whether[i,j]:=false;
                        inc(have);
                        end;
        j:=num;
        while (have>0) do
                begin
                if not whether[i,j] then
                        begin
                        whether[i,j]:=true;
                        dec(have);
                        end;
                inc(j);
                end;
        end;
end;

PROCEDURE WriteOut;
var
        i,j,tot                                 :Integer;
        ansx,ansy                               :array[1..1000]of Integer;
begin
write('Data set ',step,' ends with boxes at locations ');
tot:=0;
for i:=0 to h do for j:=0 to w do if whether[i,j] then
        begin
        inc(tot);
        ansx[tot]:=i;
        ansy[tot]:=j;
        end;
for i:=1 to tot-1 do write('(',ansx[i],',',ansy[i],') ');
if tot<>0 then write('(',ansx[tot],',',ansy[tot],')');
writeln('.');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(h,w);
step:=0;
while (h<>0)or(w<>0) do
        begin
        inc(step);
        read(n);
        dec(h);dec(w);
        fillchar(whether,sizeof(whether),0);
        for i:=1 to n do
                begin
                read(a,b);
                whether[a,b]:=true;
                end;
        readln;
        readln(s);
        while s<>'done' do
                begin
                if pos('down',s)=1 then
                        begin
                        delete(s,1,pos(' ',s));
                        val(s,num,code);
                        changedown;
                        end else
                if pos('up',s)=1 then
                        begin
                        delete(s,1,pos(' ',s));
                        val(s,num,code);
                        changeup;
                        end else
                if pos('left',s)=1 then
                        begin
                        delete(s,1,pos(' ',s));
                        val(s,num,code);
                        changeleft;
                        end else
                if pos('right',s)=1 then
                        begin
                        delete(s,1,pos(' ',s));
                        val(s,num,code);
                        changeright;
                        end;
                readln(s);
                end;
        WriteOut;
        readln(h,w);
        end;
END.