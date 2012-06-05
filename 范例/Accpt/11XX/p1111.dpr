program p1111;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        Card    = Object
                Level   : Longint;
                UseRank : Longint;
                Rank    : array[1..5] of Longint;
                num     : array[2..14] of Longint;
                col     : array[1..4] of Longint;
                procedure PutsIn;
                function HighCard       : Boolean;
                function Pair           : Boolean;
                function TwoPair        : Boolean;
                function ThreeOfAKind   : Boolean;
                function Straight       : Boolean;
                function Flush          : Boolean;
                function FullHouse      : Boolean;
                function FourOfAKind    : Boolean;
                function StraightFlush  : Boolean;
                procedure MakeLevel;
                end;

var     p1 , p2         : Card;

procedure Card.PutsIn;
var     i       : Longint;
        ch      : Char;
begin
        ch := ' ';
        for i := 1 to 5 do
                begin
                if i > 1 then read ( ch );
                read ( ch );
                case    ch of
                        'T'     : inc ( num [10] );
                        'J'     : inc ( num [11] );
                        'Q'     : inc ( num [12] );
                        'K'     : inc ( num [13] );
                        'A'     : inc ( num [14] );
                        else    inc ( num [ord ( ch ) - 48] );
                end; {case}

                read ( ch );
                case    ch of
                        'C'     : inc ( col [1] );
                        'D'     : inc ( col [2] );
                        'H'     : inc ( col [3] );
                        'S'     : inc ( col [4] );
                end; {case}
                end;
        if eoln then readln
                else read ( ch );
end;

function Card.HighCard : Boolean;
var     i , j   : Longint;
begin
        Result := true;
        Level := 1;
        UseRank := 5;
        i := 0;
        for j := 14 downto 2 do if num [j] = 1 then begin inc ( i ); Rank [i] := j; end;
end;

function Card.Pair : Boolean;
var     i , j , k       : Longint;
begin
        Result := false;
        for i := 14 downto 2 do if num [i] = 2 then
                begin
                Result := true;
                Level := 2;
                UseRank := 4;
                Rank [1] := i; j := 1;
                for k := 14 downto 2 do if num [k] = 1 then begin inc ( j ); Rank [j] :=k; end;
                exit;
                end;
end;

function Card.TwoPair : Boolean;
var     i , j   : Longint;
        k       : Longint;
begin
        for i := 14 downto 2 do if num [i] = 2 then
        for j := i - 1 downto 2 do if num [j] = 2 then
        for k := 14 downto 2 do if num [k] = 1 then
                begin
                Result := true;
                Level := 3;
                UseRank := 3;
                Rank [1] := i;
                Rank [2] := j;
                Rank [3] := k;
                exit;
                end;
        Result := false;
end;

function Card.ThreeOfAKind : Boolean;
var     i       : Longint;
begin
        Result := false;
        for i :=14 downto 2 do if num [i] = 3 then
                begin
                Result := true;
                Level := 4;
                UseRank := 1;
                Rank [1] := i;
                exit;
                end;
end;

function Card.Straight : Boolean;
var     i       : Longint;
        j       : Longint;
begin
        for i := 14 downto 2 do if num [i] > 0 then begin
                for j := 1 to 4 do if ( i - j < 2 ) or ( num [i - j] <> 1 ) then
                        begin Result := false; exit; end;
                break;
                end;
        Result := true;
        Level := 5;
        UseRank := 1;
        Rank [1] := i;
end;

function Card.Flush : Boolean;
var     i , j   : Longint;
        k       : Longint;
begin
        for i := 1 to 4 do if col [i] = 5 then
                begin
                Result := true;
                Level := 6;
                UseRank := 5;
                j := 0;
                for k := 14 downto 2 do if num [k] = 1 then
                        begin
                        inc ( j );
                        Rank [j] := k;
                        end;
                exit;
                end;
        Result := false;
end;

function Card.FullHouse : Boolean;
var     i , j   : Longint;
begin
        for i := 14 downto 2 do if num [i] = 3 then
                for j := 14 downto 2 do if num [j] = 2 then
                        begin
                        Result := true;
                        Level := 7;
                        UseRank := 1;
                        Rank [1] := i;
                        exit;
                        end;
        Result := false;
end;

function Card.FourOfAKind : Boolean;
var     i       : Longint;
begin
        for i := 14 downto 2 do if num [i] = 4 then
                begin
                Result := true;
                Level := 8;
                UseRank := 1;
                Rank [1] := i;
                exit;
                end;
        Result := false;
end;

function Card.StraightFlush : Boolean;
var     i , j   : Longint;
begin
        Result := false;
        for i := 1 to 4 do if ( col [i] > 0 ) and ( col [i] < 5 ) then exit;
        for i := 14 downto 2 do if num [i] > 0 then begin
                for j := 1 to 4 do if ( i - j < 2 ) or ( num [i - j] <> 1 ) then exit;
                break;
                end;
        Result := true;
        Level := 9;
        UseRank := 1;
        Rank [1] := i;        
        
end;

procedure Card.MakeLevel;
begin
        if StraightFlush        then exit;
        if FourOfAKind          then exit;
        if FullHouse            then exit;
        if Flush                then exit;
        if Straight             then exit;
        if ThreeOfAKind         then exit;
        if TwoPair              then exit;
        if Pair                 then exit;
        if HighCard             then exit;
end;

function comp : Longint;
var     i       : Longint;
begin
        if P1.Level <> P2.Level then begin comp := P1.Level - P2.Level ; exit; end;
        for i := 1 to P1.UseRank - 1 do if P1.Rank [i] <> P2.Rank [i] then
                begin comp := P1.Rank [i] - P2.Rank [i]; exit; end;
        comp := P1.Rank [P1.UseRank] - P2.Rank [P2.UseRank];
end;

procedure Work;
var
        cp      : Longint;
begin
        fillchar ( P1 , sizeof ( P1 ) , 0 );
        fillchar ( P2 , sizeof ( P2 ) , 0 );
        P1.PutsIn;
        P2.PutsIn; 
        P1.MakeLevel;
        P2.MakeLevel;
        cp := comp;
        if cp > 0 then writeln ( 'Black wins.' );
        if cp < 0 then writeln ( 'White wins.' );
        if cp = 0 then writeln ( 'Tie.' );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while not seekeof do Work;
end.
