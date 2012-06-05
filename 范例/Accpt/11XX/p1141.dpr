program p1141;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        node    = record
                Father          : Longint;
                Number          : Longint;
                Dep             : Longint;
                end;

var
        line    : array[1..1000] of node;
        Used    : array[1..1000] of Longint;
        n       : Longint;
        m       : Longint;

function search ( p : Longint ) : Longint;
begin
        if p = 0 then search := 0 
                else begin
                if line [p].Dep = 0 then line [p].dep := search ( line [p].Father );
                search := line [p].Dep + 1;
                end;
end;

procedure init;
var     i       : Longint;
        a , b   : Longint;
        ch      : Char;
        j       : Longint;
        c       : Longint;
begin
        readln ( n );
        fillchar ( line , sizeof ( line ) , 0 );
        for i := 1 to n do
                begin
                a := 0;
                while ( true ) do
                        begin
                        read ( ch );
                        if ( ch < '0' ) or ( ch > '9' ) then break;
                        a := a * 10 + ord ( ch ) - 48;
                        end;

                

                read ( ch ); while ( ch <> '(' ) do read ( ch );
                
                b := 0;
                while ( true ) do
                        begin
                        read ( ch );
                        if ( ch < '0' ) or ( ch > '9' ) then break;
                        b := b * 10 + ord ( ch ) - 48;
                        end;
                        
                while not eoln and ( ch <> ' ' ) do read ( ch );
                
                for j := 1 to b do
                        begin
                        read ( c );
                        line [c].Father := a;
                        end;
                readln;
                end;
        for i := 1 to n do search ( i );
end;

function Common ( a , b : Longint ) : Longint;
begin
        if a = b then Common := a else
        if ( line [a].Dep > line [b].Dep ) then Common := Common ( line [a].Father , b )
                else Common := Common ( a , line [b].Father );
end;

procedure Work;
var     i       : Longint;
        ch      : Char;
        a       : Longint;
        b       : Longint;
begin
        readln ( m );
        fillchar ( Used , sizeof ( Used ) , 0 );
        for i := 1 to m do
                begin
                repeat read ( ch ); until ch = '(';
                a := 0;
                while ( true ) do
                        begin
                        read ( ch );
                        if ch = ',' then break;
                        a := a * 10 + ord ( ch ) - 48;
                        end;
                b := 0;
                while ( true ) do
                        begin
                        read ( ch );
                        if ch = ')'  then break;
                        b := b * 10 + ord ( ch ) - 48;
                        end;
                inc ( Used [ Common ( a , b )] );
                end;
        readln;
end;

procedure Print;
var
        i       : Longint;
begin
        for i := 1 to n do
                if Used [i] > 0 then writeln ( i , ':' , Used [i] );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        while not seekeof do
                begin
                init;
                Work;
                Print;
                end;
end.
