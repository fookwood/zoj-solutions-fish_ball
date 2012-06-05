program p1487;

{$APPTYPE CONSOLE}

type
        point=^node;
        node=record
                card:integer;
                left,right:point;
                end;

var
        n,m     :longint;
        queue   :point;
        i       :Integer;
        j       :integer;
        tp      :point;

begin
while not eof do
        begin
        readln(n,m);
        new(queue);
        queue^.card:=n;
        queue^.left:=queue;
        queue^.right:=queue;
        for I:=n-1 downto 1 do
                begin
                for j:=1 to m mod (n-i) do
                        queue:=queue^.left;
                new(tp);
                tp^.right:=queue^.right;
                queue^.right^.left:=tp;
                tp^.left:=queue;
                queue^.right:=tp;
                tp^.card:=i;
                end;
        for J:=1 to m mod n do queue:=queue^.left;
        tp:=queue^.right;
        while tp<>queue do
                begin
                write(tp^.card,' ');
                tp:=tp^.right;
                end;
        writeln(tp^.card);
        end;
end.
 