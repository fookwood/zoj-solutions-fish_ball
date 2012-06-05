PROGRAM p1256;

CONST
        total           :array[1..12]of Integer=
        (31,28,31,30,31,30,31,31,30,31,30,31);
        monthset        :array[1..12]of String=
        ('January','February','March','April','May','June','July',
        'August','September','October','November','December');

        WeekSet         :array[0..6]of String=
        ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');


VAR
        year,month,day                          :Integer;
        ans                                     :Integer;

FUNCTION Check(y:Integer):Boolean;
begin
if y mod 100=0 then
        begin
        if y mod 400=0 then check:=true else check:=false;
        end else
        begin
        if y mod 4=0 then check:=true else check:=false;
        end;
end;

PROCEDURE Error;
begin
writeln(month,'/',day,'/',year,' is an invalid date.');
end;

PROCEDURE Main;
var
        i                                       :Integer;
begin
if not check(year)  then
        begin
        if (month<1)or(month>12)or(day<1)or(day>total[month]) then
                begin
                error;
                exit;
                end;
        end else
        begin
        if ((month<1)or(month>12)or(day<1)or(day>total[month]))and(month<>2) then
                begin
                error;
                exit;
                end;
        if (month=2)and(day>29) then
                begin
                error;
                exit;
                end;
        end;


if (year=1752)and(month=9)and(day=7) then
        begin
        error;
        exit;
        end;


ans:=0;
if (year<1752)or((year=1752)and((month<9)or((month=9)and(day<3)) )) then ans:=-3;
for i:=1700 to year-1 do
        if check(i) then
                ans:=(ans+366) mod 7
                        else
                ans:=(ans+365) mod 7;
for i:=1 to month-1 do
        begin
        if (i=2) and (check(year)) then inc(ans);
        ans:=(ans+total[i]) mod 7;
        end;
ans:=(ans+day) mod 7;

writeln(monthset[month],' ',day,', ',year,' is a ',WeekSet[(ans+4) mod 7]);
end;

BEGIN
assign(input,'p.in');
reset(input);
readln(month,day,year);
while (month<>0) do
        begin
        Main;
        readln(month,day,year);
        end;
END.