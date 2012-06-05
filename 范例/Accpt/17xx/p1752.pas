PROGRAM p1752;

VAR
        step                            :Longint;
        n,k,i,a,b,c,d,ans,colour        :Longint;
        p,q                             :Longint;
        col                             :array[-100..100,-100..100]of Integer;

BEGIN
step:=0;
//assign(input,'p.in');
//reset(input);
readln(n,k);
while n<>0 do
        begin
        inc(step);
        fillchar(col,sizeof(col),0);
        for I:=1 to n do
                begin
                readln(colour,a,b,c,d);
                if a>c then begin ans:=a;a:=c;c:=ans;end;
                if b>d then begin ans:=b;b:=d;d:=ans;end;
                for p:=a to c-1 do
                        for q:=b to d-1 do col[p,q]:=colour;
                end;
        ans:=0;
        for p:=-100 to 100 do
                for q:=-100 to 100 do if col[p,q]=k then inc(ans);
        writeln('The area of color ',k,' in dataset ',step,' is: ',ans);
        readln(n,k);
        end;
END.
