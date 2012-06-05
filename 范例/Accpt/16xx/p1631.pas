PROGRAM p1631;

TYPE
	information=record
	hp,armor,cool,amount,power,now			:Longint;
	name							:String;
	end;

VAR
	king1,king2						:Information;
        s1,s2                                                   :Longint;

PROCEDURE Main;
var
        atack1,atack2                                           :Longint;
        time1,time2                                             :Longint;
begin
atack1:=(king2.power-king1.armor);
if atack1<1 then atack1:=1;
atack2:=(king1.power-king2.armor);
if atack2<1 then atack2:=1;

atack1:=atack1 * king2.amount;
atack2:=atack2 * king1.amount;

time1:=king1.hp div atack1;
if king1.hp mod atack1<>0 then inc(time1);
time1:=time1*king2.cool;
time2:=king2.hp div atack2;
if king2.hp mod atack1<>0 then inc(time2);
time2:=time2*king1.cool;

if time1<time2 then
        writeln(king2.name,' Survive!') else
if time1>time2 then
        writeln(king1.name,' Survive!') else
        writeln('All Die!');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
begin
with king1 do
begin
readln(name);
readln(hp,armor,cool,amount,power);
s1:=hp;
now:=cool;
end;
with king2 do
begin
readln(name);
readln(hp,armor,cool,amount,power);
now:=cool;
s2:=hp;
end;
Main;
if not eof then readln;
end;
END.
