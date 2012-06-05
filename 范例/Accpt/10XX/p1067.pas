PROGRAM p1067;

TYPE
        node=record
                x,y,z:integer;
                end;

VAR
        map     :array[1..16]of node;
        i       :integer;
        temp    :node;
        mindis  :real;
        ans     :node;

BEGIN
for i:=1 to 16 do
        readln(map[i].x,map[i].y,map[i].z);
readln(temp.x,temp.y,temp.z);
while (temp.x<>-1) do
        begin
        mindis:=1e6;
        for i:=1 to 16 do
                if sqrt(sqr(temp.x-map[i].x)+sqr(temp.y-map[i].y)+sqr(temp.z-map[i].z))<mindis then
                        begin
                        mindis:=sqrt(sqr(temp.x-map[i].x)+sqr(temp.y-map[i].y)+sqr(temp.z-map[i].z));
                        ans:=map[i];
                        end;
        writeln('(',temp.x,',',temp.y,',',temp.z,') maps to (',ans.x,',',ans.y,',',ans.z,')');
        readln(temp.x,temp.y,temp.z);
        end;

END.
