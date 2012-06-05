program p1011;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        Power2  : array[0..14] of Longint =
                (1, 2, 4, 8, 16,
                32, 64, 128, 256, 512,
                1024, 2048, 4096, 8192, 16384 );

type
        Node    = record
                Left , Right    : Longint;
                Next            : Longint;
                end;

var
        part            : Longint;

        n , m , k       : Longint;
        Reach           : Longint;
        Table           : array[0..14 , 0..10] of Longint;
        Line            : array[1..500] of Node;

        L       : Longint;
        Tot     : Longint;
        Map     : array[0..1 shl 11 - 1] of Longint;

        Aval    : Longint;

procedure init;
var     i , j   : Longint;
begin
        Reach := 0;
        fillchar ( Table , sizeof ( Table ) , 0 );
        for i := 0 to n - 1 do
                for j := 0 to k - 1 do
                        begin
                        while not seekeoln do
                                begin
                                inc ( Reach );
                                read ( Line [Reach].Left , Line [Reach].Right );
                                Line [Reach].Left := power2 [Line [Reach].Left];
                                Line [Reach].Right := power2 [Line [Reach].Right];
                                
                                Line [Reach].Next := Table [i] [j];
                                Table [i] [j] := Reach;
                                end;
                        readln;
                        end;
       Aval := 0;
       for i := n - m to n - 1 do Aval := Aval or Power2 [i];
end;

procedure Work;
var     t       : Longint;
        i , j   : Longint;
        ch      : Char;
begin
        t := 0;
        for i := 0 to L do
                begin
                for j := 1 to 1 shl i do
                        begin
                        inc ( t );
                        if j > 1 then read ( ch );
                        read ( ch );
                        if ch = '*' then map [t] := k
                                else
                                begin
                                map [t] := ord ( ch ) - ord ( 'a' );
                                if ( map [t] < 0 ) or ( map [t] >= k ) then
                                        while true do; 
                                end; 
                        end;
                readln;
                end;
        Tot := 1 shl ( L + 1 ) - 1;
end;

function Ret ( s : Longint ) : Longint;
var     i       : Longint;
        j       : Longint;
        L , R   : Longint;
        Final   : Longint;
begin
        if ( s > Tot ) or ( map [s] = k ) then
                begin
                Ret := Aval;
                exit;
                end;

        Final := 0;
        L := Ret ( s shl 1 );
        R := Ret ( s shl 1 + 1 );

        for i := 0 to n - 1 do
                begin
                j := Table [i] [map [s]];
                while ( j <> 0 ) do
                        begin
                        if ( Line [j].Left and L > 0 ) and ( Line [j].Right and R > 0 ) then
                                begin
                                Final := Final or power2 [i];
                                break;
                                end;
                        j := Line [j].Next;
                        end;
                end;
        Ret := Final;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        part := 0;
        while true do
                begin
                readln ( n , m , k );
                if ( n = 0 ) and ( m = 0 ) and ( k = 0 ) then break;

                inc ( part );
                if part > 1 then writeln;
                writeln ( 'NTA' , part , ':' );

                init;
                while true do
                        begin
                        readln ( L );
                        if L = -1 then break;
                        Work;
                        if Ret ( 1 ) and 1 > 0
                                then writeln ( 'Valid' )
                                else writeln ( 'Invalid' );
                        end;
                end;
end.
