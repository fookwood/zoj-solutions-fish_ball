program p2014;

{$APPTYPE CONSOLE}

const
        maxn    = 10000;


type
        Topt    = array[0..maxn] of Longint;

var
        n , part , p    : Longint;
        max             : Longint;
        Sa , Sb         : Longint;
        a , b           : Longint;
        opt             : Topt;

procedure relax ( sc , g : Longint );
var     i               : Longint;
begin
for i := 0 to max - g do if opt [i] <> -1 then
        if ( opt [i + g] = -1 ) or ( opt [i] + sc < opt [i + g] ) then
                opt [i + g] := opt [i] + sc;
end;

begin
readln ( part );
for p := 1 to part do
        begin
        readln ( Sa , Sb );
        if Sb > Sa then max := Sb - Sa else max := 0;
        readln ( n );
        fillchar ( opt , sizeof ( opt ) , $FF ); opt [0] := 0;
        while ( n > 0 ) do
                begin
                readln ( a , b );
                relax ( a , b );
                dec ( n );
                end;
        if ( Sb < Sa ) or ( opt [max] < 0 ) then
                writeln ( 'This is impossible.' )
                        else
                writeln ( 'The minimum amount of money in the piggy-bank is ' , opt [max] , '.' );
        end;
end.
