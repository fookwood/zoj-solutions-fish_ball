{$R-,I-,Q-}
PROGRAM p2150;

VAR
        part , p                        : Longint;
        lev , n , i , a , b             : Longint;
        ans , temp                      : Longint;

BEGIN
//assign(input,'p.in');
//reset ( Input );
readln ( part );

for p := 1 to part do
        begin
        ans := 0;
        readln ( lev );
        readln ( n );
        for i:= 1 to n do
                begin
                readln ( a , b );
                a := a mod lev;
                temp := 1;
                while ( b > 0 ) do
                        begin
                        if odd ( b ) then temp := temp * a mod lev;
                        b := b div 2;
                        a := a * a mod lev;
                        end;

                ans := ( ans + temp ) mod lev;
                end;
        writeln ( ans );
        end;
END.
