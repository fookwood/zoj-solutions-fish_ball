//Accept at time : 2005/06/06 1 : 29
PROGRAM p1408;

const
        maxn    = 64;

type
        Tsam    = array[1..maxn ] of Char;
        Tans    = array[1..maxn ] of Longint;

VAR
        part , p , n , i                : Longint;
        D                               : Int64;
        sam                             : Tsam;
        ans                             : Tans;

BEGIN
{assign ( input , 'p.in' );
reset ( input );}

readln ( part );
for p := 1 to part do
        begin
        readln ( n );
        for i := 1 to n do read ( sam [i] ); readln;
        readln ( D );

        for i := n downto 1 do
                if odd ( D ) then
                        begin
                        if D > 0 then
                                begin
                                case sam [i] of
                                        'p'     : D := D div 2;
                                        'n'     : D := D div 2 + 1;
                                end ;
                                end else
                                begin
                                case sam [i] of
                                        'p'     : D := D div 2 - 1;
                                        'n'     : D := D div 2;
                                end ;
                                end;
                        ans [i] := 1;
                        end else
                        begin
                        ans [i] := 0;
                        D := D div 2;
                        end;
        if D = 0 then
                for i := 1 to n do write ( ans [i] )
                else write ( 'Impossible' );
        writeln;
        end;
END.