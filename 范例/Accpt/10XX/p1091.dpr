program p1091;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        dx      : array[1..8] of Longint = ( 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1 );
        dy      : array[1..8] of Longint = ( 2 , 1 , -1 , -2 , 2 , 1 , -1 , -2 );

var
        x1 , y1 , x2 , y2       : Longint;
        reach   : array[1..8,1..8] of Longint;

procedure search ( x , y , cost : Longint );
var     i       : Longint;
begin
        if ( x < 1 ) or ( x > 8 ) or ( y < 1 ) or ( y > 8 ) then exit;
        if ( reach [x] [y] <> -1 ) and ( cost >= reach [x] [y] ) then exit;
        reach [x] [y] := cost;
        for i := 1 to 8 do search ( x + dx [i] , y + dy [i] , cost + 1 );
end;

procedure Work;
var
        ch      : Char;
begin
        read ( ch ); x1 := ord ( ch ) - ord ( 'a' ) + 1;
        read ( ch ); y1 := ord ( ch ) - ord ( '0' );
        read ( ch );
        read ( ch ); x2 := ord ( ch ) - ord ( 'a' ) + 1;
        readln ( ch ); y2 := ord ( ch ) - ord ( '0' );
        fillchar ( reach , sizeof ( reach ) , $FF );
        search ( x1 , y1 , 0 );
        writeln ( 'To get from ' , chr ( x1 + ord ( 'a' ) - 1 ) , y1 , ' to ' ,
                  chr ( x2 + ord ( 'a' ) - 1 ) , y2 , ' takes ' , reach [x2] [y2] , ' knight moves.' );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while not seekeof do
                Work;
end.
