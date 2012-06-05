program p1118;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        MaxTerest       = 10;
        MaxPoints       = 1000;

type
        TPoint  = array [1..MaxTerest] of Longint; // 坐标的表示方法



var
        n               : Longint;
        step            : Longint;
        TotalPoint      : Longint;
        StartPoint      : Longint;
        GoalPoint       : Longint;
        Point           : array [1..maxPoints] of TPoint;
        ReachAble       : array [1..maxPoints] of Boolean;
        Edge            : array [1..maxPoints , 1..maxPoints] of Boolean;

function find ( const v : TPoint ) : Longint;
var     i               : Longint;
        j               : Longint;
        Equal           : Boolean;
begin
        for i := 1 to TotalPoint do
                begin
                Equal := true;
                for j := 1 to n do if v [j] <> Point [i] [j] then
                        begin
                        Equal := false;
                        break;
                        end;
                if Equal then begin
                        Result := i;
                        exit;
                        end;                
                end;
        inc ( TotalPoint );
        Point [TotalPoint] := v;
        Result := TotalPoint;
end;

procedure init;
var     i               : Longint;
        a , b           : TPoint;
        P1 , P2         : Longint;
        First           : Boolean;
begin
        TotalPoint := 0;
        fillchar ( Edge , sizeof ( Edge ) , 0 );
        First := true;
        while ( true ) do
                begin
                for i := 1 to n do
                        begin
                        read ( a [i] );
                        if a [i] = - 1 then exit;
                        end;
                        
                for i := 1 to n do read ( b [i] );
                readln;

                P1 := find ( a ); P2 := find ( b );

                if First then begin
                        StartPoint := P1;
                        GoalPoint := P2;
                        First := false;
                        continue;
                        end;
                        
                Edge [P1] [P2] := true;
                Edge [P2] [P1] := true;
                end;
end;

procedure search ( v : Longint );
var     i               : Longint;
begin
        if ReachAble [v] then exit;
        ReachAble [v] := true;
        for i := 1 to TotalPoint do
                if Edge [v] [i] then search ( i );
end;

procedure main;
begin
        fillchar ( ReachAble , sizeof ( ReachAble ) , 0 );
        search ( StartPoint );
        if ReachAble [GoalPoint] then
                writeln ( 'Maze #' , step , ' can be travelled' )
                        else
                writeln ( 'Maze #' , step , ' cannot be travelled' );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        Step := 0;
        while ( true ) do
                begin
                readln ( n );
                if n = 0 then break;
                inc ( Step );
                init;
                main;
                end;
end.
