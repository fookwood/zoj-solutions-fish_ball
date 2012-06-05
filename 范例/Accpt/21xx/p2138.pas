PROGRAM p2138;

VAR
        n,k,part,p,i,j,total                                    :Longint;
        have,data,ans                                           :array[1..100]of Longint;
        whether                                                 :array[1..100]of Boolean;
        min,max                                                 :Longint;


BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        readln(n,k);
        fillchar(whether,sizeof(whether),false);
        fillchar(have,sizeof(have),0);
        fillchar(ans,sizeof(ans),0);
        for i:=1 to n do
                begin
                min:=maxLongint;
                max:=-maxLongint;
                for j:=1 to k do
                        begin
                        read(data[j]);
                        if data[j]<min then min:=data[j];
                        if data[j]>max then max:=data[j];
                        end;
                for j:=1 to k do
                        begin
                        if data[j]=max then whether[j]:=true;
                        if data[j]=min then inc(have[j]);
                        end;
                end;
        total:=0;
        for i:=1 to k do
                if (not whether[i]) then
                if have[i]>n/2 then
                        begin
                        inc(total);
                        ans[total]:=i;
                        end;
        for i:=1 to total-1 do
                write(ans[i],' ');
        if total<>0 then write(ans[total]);
        if total=0 then write(0);
        writeln;
        if p<part then writeln;
        end;
END.
