PROGRAM p1315;

VAR
        step                            :Integer;
        numdic,numdata                  :Integer;
        i                               :Integer;
        data,dic,copy                   :array[1..20]of String;

PROCEDURE Main;
var
        i,j,p                           :Integer;
        max                             :Integer;
        match                           :array[1..20]of Integer;
        s                               :String;
        flag                            :Boolean;

begin
max:=0;
for i:=1 to numdata do
        begin
        match[i]:=0;
        for j:=1 to numdic do
                begin
                s:=data[i];
                while pos(dic[j],s)>0 do
                        begin
                        p:=pos(dic[j],s);
                        if (p=1)or(p+length(dic[j])-1=length(s)) then
                                flag:=true else
                                begin
                                flag:=true;
                                if (((s[p-1]>='a')and(s[p-1]<='z')) or
                                        ((s[p-1]>='A')and(s[p-1]<='Z'))) then flag:=false;
                                if (((s[p+length(dic[j])]>='a')and(s[p+length(dic[j])]<='z')) or
                                        ((s[p+length(dic[j])]>='A')and(s[p+length(dic[j])]<='Z'))) then flag:=false;
                                end;
                        if flag then inc(match[i]);
                        s[p]:='/';
                        end;
                end;
        if match[i]>max then max:=match[i];
        end;
writeln('Excuse Set #',step);
for i:=1 to numdata do
        if match[i]=max then writeln(copy[i]);
writeln;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
while not eof do
        begin
        inc(step);
        readln(numdic,numdata);
        for i:=1 to numdic do
                begin
                readln(dic[i]);
                dic[i]:=upcase(dic[i]);
                end;
        for I:=1 to numdata do
                begin
                readln(data[i]);
                copy[i]:=data[i];
                data[i]:=upcase(data[i]);
                end;
        Main;
        end;
END.
