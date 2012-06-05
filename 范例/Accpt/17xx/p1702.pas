PROGRAM p1702;

CONST
        maxwide=30;

VAR
        ste                     :Set of Char;
        s                       :String;
        n,wide,i                :Integer;
        position                :array[1..maxwide]of Integer;
        long                    :array[1..maxwide]of Integer;
        data                    :array[1..21,1..maxwide]of String;

PROCEDURE Costtime(p:Longint);
var
        i,j                     :Longint;
begin
for I:=1 to p do for J:=1 to 10000000 do ;
end;

PROCEDURE Puts;
var
        i,j                     :Longint;
begin
write('@');
for i:=1 to wide do
        begin
        for j:=1 to long[i]+2 do write('-');
        if i<wide then write('-');
        end;
writeln('@');
end;

PROCEDURE Puts_part;
var
        i,j                     :Longint;
begin
write('|');
for i:=1 to wide do
        begin
        for j:=1 to long[i]+2 do write('-');
        if i<wide then write('+');
        end;
writeln('|');
end;

PROCEDURE Putsdata(p:Integer);
var
        i,j,need               :Integer;
begin
write('|');
for i:=1 to wide do
        begin
        need:=long[i]-length(data[p][i]);
        case position[i] of
        -1              :begin
                        write(' ');
                        write(data[p][i]);
                        for j:=1 to need+1 do write(' ');
                        end;

        0               :begin
                        write(' ');
                        for j:=1 to need div 2 do write(' ');
                        write(data[p][i]);
                        for j:=1 to need - need div 2 do write(' ');
                        write(' ');
                        end;

        1               :begin
                        write(' ');
                        for j:=1 to need do write(' ');
                        write(data[p][i]);
                        write(' ');
                        end;
        end;
        write('|');
        end;
writeln;
end;

PROCEDURE Main;
var
        i,j                     :Integer;
begin
{writeln('Here are all datas:');
writeln('n = ',n);
writeln('Wide = ',wide);

writeln;
for i:=1 to n do
        begin
        for j:=1 to wide do write(data[i][j]:23);
        writeln;
        end;
writeln; }

fillchar(long,sizeof(long),0);
for I:=1 to n do
        for j:=1 to wide do
                if length(data[i][j])>long[j] then long[j]:=length(data[i][j]);

puts;

putsdata(1);
puts_part;

for i:=2 to n do putsdata(i);

puts;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
//assign(output,'p.out');
//rewrite(output);
ste:=['<','>','='];
readln(s);
while (s<>'*') do
        begin
        n:=0;
        wide:=length(s);
        for I:=1 to wide do
                case s[i] of
                '<'     :position[i]:=-1;
                '>'     :position[i]:=1;
                '='     :position[i]:=0;
                end;
        readln(s);
        n:=0;

        while (s<>'*') and not (s[1] in ste) do
                begin
                inc(n);

                s:=s+'&';
                for i:=1 to wide do
                        begin
                        data[n][i]:=copy(s,1,pos('&',s)-1);
                        delete(s,1,pos('&',s));
                        end;
                readln(s);
                end;

        Main;
        end;
//close(output);
END.