program lab_11;
   
procedure new_f (name:string);
  var s,n:string;
      i, kol:integer;
      mn:set of char;
      f,g:text;
  begin
    assign(f, name);
    reset(f);
    readln(f,n);
    close(f);
    kol:= length(n);
    s:='';
    mn:=[];
    for i:=kol downto 1 do begin
      if not (n[i] in mn) then begin
        mn:=mn+[n[i]];
        s:=s+n[i];
      end;
    end;
    assign(f, name);
    rewrite(f);
    writeln(f,s);
    close(f);
  end;
    
var name:string; 
begin
  read(name);
  new_f(name);
end.
     