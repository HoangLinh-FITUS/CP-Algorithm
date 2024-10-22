uses crt;
var n:longint;
begin
clrscr;
randomize;
       n:=random(2);
       if n = 1 then writeln('YES') else
       writeln('NO');
readln;
end.