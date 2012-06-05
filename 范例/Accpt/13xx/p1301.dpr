program p1031;

{$APPTYPE CONSOLE}

type
        TState  = array [1..2047,1..10] of Longint;
        TLine   = array [1..10,0..10] of Longint;
        TOrder  = array [1..10] of Longint;
        TList   = array [1..20470] of Longint;
        
var
        Villa , room    : Longint;
        Way , Contrl    : TLine;
        State , prev    : TState;
        Order           : TOrder;
        List            : TList;

PROCEDURE makeorder;
var
        i               : Integer;
begin
order [1] := 1;
for i := 2 to 10 do order [i] := order [i - 1] shl 1;
end;

FUNCTION init : Boolean;
var
        d , s , i , a , b
                         : Integer;
begin
readln ( room , d , s );

if ( room = 0 ) and ( d = 0 ) and ( s = 0 ) then
        begin
        Init := false;
        exit;
        end;

Init := true;
fillchar ( Way , sizeof ( Way ) , 0 );
fillchar ( Contrl , sizeof ( Contrl ) , 0 );

// readin the room contect
for i := 1 to d do
        begin
        readln ( a , b );
        if ( a = b ) then continue;
        inc ( Way [a] [0] );
        Way [a] [ Way [a] [0] ] := b;
        inc ( Way [b] [0] );
        Way [b] [ Way [b] [0] ] := a;
        end;

// readin contrl for each room
for i := 1 to s do
        begin
        readln ( a , b );
        if ( a = b ) then continue;
        inc ( Contrl [a] [0] );
        Contrl [a] [ Contrl [a] [0] ] := b;
        end;

fillchar ( State , sizeof ( State ) , 0 );
end;

PROCEDURE Print ( v : Longint );
var
        have , place , lhave , lplace
                                : Longint;
        i                       : Integer;
begin
if v = 101 then exit;

have  := v div 100;
place := v mod 100;

print ( prev [ have ] [ place ] );

lhave  := prev [ have ] [ place ] div 100;
lplace := prev [ have ] [ place ] mod 100;

//writeln(prev[have][place]);
if place <> lplace then
        begin
        writeln ( '- Move to room ' , place , '.' );
        end else
        begin
        for i := 1 to room do
                if Order [i] = have xor lhave then break;
                
        if lhave < have then
                writeln ( '- Switch on light in room ' , i , '.' )
                        else
                writeln ( '- Switch off light in room ' , i , '.' );
        end;
end;

PROCEDURE Kfs;
var
        open , closed , have , place , goal , i , j ,
        chave , cplace , long
                                : Longint;
begin
open     := 1;
closed   := 1;
List [1] := 101;
goal     := Order [room] * 100 + room;

repeat
        have  := List [ open ] div 100;
        place := List [ open ] mod 100;
        long  := State [ have ] [ place ] + 1;

        for i := 1 to Contrl [place] [0] do
                begin
                j := Contrl [place] [i];
                
                        // open the light
                if ( have and Order [j] = 0 ) then
                        begin
                        chave  := have or Order [j];
                        cplace := place;
                        if ( State [ chave ] [ cplace ] = 0 ) or
                                ( long < State [ chave ] [ cplace ] ) then
                                        begin
                                        inc ( closed );
                                        List [closed] := chave * 100 + cplace;
                                        State [ chave ] [ cplace ] := long;
                                        prev [ chave ] [ cplace ] := List [open];
                                        end;
                        // close the light 
                        end else
                        begin
                        chave   := have xor Order [j];
                        cplace  := place;
                        if ( State [ chave ] [ cplace ] = 0 ) or
                                ( long < State [ chave ] [ cplace ] ) then
                                        begin
                                        inc ( closed );
                                        List [closed] := chave * 100 + cplace;
                                        State [ chave ] [ cplace ] := long;
                                        prev [ chave ] [ cplace ] := List [open];
                                        end;
                        end;
                end;

        for i := 1 to Way [place] [0] do
                begin
                //  Move
                j := Way [place] [i];
                if have and Order [j] = Order [j] then
                        begin
                        chave  := have;
                        cplace := j;
                        if ( State [ chave ] [ cplace ] = 0 ) or ( long < State [ chave ] [ cplace ] ) then
                                begin
                                inc ( closed );
                                List [ closed ] := chave * 100 + cplace;
                                State [ chave ] [ cplace ] := long;
                                prev [ chave ] [ cplace ] := List [open];
                                end;
                        end;
                end;
        inc ( open );
until open > closed;
if ( State [ Order [room] ] [ room ] = 0 ) and not ( room = 1 ) then
        writeln ( 'The problem cannot be solved.' )
                else
                begin
                writeln ( 'The problem can be solved in ' , State [Order [room] ] [room] , ' steps:');
                Print ( goal ) ;
                end;
//;writeln (goal );
end;

begin
{
assign ( input , 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );
}

makeorder;

Villa := 0;
while Init do
        begin

        inc ( Villa );
        writeln ( 'Villa #' , Villa );

        Kfs;

        writeln;
        end;
end.
