type t_file=file of integer;
procedure write_f(fname:string);
  var i,n,q:integer;
      f:t_file;
  begin
    read(n);
    assign(f,fname);
    reset(f);
    for i:=1 to n do begin 
      read(q);
      write(f,q);
    end;
    close(f);
  end;
  
var fname:string;
begin 
  readln(fname);
  write_f(fname);
end.