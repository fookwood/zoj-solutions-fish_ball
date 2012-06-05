program p1156;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        maxn    = 512;

type
        node    = record
                Num     : array[0..3] of Longint;
                Value   : Longint;
                end;

var
        PointNum: Longint;
        Total   : Longint;
        p       : Longint;
        part    : Longint;
        n       : Longint;
        data    : array[0..maxn] of node;
        map     : array[0..maxn , 0..maxn] of Longint;

procedure Caculate ( Number : Longint; x , y : Longint );
var     Father  : Longint;
        X_ , Y_ : Longint;
begin
        repeat
                Father := ( Number - 1 ) div 4;
                X_ := x mod 2; Y_ := y mod 2;
                data [Father].Num [ord ( X_ = 1 ) * 2 + ord ( Y_ = 1 )] := Number;
                Number := Father;
                x := x div 2; y := y div 2; 
        until Father = 0;
end;

procedure FillIn ( Number : Longint );
var     i       : Longint;
        Sub     : Longint;
begin
        Sub := Number * 4; if Sub > PointNum then exit;
        for i := 1 to 4 do
                begin
                inc ( Sub );
                data [Sub].Value := data [Number].Value;
                FillIn ( Sub );
                end;
end;

procedure FillMap ( Number : Longint; x , y , L : Longint );
begin
        if Number * 4 >= PointNum then
                begin
                map [x] [y] := data [Number].Value;
                exit;
                end;

        FillMap ( data [Number].Num [0] , x , y , L div 2 );
        FillMap ( data [Number].Num [1] , x , y + L , L div 2 );
        FillMap ( data [Number].Num [2] , x + L , y , L div 2 );
        FillMap ( data [Number].Num [3] , x + L , y + L , L div 2 );
end;

procedure init;
var     i       : Longint;
        m       : Longint;
        x , y   : Longint;
        Number  : Longint;
        Tpos    : Longint;
begin
        readln ( n );
        PointNum := 0; 
        i := 1;
        if n = 1 then PointNum := 0 else
        repeat
                i := i * 2;
                inc ( PointNum , sqr ( i ));
        until i = n;

        for i := 1 to PointNum do with data [i] do
                begin
                Num [0] := 0; Num [1] := 0; Num [2] := 0; Num [3] := 0;
                Value := -1;
                end;

        readln ( m );
        for i := 1 to m do
                begin
                readln ( Number , TPos );
                x := TPos div n;
                y := TPos mod n;
                Caculate ( Number , x , y );
                end;

        readln ( m );
        for i := 1 to m do
                begin
                readln ( Number , data [Number].Value );
                FillIn ( Number );
                end;

        FillMap ( 0 , 0 , 0 , n div 2 );
end;

procedure print;
var     i , j   : Longint;
begin
        for i := 0 to n - 1 do
                begin
                for j := 0 to n - 1 do write ( map [i] [j] : 4 );
                writeln;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        readln ( part );
        while ( part > 0 ) do
                begin
                readln ( Total );
                for p := 1 to Total do
                        begin
                        if p > 1 then writeln;
                        init;
                        writeln ( 'Case ' , p );
                        writeln;
                        print;
                        end;
                dec ( part );
                if part > 0 then writeln;
                end;
end.
