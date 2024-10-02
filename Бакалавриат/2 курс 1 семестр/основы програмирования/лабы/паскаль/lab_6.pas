program lab_6;

function get_word (s:string; var i:integer ):string;
  var w:string;
  begin 
    while (i<=length(s)) and (s[i]<=' ') do
      i:=i+1;
    w:='';
    while (i<=length(s)) and (s[i]>' ') do begin 
      w:=w+s[i];
      i:=i+1;
    end;
    get_word:=w;
  end;

function swaps(s:string ):string;
  var m,g:string;
      i:integer;
  begin
    i:=1;
    m:='';
    while i<length(s) do begin
      g:=get_word(s,i);
      if (g='this') then 
        m:=m+'the'+' '
      else
        m:=m+g+' ';
    end;
    swaps:=m;
  end;

var s:string;
begin
  readln(s);
  s:=swaps(s);
  writeln(s);
  
end.