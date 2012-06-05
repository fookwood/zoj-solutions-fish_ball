program p1095;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        Tnum    = array[0..5842] of Longint;
        Tpos    = array[1..4] of Longint;

const
        pred    : Tpos = ( 2 , 3 , 5 , 7 );

var
        pos     : Tpos;
        num     : Tnum;

procedure MakeNum;
var     i , j   : Longint;
        min     : Longint;
begin
        fillchar ( pos , sizeof ( pos ) , 0 );
        num [0] := 1;
        for i := 1 to 5841 do
                begin
                min := 2000000001;
                for j := 1 to 4 do
                        begin
                        while ( pred [j] * num [pos [j]] <= num [i - 1] ) do inc ( pos [j] );
                        if pred [j] * num [pos [j]] < min then min := pred [j] * num [pos [j]];
                        end;
                num [i] := min;
                end;
end;

procedure work;
var     n       : Longint;
begin
        while true do
                begin
                readln ( n ); if n = 0 then break;
                write ( 'The ' );
                if n div 10 mod 10 = 1 then
                        write ( n , 'th' )
                                else
                        case n mod 10 of
                        1       : write ( n , 'st' );
                        2       : write ( n , 'nd' );
                        3       : write ( n , 'rd' );
                        else    write ( n , 'th' );
                        end;
                writeln ( ' humble number is ' , num [n - 1] , '.' );
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        
        MakeNum;
        work;
end.
