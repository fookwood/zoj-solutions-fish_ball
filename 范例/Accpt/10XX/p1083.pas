{
ID: andyzh11
PROG: frameup
LANG: PASCAL
}

PROGRAM p1083;

VAR
        h,w                             :Integer;
        i,j                             :Integer;
        s                               :String;
        total                           :Integer;
        whether                         :array['A'..'Z','A'..'Z']of Boolean;
        have                            :array['A'..'Z']of Boolean;
        degree                          :array['A'..'Z']of Integer;
        map                             :array[1..30,1..30]of Char;


PROCEDURE Determine;
var
        ch                              :Char;
        i,j                             :Integer;
        minx,miny,maxx,maxy             :Integer;
begin
fillchar(have,sizeof(have),0);
fillchar(whether,sizeof(whether),0);
fillchar(degree,sizeof(degree),0);
for ch:='A' to 'Z' do
        begin
        minx:=maxint;
        miny:=maxint;
        maxx:=0;
        maxy:=0;
        for i:=1 to h do
                for j:=1 to w do
                        if map[i,j]=ch then
                        begin
                        have[ch]:=true;
                        if i>maxx then maxx:=i;
                        if i<minx then minx:=i;
                        if j>maxy then maxy:=j;
                        if j<miny then miny:=j;
                        end;
        if have[ch] then
                begin
                for i:=minx to maxx do
                        begin
                        if not whether[map[i,miny],ch] and (map[i,miny]<>ch) then
                                begin
                                inc(degree[map[i,miny]]);
                                whether[map[i,miny],ch]:=true;
                                end;
                        if not whether[map[i,maxy],ch] and (map[i,maxy]<>ch) then
                                begin
                                inc(degree[map[i,maxy]]);
                                whether[map[i,maxy],ch]:=true;
                                end;
                        end;
                for j:=miny to maxy do
                        begin
                        if (not whether[map[minx,j],ch])and(map[minx,j]<>ch) then
                                begin
                                inc(degree[map[minx,j]]);
                                whether[map[minx,j],ch]:=true;
                                end;
                        if not whether[map[maxx,j],ch] and (map[maxx,j]<>ch) then
                                begin
                                inc(degree[map[maxx,j]]);
                                whether[map[maxx,j],ch]:=true;
                                end;
                        end;
                end;
        end;
total:=0;
for ch:='A' to 'Z' do if have[ch] then inc(total);
end;

PROCEDURE Topu;
var
        i,j                     :Char;
begin
for i:='A' to 'Z' do
        if have[i] then
        begin
        for j:='A' to 'Z' do
                if have[j] then
                        begin
                        write(ord(whether[i,j]));
                        end;
                writeln;
        end;
end;

PROCEDURE Search;
var
        ch,ph                                   :Char;
begin
if length(s)=total then
        begin
        writeln(s);
        exit;
        end;
for ch:='A' to 'Z' do
        if (have[ch])and(pos(ch,s)=0)and(degree[ch]=0) then
                begin
                s:=s+ch;
                for ph:='A' to 'Z' do
                        if (have[ph])and(pos(ph,s)=0)and(whether[ph,ch]) then
                                dec(degree[ph]);
                search;
                delete(s,length(s),1);
                for ph:='A' to 'Z' do
                        if (have[ph])and(pos(ph,s)=0)and(whether[ph,ch]) then
                                inc(degree[ph]);
                end;
end;

BEGIN
assign(input,'frameup.in');
reset(input);
assign(output,'frameup.out');
rewrite(output);
while not eof do
        begin
        read(h);
        readln(w);
        for i:=1 to h do
                begin
                for j:=1 to w do read(map[i,j]);
                readln;
                end;
        determine;
//        topu;
        s:='';
        search;
        end;
close(input);
close(output);
END.