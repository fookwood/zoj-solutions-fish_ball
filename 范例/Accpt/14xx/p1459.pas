// This is a Dp Program
// It just like CLS
// time                 :2005/04/12


PROGRAM p1459;

CONST
        MAX_N   = 80;

        Insert_         = 0;
        Delete_         = 1;
        Replace_        = 2;
        Otherwise_      = 3;

TYPE
        Node=record
        minway          :Integer;
                        // The miniral way need to get to this point

        from_a,from_b   :Integer;
                        // The point before this one

        perform         :Integer;
                        // What will do with this point

        end;


VAR
        n               :Integer;
        step            :Integer;
        len_m,len_g     :Integer;
        mstr,gstr       :String;
        F               :array[1..MAX_N+1,1..MAX_N+1]of Node;

// Just for input

PROCEDURE Readin;
begin
readln(mstr);
readln(gstr);
end;


// prepare for Dp
PROCEDURE Init;
var
        i,j            :Integer;
begin
len_m:=length(mstr);
len_g:=length(gstr);
for i:=1 to len_m do
        for j:=1 to len_g do
                F[i][j] . minway:=maxint;

F[len_m+1][len_g+1] . minway :=0;

for i:=len_m downto 1 do
        with F[i][len_g+1] do
                begin
                minway:=len_m - i + 1;
                from_a:=i+1;
                from_b:=len_g+1;
                perform:=Delete_;
                end;

for j:=len_g downto 1 do
        with F[len_m+1][j] do
                begin
                minway:=len_g - j + 1;
                from_a:=len_m+1;
                from_b:=j+1;
                perform:=Insert_;
                end;
end;


// It is for output
PROCEDURE Print(a,b:Integer);
begin
if F[a][b].minway=0 then exit;

case F[a][b].perform of
        Insert_                 :begin
                                print(a,b+1);
                                inc(step);
                                writeln(step,' Insert ',a,',',gstr[b]);
                                end;
        Delete_                 :begin
                                print(a+1,b);
                                inc(step);
                                writeln(step,' Delete ',a);
                                end;
        Replace_                :begin
                                print(a+1,b+1);
                                inc(step);
                                writeln(step,' Replace ',a,',',gstr[b]);
                                end;
        otherwise_              :begin
                                print(a+1,b+1);
                                end;
end;

end;

// Dp program
PROCEDURE Dp;
var
        i,j                     :Integer;
begin
for i:=len_m downto 1 do
        for j:=len_g downto 1 do
                with F[i][j] do
                        begin
                        if (mstr[i]=gstr[j]) and (F[i+1][j+1]. minway<minway) then
                                begin
                                minway:=F[i+1][j+1].minway;
                                perform:=otherwise_;
                                end;

                        if (F[i+1][j]. minway + 1 < minway) then
                                begin
                                minway:=F[i+1][j].minway + 1;
                                perform:=Delete_;
                                end;

                        if (F[i][j+1]. minway + 1 < minway) then
                                begin
                                minway:=F[i][j+1]. minway + 1;
                                perform:=Insert_;
                                end;

                        if (F[i+1][j+1].minway + 1 <minway) then
                                begin
                                minway:=F[i+1][j+1]. minway + 1;
                                perform:=Replace_;
                                end;

                        end;

step:=0;

writeln(F[1][1].minway);
Print(1,1);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Init;
        Dp;
        end;
END.