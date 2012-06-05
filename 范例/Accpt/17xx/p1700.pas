PROGRAM p1700;

VAR
        finish                  :Boolean;
        total,i,tree            :Integer;
        availue                 :Integer;
        leftsub,rightsub,next
                                :array[1..90]of Integer;
        number                  :array[1..90]of Char;
        fallen                  :array[1..26]of String;


PROCEDURE Readin;
var
        i                       :Integer;
begin
total:=1;
readln(fallen[total]);
while (fallen[total]<>'*')and(fallen[total]<>'$') do
        begin
        inc(total);
        readln(fallen[total]);
        end;
if fallen[total]='$' then finish:=true;
dec(total);
end;

PROCEDURE Search(p:Integer;left,right:Char);
var
        t                               :Integer;
        i,j                             :Integer;
begin
//write(left:10,right:5);
for i:=total downto 1 do
        for j:=1 to length(fallen[i]) do
                if (fallen[i][j]>=left)and(fallen[i][j]<=right) then
                        begin
                        //write(fallen[i][j]);
                        number[p]:=fallen[i][j];
                        leftsub[p]:=availue;
                        availue:=next[availue];
                        rightsub[p]:=availue;
                        availue:=next[availue];
                        number[leftsub[p]]:=' ';
                        number[rightsub[p]]:=' ';
                        leftsub[leftsub[p]]:=0;
                        rightsub[leftsub[p]]:=0;
                        leftsub[rightsub[p]]:=0;
                        rightsub[rightsub[p]]:=0;
                        Search(leftsub[p],left,pred(fallen[i][j]));
                        Search(rightsub[p],succ(fallen[i][j]),right);
                        exit;
                        end;
end;

PROCEDURE Print(p:Integer);
var
        l,r                     :Integer;
begin
l:=leftsub[p];
r:=rightsub[p];
if number[p] <>' ' then write(number[p]);
next[p]:=availue;
availue:=p;
if l<>0 then print(l);
if r<>0 then print(r);
end;


BEGIN
{assign(input,'p.in');
reset(input);
assign(output,'p.out');
rewrite(output);}
finish:=false;
for i:=1 to 89 do next[i]:=i+1;
availue:=1;
while not finish do
        begin
        Readin;
        tree:=availue;
        availue:=next[availue];
        leftsub[tree]:=0;
        rightsub[tree]:=0;
        number[tree]:=' ';
        Search(tree,'A','Z');
        Print(tree);
        writeln;
        end;
{close(output); }

END.
