PROGRAM p2409;

VAR
        part,p          :Integer;
        card            :array[1..5,1..2] of Integer;
        name            :array[1..5]of String;
        ordering        :array[1..5] of Integer;
        chose           :array[1..5] of Integer;

PROCEDURE Readin;
var
        i               :Integer;
        s               :String;
begin

readln(s);
for i:=1 to 5 do
        begin
        ordering[i]:=i;
        if pos(' ',s)=0 then name[i]:=s
                else
                begin
                name[i]:=copy(s,1,pos(' ',s)-1);
                delete(s,1,pos(' ',s));
                end;

        case name[i][length(name[i])] of
                'C'             :card[i][2]:=1;
                'D'             :card[i][2]:=2;
                'H'             :card[i][2]:=3;
                'S'             :card[i][2]:=4;
        end;

        if length(name[i])=3 then
                begin
                card[i][1]:=10;
                end else
                begin
                if (name[i][1]>='2') and (name[i][1]<='9') then
                        card[i][1]:=ord(name[i][1])-48
                                else
                        case name[i][1] of
                                'A'             :card[i][1]:=1;
                                'J'             :card[i][1]:=11;
                                'Q'             :Card[i][1]:=12;
                                'K'             :card[i][1]:=13;
                        end;

                end;
        end;
end;

FUNCTION Compare(a,b:Integer):Integer;
begin
compare:=-1;
if (card[a][1]<card[b][1]) then exit;
compare:=1;
if (card[a][1]>card[b][1]) then exit;
if (card[a][2]<card[b][2]) then compare:=-1 else
if (card[a][2]=card[b][2]) then compare:=0;
end;

PROCEDURE Sort;
var
        i,j                     :Integer;
        temp                    :Integer;
begin
for i:=1 to 4 do
        for j:=i+1 to 5 do
                if compare(ordering[i],ordering[j])>0 then
                        begin
                        temp:=ordering[i];
                        ordering[i]:=ordering[j];
                        ordering[j]:=temp;
                        end;
end;

FUNCTION Check:Boolean;
var
        num                     :Integer;
        j,k                     :Integer;
        noww                    :array[1..2]of Integer;
begin
num:=card[ordering[chose[2]]][1];

k:=3;
for j:=4 to 5 do
        if compare(ordering[chose[j]],ordering[chose[k]])<0 then k:=j;

inc(num,k-2);
if num>13 then num:=num-13;

j:=0;
if (k<>3) then begin inc(j);noww[j]:=3; end;
if (k<>4) then begin inc(j);noww[j]:=4; end;
if (k<>5) then begin inc(j);noww[j]:=5; end;

if compare(ordering[chose[noww[1]]],ordering[chose[noww[2]]])>=0 then num:=num+3;
if num>13 then num:=num-13;
if num=card[ordering[chose[1]]][1] then check:=true else check:=false;
end;

PROCEDURE print;
var
        i                       :Integer;
begin
write('Problem ',p,':');
for i:=1 to 5 do
        write(' ',name[ordering[chose[i]]]);
writeln;
end;

PROCEDURE Main;
var
        i,j,k,p,q                       :Integer;
begin
for i:=1 to 5 do
        for j:=1 to 5 do
                if (i<>j) and (card[ordering[i]][2]=card[ordering[j]][2]) then
                for k:=1 to 5 do
                if (i<>k)and(j<>k) then
                for p:=1 to 5 do
                if (i<>p)and(j<>p)and(k<>p) then
                        begin
                        q:=1+2+3+4+5-i-j-k-p;
                        chose[1]:=i;
                        chose[2]:=j;
                        chose[3]:=k;
                        chose[4]:=p;
                        chose[5]:=q;
                        if check then
                                begin
                                print;
                                exit;
                                end;
                        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        Sort;
        Main;
        end;
END.
