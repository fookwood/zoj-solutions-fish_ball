program p1148;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        dx      : array[0..3] of Longint
                = ( -1 , 0 , 1 , 0 );
        dy      : array[0..3] of Longint
                = ( 0 , 1 , 0 , -1 );

var
        part    : Longint;
        n , m   : Longint;
        map     : array [0..80 , 0..80] of Boolean;
        mincost : array [0..80 , 0..80 , 0..3] of Longint;
        line    : array [1..20000 , 0..2] of Longint;

procedure init;
var     i       : Longint;
        j       : Longint;
        ch      : Char;
begin
        fillchar ( map , sizeof ( map ) , 0 );
        for i := 1 to n do
                begin
                for j := 1 to m do
                        begin
                        read ( ch );
                        map [i] [j] := ch = 'X';
                        end;
                readln;
                end;
end;

procedure swap ( var a , b : Longint );
var     t       : Longint;
begin
        t := a; a := b; b := t;
end;

function RangeIn ( x , y : Longint ) : Boolean;
begin
        RangeIn := ( x >= 0 ) and ( x <= n + 1 ) and ( y >= 0 ) and ( y <= m + 1 );
end;

function cost ( sx , sy , gx , gy : Longint ) : Longint;
var     s , t   : Longint;
        rx , ry : Longint;
        px , py : Longint;
        i       : Longint;
        x , y   : Longint;
        face    : Longint;
        min     : Longint;

        procedure insert ( x , y , c , face : Longint );
        begin
                if not RangeIn ( x , y ) then exit;
                if ( mincost [x] [y] [face] <> 0 ) and ( mincost [x] [y] [face] <= c ) then exit;
                mincost [x] [y] [face] := c;
                if ( map [x] [y] ) then exit;
                
                inc ( t );
                line [t] [0] := x;
                line [t] [1] := y;
                line [t] [2] := face;
        end;
        
begin
        fillchar ( mincost , sizeof ( mincost ) , 0 );

        t := 0; s := 1;
        for i := 0 to 3 do
                begin
                mincost [sx] [sy] [i] := 1;
                insert ( sx + dx [i] , sy + dy [i] , 1 , i );
                end;

        repeat
                x := line [s] [0];
                y := line [s] [1];
                face := line [s] [2];
                
                rx := x; ry := y;
                while ( true ) do
                        begin
                        inc ( rx , dx [face] );
                        inc ( ry , dy [face] );
                        if not RangeIn ( rx , ry ) then break;
                        if ( mincost [rx] [ry] [face] <> 0 ) and ( mincost [rx] [ry] [face] < mincost [x] [y] [face] ) then break;
                        mincost [rx] [ry] [face] := mincost [x] [y] [face];
                        if map [rx] [ry] then break;
                        end;

                rx := x; ry := y;
                repeat
                        if map [rx] [ry] then break;
                        for i := 0 to 3 do
                                begin
                                if i = face then continue;
                                if i = ( face + 2 ) mod 4 then continue;

                                px := rx + dx [i];
                                py := ry + dy [i];
                                insert ( px , py , mincost [x] [y] [face] + 1 , i );
                                end;
                        inc ( rx , dx [face] );
                        inc ( ry , dy [face] );
                until not RangeIn ( rx , ry );
                
                inc ( s );
        until s > t;


        min := maxlongint;
        for i := 0 to 3 do
                if ( mincost [gx] [gy] [i] > 0 ) and ( mincost [gx] [gy] [i] < min ) then
                        min := mincost [gx] [gy] [i];
        cost := min;
        if ( sx = gx ) and ( sy = gy ) then cost := 0;
        if min = maxlongint then cost := -1;
end;

procedure Work;
var     x1 , y1 , x2 , y2       : Longint;
        p                       : Longint;
        c                       : Longint;
begin
        p := 0;
        while true do
                begin
                readln ( y1 , x1 , y2 , x2 );
                if ( y1 = 0 ) then break;
                inc ( p );
                c := cost ( x1 , y1 , x2 , y2 );
                if c >= 0 then writeln ( 'Pair ' , p , ': ' , c ,' segments.' )
                        else writeln ( 'Pair ' , p , ': impossible.' );
                end;
end;

begin
        part := 0;
        while true do
                begin
                readln ( m , n );
                if ( m = 0 ) then break;

                inc ( part );
                writeln ( 'Board #' , part , ':' );
                init;

                Work;
                writeln;
                end;
end.
