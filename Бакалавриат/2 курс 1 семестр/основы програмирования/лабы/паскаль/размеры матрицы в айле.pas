program zzzzzzz;
var f:text;i,n,m:integer;
begin
  assign(f,'t.txt');
  reset(f);
  i:=0;
  while not eof(f) do begin
    readln(f,i);
    inc(n);
  end;
reset(f);
while not SeekEoln(f) do begin
  read(f,i);
  inc(m);
end;
close(f);
write(m,' ',n);
end.