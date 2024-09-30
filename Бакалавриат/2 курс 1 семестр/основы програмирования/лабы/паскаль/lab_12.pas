program lab_12;

type t_file=file of integer;

procedure write_f(fname:string);
  var w:integer;
      f:t_file;
  begin
    assign(f,fname);
    reset(f);
    while not eof (f) do begin
       read(f,w);
       write(w,' ');
    end;
    writeln;
    close(f);
  end;
  
function get_min(var f:t_file; var i:integer):integer;
  var min,q,imin:integer;
  begin
    min:=100;
    imin:=i-1;
    seek(f,i);
    q:=1;
    while (not eof(f)) and (q<>0)do begin 
      read(f,q);
      if (q<min)and(q<>0) then begin
        min:=q;
        imin:=i;
      end;
      inc(i);
    end;
   
    if q<>0 then 
      i:=i+1;
    get_min:=imin;
  end;

procedure del (var f:t_file; index,m:integer);
  var i,len,q,pos:integer;
  begin
    pos:=filepos(f);
    len:=filesize(f);
    for i:=index to len-m-1 do begin 
    write('s ');
      seek(f,i+m);
      read(f,q);
      seek(f,i);
      write(f,q);
    end;
    seek(f,len-m);
    truncate(f);
    seek(f,pos-m);
    writeln();
  end;
  
procedure del_el(fname:string);
  var i,imin:integer;
      f:t_file;
  begin
    assign(f,fname);
    reset(f); 
    i:=0;
    while not eof (f) do begin
      imin:=get_min(f,i);
      del(f,imin,i-imin-1);
      i:=imin+1;
    end;
    close(f);
  end;

  
var fname:string;
begin
  read(fname);
  write_f(fname);
  del_el(fname);
  write_f(fname)
end.