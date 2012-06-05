program P1039;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        power2  : array[2..20] of Longint =
                ( 1, 2, 4, 8, 16,
                  32, 64, 128, 256, 512,
                  1024, 2048, 4096, 8192, 16384,
                  32768, 65536, 131072, 262144 );

var     Choose  : array[2..20] of Boolean;
        Win     : array[0..1 shl 19 - 1] of Byte;

function Notice ( s : Longint; InputToChoose : Boolean ) : Byte;
var
        i , j   : Longint;
        t       : Longint;
begin
        if Win [s] > 0 then begin Notice := Win [s]; exit; end;
        Win [s] := 1;
        for i := 2 to 20 do
                if s and power2 [i] > 0 then
                        begin
                        t := s xor power2 [i];
                        
                        for j := 2 to 20 - i do
                                if t and power2 [j] = 0 then
                                        t := t and not power2 [j + i];

                        if Notice ( t , false ) = 1 then
                                if InputToChoose
                                        then begin
                                        Win [s] := i;
                                        Choose [i] := true;
                                        end
                                        else begin
                                        Win [s] := i;
                                        break;
                                        end;
                        end;
        Notice := Win [s];
end;

procedure init;
begin
        fillchar ( Win , sizeof ( Win ) , 0 );
        Win [0] := 1;
end;

procedure Work;
var     s       : Longint;
        i , t   : Longint;
        l       : Longint;
        part    : Longint;
        p       : Longint;
begin
        readln ( part );
        for p := 1 to part do
                begin
                writeln ( 'Scenario #' , p , ':' );
                s := 0;
                read ( l );
                for i := 1 to l do
                        begin
                        read ( t );
                        s := s or power2 [t];
                        end;
                fillchar ( Choose , sizeof ( Choose ) , 0 );
                if s <> 0 then Win [s] := 0;
                Notice ( s , true );
                if Win [s] = 1 then
                        writeln ( 'There is no winning move.' )
                                else begin
                        write ( 'The winning moves are:' );
                        for i := 2 to 20 do if Choose [i] then write ( ' ' , i );
                        writeln ( '.' );
                                end;
                writeln;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        init;
        Work;
end.
