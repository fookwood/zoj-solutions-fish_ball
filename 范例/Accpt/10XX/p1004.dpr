program p1004;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

var
        standard        : String;
        goal            : String;
        precept         : String;
        stack           : String;

procedure search ( p , q : Longint );
var     ch      : Char;
begin
        if p = length ( standard ) + 1 then
                begin
                writeln ( precept , ' ' );
                exit;
                end;
        
        if q < length ( standard ) + 1 then
                begin
                precept := precept + ' i';
                stack := stack + standard [q];
                search ( p , q + 1 );
                delete ( precept , length ( precept ) - 1 , 2 );
                delete ( stack , length ( stack ) , 1 );
                end;

        if ( length ( stack ) > 0 ) and ( stack [length ( stack )] = goal [p] ) then
                begin
                precept := precept + ' o';
                ch := stack [length ( stack )];
                delete ( stack , length ( stack ) , 1 );

                search ( p + 1 , q );
                delete ( precept , length ( precept ) - 1 , 2 );
                stack := stack + ch;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        {assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );}

        while not seekeof do
                begin
                readln ( standard );
                readln ( goal );
                precept := 'i';
                stack   := standard [1];
                writeln ( '[' );
                search ( 1 , 2 );
                writeln ( ']' );
                end;
end.
