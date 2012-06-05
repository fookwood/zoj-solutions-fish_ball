program p1012;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        Information     = Object
                CPUs            : Longint;
                Memories        : Longint;
                Arriving        : Longint;
                TimeLine        : Longint;
                reward          : Longint;
                bonus           : Longint;
                punishment      : Longint;
                Next            : Longint;
                end;

var
        part            : Longint;
        nCPUs           : Longint;
        nMemories       : Longint;
        nWork           : Longint;
        TimeLimit       : Longint;
        MaxGet          : Longint;

        data            : array[1..10000] of Information;

procedure init;
var     i               : Longint;
begin
        readln ( nCPUs , nMemories , nWork );
        for i := 1 to nWork do with data [i] do
                readln ( CPUs , Memories , Arriving , TimeLine , reward , bonus , punishment );
end;

function comp ( var a , b : Information ) : Longint;
begin
        if a.Arriving = b.Arriving
                then comp := b.reward - a.reward
                else comp := a.Arriving - b.Arriving;
end;

procedure sort ( left , right : Longint );
var     i , j   : Longint;
        Key     : Information;
        t       : Information;
begin
        i := left - 1; j := right + 1;
        Key := data [left + random ( right - left )];
        
        repeat
                repeat dec ( j ); until comp ( data [j] , Key ) <= 0;
                repeat inc ( i ); until comp ( data [i] , Key ) >= 0;
                if ( i < j ) then
                        begin
                        t := data [i]; data [i] := data [j]; data [j] := t;
                        end else break;
        until false;
        if left < j then sort ( left , j );
        if j + 1 < right then sort ( j + 1 , right );
end;

procedure Work;
var     i       : Longint;
        j       : Longint;
        l       : Longint;
        TimeTo  : Longint;
        LeftWork        : Longint;
        LeftCPUs        : Longint;
        LeftMemories    : Longint;
begin
        for i := 1 to 9999 do data [i].Next := i + 1;
        data [nWork].Next := 0;

        MaxGet := 0;
        TimeTo := 0;
        LeftWork := nWork;

        i := 1;
        while ( TimeTo < TimeLimit ) and ( LeftWork > 0 ) do
                begin
                LeftCPUs := nCPUs;
                LeftMemories := nMemories;
                j := i; l := i;
                
                while ( j <> 0 ) and ( data [j].Arriving <= TimeTo ) do
                        begin
                        if ( LeftCPUs >= data [j].CPUs ) and ( LeftMemories >= data [j].Memories ) then
                                begin
                                dec ( LeftCPUs , data [j].CPUs );
                                dec ( LeftMemories , data [j].Memories );
                                if TimeTo + 1 <= data [j].TimeLine
                                        then inc ( MaxGet , data [j].reward + ( data [j].TimeLine - TimeTo - 1 ) * data [j].bonus )
                                        else inc ( MaxGet , data [j].reward - ( TimeTo + 1 - data [j].TimeLine ) * data [j].punishment );
                                if ( i = j ) then i := data [i].Next;
                                data [l].Next := data [j].Next;
                                dec ( LeftWork );
                                end else l := j;
                        j := data [j].Next;
                        end;
                inc ( TimeTo );
                end;
        j := i;
        while ( j <> 0 ) do
                begin
                if TimeLimit > data [j].TimeLine then
                        dec ( MaxGet , ( TimeLimit - data [j].TimeLine ) * data [j].punishment );
                j := data [j].Next;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        randomize;
        part := 0;
        while true do
                begin
                readln ( TimeLimit );
                if TimeLimit = 0 then break;
                inc ( part );

                init;
                sort ( 1 , nWork );

                Work;
                writeln ( 'Case ' , part , ': ' , MaxGet );
                writeln;
                end;
end.
