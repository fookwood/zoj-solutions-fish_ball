program p1061;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        Stack   : array[0..100] of String;
        len     : Longint;
        p       : Longint;
        part    : Longint;

procedure Work;
var     s       : String;
        order   : String;
begin
        len := 0; p := 0;
        Stack [0] := 'http://www.acm.org/';
        readln ( s );
        while s <> 'QUIT' do
                begin
                if pos ( ' ' , s ) > 0 then
                        begin
                        order := copy ( s , 1 , pos ( ' ' , s ) - 1 );
                        delete ( s , 1 , pos ( ' ' , s ));
                        end
                        else order := s;
                        
                if order = 'VISIT' then
                        begin
                        inc ( p );
                        len := p;
                        Stack [len] := s;
                        writeln ( s );
                        end else
                if order = 'BACK' then
                        begin
                        if p = 0 then writeln ( 'Ignored' )
                                else begin
                                dec ( p );
                                writeln ( Stack [p] );
                                end;
                        end else
                if order = 'FORWARD' then
                        begin
                        if p = len then writeln ( 'Ignored' )
                                else begin
                                inc ( p );
                                writeln ( Stack [p] );
                                end;
                        end;
                readln ( s );
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        readln ( part );
        while part > 0 do
                begin
                readln;
                Work;
                dec ( part );
                if part > 0 then writeln;
                end;
end.
