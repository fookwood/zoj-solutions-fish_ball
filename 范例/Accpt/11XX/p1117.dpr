program p1117;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        node    = record
                name    : Char;
                num     : Longint;
                Used    : Boolean;
                end;

var
        len     : Longint;
        data    : array[1..100] of node;
        s       : String;

procedure insert ( c : Char );
var     i       : Longint;
begin
        for i := 1 to len do
                if data [i].name = c then
                        begin
                        inc ( data [i].num );
                        exit;
                        end;
        inc ( len );
        data [len].name := c;
        data [len].num := 1;
        data [len].Used := false;
end;

procedure GetMin ( var v , s : Longint );
var     i       : Longint;
begin
        v := maxLongint;
        for i := 1 to len do
                if not data [i].Used and ( data [i].num < v ) then
                        begin
                        v := data [i].num;
                        s := i;
                        end;
end;

procedure work;
var
        i       : Longint;
        min1    : Longint;
        min2    : Longint;
        f1      : Longint;
        f2      : Longint;
        Total   : Longint;
begin
        len := 0;
        for i := 1 to length ( s ) do
                insert ( s [i] );
        
        Total := 0;
        for i := 1 to len - 1 do
                begin
                GetMin ( min1 , f1 );
                data [f1].Used := true;
                GetMin ( min2 , f2 );
                inc ( data [f2].num , data [f1].num );
                inc ( Total , data [f2].num );
                end;
        if len = 1 then Total := data [1].num;
        writeln ( length ( s ) * 8 , ' ' , Total , ' ' , length ( s ) * 8 / Total : 0 : 1 );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        while true do
                begin
                readln ( s );
                if s = 'END' then break;
                work;
                end;

end.
