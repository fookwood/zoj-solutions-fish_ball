PROGRAM p2312;

CONST
        MAX_    =       50;

        Change  :       array[0..3,1..2]of Integer=
        ((-1,0),(0,1),(1,0),(0,-1));

        MAPCONST:       array ['A'..'K',0..3]of Byte=
        ((1,0,0,1),(1,1,0,0),(0,0,1,1),(0,1,1,0),
        (1,0,1,0),(0,1,0,1),(1,1,0,1),(1,0,1,1),
        (0,1,1,1),(1,1,1,0),(1,1,1,1));

TYPE
        MAPTYPE =       'A'..'K';

VAR
        t                       :Integer;
        n,m                     :Integer;
        cover                   :array[1..MAX_,1..MAX_]of Boolean;
        map                     :array[1..MAX_,1..MAX_]of MAPTYPE;

PROCEDURE Readin;
var
        i,j                     :Integer;
begin
readln(n,m);
if (n=-1)and(m=-1) then halt;
for i:=1 to n do
        begin
        for j:=1 to m do read(map[i][j]);
        readln;
        end;
end;

PROCEDURE Search(x,y:Integer);
var
        i,p,q                   :Integer;

        Function Check(face:Integer):Boolean;
        begin
        Check:=false;
        p:=x+change[i][1];
        q:=y+change[i][2];

        if (p<1) or (q<1) or (p>n) or (q>m) or cover[p][q] then exit;

        if cover[p][q] then exit;

        case i of
                0               :
                        if mapconst[map[p][q]][2]=0 then exit;
                1               :
                        if mapconst[map[p][q]][3]=0 then exit;
                2               :
                        if mapconst[map[p][q]][0]=0 then exit;
                3               :
                        if mapconst[map[p][q]][1]=0 then exit;
        end;

        Check:=true;
        end;
begin

cover[x][y]:=true;

for i:=0 to 3 do
        if (mapconst[map[x][y]][i]=1) and check(i) then
                begin
                Search(p,q);
                end;
end;

PROCEDURE Main;
var
        i,j                     :Integer;

begin
fillchar(cover,sizeof(cover),0);
T:=0;

for i:=1 to n do
        for j:=1 to m do
                if not cover[i][j] then
                        begin
                        inc(T);
                        Search(i,j);
                        end;

writeln(T);

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
