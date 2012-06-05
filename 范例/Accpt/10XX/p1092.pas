PROGRAM p1092;

VAR
//        f       :text;
        dic     :array[1..31]of string;
        dicnum  :longint;
        pre     :array[1..31,1..31]of real;
        n       :longint;
        ans     :boolean;
        i       :longint;
        step    :longint;


PROCEDURE floyd;

var
        i,j,k   :longint;

begin
for K:=1 to dicnum do
          for I:=1 to dicnum do
              if i<>k then
              for j:=1 to dicnum do
                  if (j<>k)and(pre[i,k]<>0)and(pre[k,j]<>0)and(pre[i,k]*pre[k,j]>pre[i,j]) then pre[i,j]:=pre[i,k]*pre[k,j];
ans:=false;
      for I:=1 to dicnum do
                for j:=1 to dicnum do
                if (pre[i,j]*pre[j,i]>1) then
                        begin
                        ans:=true;
                        exit;
                        end;
end;

FUNCTION check(s:string):longint;
var
        I       :longint;
begin
for i:=1 to dicnum do
    if dic[i]=s then
       begin
       check:=i;
       exit;
       end;
check:=-1;
end;

PROCEDURE readin;
var
        i,j     :integer;
        a,b     :longint;
        d       :real;
        s       :string;
        ch      :char;
begin
readln(n);
for i:=1 to n do
        begin
        s:='';
        while true do
                begin
                read(ch);
                if ch=' ' then break;
                s:=s+ch;
                end;

        a:=check(s);
        read(d);
        read(ch);
        readln(s);
        b:=check(s);
        pre[a,b]:=d;
        end;
end;

BEGIN
//assign(input,'p1092.in');
//reset(input);

readln(dicnum);
step:=0;
while dicnum>0 do
      begin
      inc(step);
      for I:=1 to dicnum do
                readln(dic[i]);

      fillchar(pre,sizeof(pre),0);
      readin;
      floyd;

      write('Case ',step,': ');
      if ans then writeln('Yes') else writeln('No');
      readln;
      readln(dicnum);
      end;
//close(f);
END.
