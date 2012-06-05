program p1050;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

const
        maxWords        = 10000;
        Finish          = '----------';

type
        Ducument        = Object
                Total   : Longint;
                Words   : array [1..maxWords] of String;
                Many    : array [1..maxWords] of Longint;

                procedure Null;
                procedure Add ( var s : String );
                procedure PutInIt;
                function Num ( var s : String ) : Longint;
                end;

var
        part , p        : Longint;
        FirstDucument   : Ducument;
        SecondDUcument  : Ducument;

procedure Ducument . Null;
begin
        Total := 0;
end;

procedure Ducument .Add ( var s : String );
var     i       : Longint;
begin
        for i := 1 to Total do
                if Words [i] = s then
                        begin
                        inc ( Many [i] );
                        exit;
                        end;
        inc ( Total );
        Words [Total] := s; Many [Total] := 1;
end;

procedure Ducument .PutInIt;
var     s       : String;
        term    : String;
        i       : Longint;
begin
        Null;
        while true do
                begin
                readln ( s );
                if s = Finish then exit;
                s := LowerCase ( s ) + ' ';
                term := '';
                for i := 1 to length ( s ) do
                        if ( ord ( s [i] ) <= 13 ) or ( s [i] = ' ' ) then
                                begin
                                if term <> '' then Add ( term );
                                term := '';
                                end else
                        if ( ( s [i] >= 'a' ) and ( s [i] <= 'z' ))
                                or (( s[i] >= '0' ) and ( s [i] <= '9' )) then
                                term := term + s [i];
                end;
end;

function Ducument .Num ( var s : String ) : Longint;
var     i       : Longint;
begin
        for i := 1 to Total do
                if Words [i] = s then
                        begin
                        Num := Many [i];
                        exit;
                        end;
        Num := 0;
end;

function Score : Double;
var     Ret     : Double;
        i       : Longint;
        
begin
        Ret := 0;
        with FirstDucument do
                for i := 1 to Total do
                Ret := Ret + sqrt ( SecondDucument.Num( Words [i] ) * Many [i] );
        Score := Ret;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }

       { assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
       }
        readln ( part );
        for p := 1 to part do
                begin
                if p > 1 then writeln;
                readln;

                FirstDucument.PutInIt;
                SecondDucument.PutInIt;
                while ( SecondDucument.Total > 0 ) do
                        begin
                        writeln ( Score : 0 : 2 );
                        SecondDucument.PutInIt;
                        end;
                end;
end.
