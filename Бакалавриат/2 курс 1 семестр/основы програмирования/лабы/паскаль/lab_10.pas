program lab_10;
type mn=set of char;

procedure read_mn(var m:mn);
  var s:string;
      i:integer;
   
  begin
    readln(s);
    i:=1;
    while (s[i]<>'.') do begin 
      if s[i] in ['A'..'Z'] then
        s[i]:=chr(ord(s[i])+32);
      m:=m+[s[i]];
      i:=i+1;
      end;
  end;

procedure new_mn(m:mn; var s_new:mn);
  var z:set of char;
  begin
    z:=['a'..'z'];
    s_new:=z-m;
    
  end;

procedure write_mn(m:mn);
  var i:char;
  begin
    for i:='a' to 'z' do
      if i in m then
        write(i,' ');
  end;

var s:set of char;
    s_new:set of char;
begin
  read_mn(s);
  new_mn(s,s_new);
  write_mn(s_new);
  writeln();
  readln();
end.
