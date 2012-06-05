PROGRAM p2311;

TYPE
        Node=record
        Inglish                                 :String;
        num                                     :Longint;
        end;

VAR
        i                                       :Integer;
        negative                                :Boolean;
        order                                   :array[1..4]of Node;
        dic                                     :array[1..28]of Node;
        s                                       :String;

PROCEDURE Makedic;
begin
with dic[1]  do begin Inglish:='zero';  num:=0; end;
with dic[2]  do begin Inglish:='one';   num:=1; end;
with dic[3]  do begin Inglish:='two';           num:=2; end;
with dic[4]  do begin Inglish:='three';         num:=3; end;
with dic[5]  do begin Inglish:='four';          num:=4; end;
with dic[6]  do begin Inglish:='five';          num:=5; end;
with dic[7]  do begin Inglish:='six';           num:=6; end;
with dic[8]  do begin Inglish:='seven';         num:=7; end;
with dic[9]  do begin Inglish:='eight';         num:=8; end;
with dic[10] do begin Inglish:='nine';          num:=9; end;
with dic[11] do begin Inglish:='ten';           num:=10; end;
with dic[12] do begin Inglish:='eleven';        num:=11; end;
with dic[13] do begin Inglish:='twelve';        num:=12; end;
with dic[14] do begin Inglish:='thirteen';      num:=13; end;
with dic[15] do begin Inglish:='fourteen';      num:=14; end;
with dic[16] do begin Inglish:='fifteen';       num:=15; end;
with dic[17] do begin Inglish:='sixteen';       num:=16; end;
with dic[18] do begin Inglish:='seventeen';     num:=17; end;
with dic[19] do begin Inglish:='eighteen';      num:=18; end;
with dic[20] do begin Inglish:='nineteen';      num:=19; end;
with dic[21] do begin Inglish:='twenty';        num:=20; end;
with dic[22] do begin Inglish:='thirty';        num:=30; end;
with dic[23] do begin Inglish:='forty';         num:=40; end;
with dic[24] do begin Inglish:='fifty';         num:=50; end;
with dic[25] do begin Inglish:='sixty';         num:=60; end;
with dic[26] do begin Inglish:='seventy';       num:=70; end;
with dic[27] do begin Inglish:='eighty';        num:=80; end;
with dic[28] do begin Inglish:='ninety';        num:=90; end;
with order[1] do begin Inglish:='negative';     num:=-1; end;
with order[2] do begin Inglish:='hundred';      num:=100; end;
with order[3] do begin Inglish:='thousand';    num:=1000; end;
with order[4] do begin Inglish:='million';      num:=1000000; end;
end;

FUNCTION Change(s:String):Longint;
var
        flag                                            :Boolean;
        make                                            :String;
        i                                               :Integer;
        ans,temp                                        :Longint;
begin
ans:=0;
temp:=0;
while length(s)>0 do
        begin
        if pos(' ',s)>0 then
                begin
                make:=copy(s,1,pos(' ',s)-1);
                delete(s,1,pos(' ',s));
                end else
                begin
                make:=s;
                s:='';
                end;
        flag:=false;
        for i:=1 to 4 do
                if order[i].Inglish=make then
                        begin
                        flag:=true;
                        break;
                        end;
        if flag then
                begin
                if i=1 then negative:=true else
                        begin
                        temp:=temp * order[i].num;
                        ans:=ans + temp;
                        temp:=0;
                        end;
                end else
                begin
                for i:=1 to 28 do
                        if dic[i].Inglish=make then
                                begin
                                flag:=true;
                                break;
                                end;
                if not flag then while true do;
                temp:=temp + dic[i].num;
                end;
        end;
ans:=ans+temp;
change:=ans;
end;

FUNCTION first(s:String):Longint;
var
        temp                                            :Longint;
        i                                               :Integer;
begin
temp:=0;
if pos(order[4].Inglish,s)>0 then
        begin
        i:=pos(order[4].Inglish,s);
        temp:=temp+first(copy(s,1,i-1))*order[4].num;
        delete(s,1,i+length(order[4].inglish));
        temp:=temp+first(s);
        first:=temp;
        exit;
        end;
if pos(order[3].Inglish,s)>0 then
        begin
        i:=pos(order[3].Inglish,s);
        temp:=temp+Change(copy(s,1,i-1))*order[3].num;
        delete(s,1,i+length(order[3].Inglish));
        temp:=temp+ Change(s);
        first:=temp;
        exit;
        end;
first:=change(s);
end;

PROCEDURE Main;
var
        answer                                          :Longint;
        i,j                                             :Integer;
begin
negative:=false;
answer:=first(s);
if negative then answer:=-answer;
writeln(answer);
end;

BEGIN
MakeDic;
while not eof do
        begin
        readln(s);
        i:=2;
        while (i<=length(s)) do
                if (s[i]=' ')and(s[i-1]=' ') then  delete(s,i,1) else inc(i);
        if s='' then break;
        Main;
        end;
END.
