
{$APPTYPE CONSOLE}
const
  fan:array[1..4,1..2]of integer=((-1,0),(0,1),(1,0),(0,-1));
var
        worm:array[1..20,1..2]of shortint;
        map:array[1..50,1..50]of boolean;
        road:array[1..100]of 1..4;
        i,j,n:integer;
procedure init;
var
  t:char;
begin
        fillchar(map,sizeof(map),true);
        for i:=1 to 20 do
        begin
                worm[i,1]:=25;
                worm[i,2]:=30-i+1;
                map[25,10+i]:=false;
        end;
        for i:=1 to n do
        begin
                read(t);
                case t of
                'N':road[i]:=1;
                'E':road[i]:=2;
                'S':road[i]:=3;
                'W':road[i]:=4;
                end;
        end;
end;

procedure work;
var
        se:shortint;
begin
        se:=0;
        i:=1;
        while (i<=n)and(se=0) do
        begin
          map[worm[20,1],worm[20,2]]:=true;
          for j:=20 DOWNto 2 do
          begin
                worm[j,1]:=worm[j-1,1];
                worm[j,2]:=worm[j-1,2];
          end;
          worm[1,1]:=fan[road[i],1]+worm[1,1];
          worm[1,2]:=fan[road[i],2]+worm[1,2];
          if not((worm[1,2]<=50)and(worm[1,2]>=1)and(worm[1,1]<=50)and(worm[1,1]>=1))then
          begin
            se:=2;
          end
          else
          begin
            if map[worm[1,1],worm[1,2]] then map[worm[1,1],worm[1,2]]:=false
            else se:=1;
          end;
          inc(i);
        end;
        if se=0 then writeln('The worm successfully made all ',n,' moves.');
        if se=1 then writeln('The worm ran into itself on move ',i-1,'.');
        if se=2 then writeln('The worm ran off the board on move ',i-1,'.');
end;

begin
        readln(n);
        while n<>0 do
        begin
                init;
                work;
                readln(n);
        end;
end.
