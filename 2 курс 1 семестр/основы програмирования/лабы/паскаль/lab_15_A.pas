program lab_15_A;
const M = 2;
      N = 3;
type t_base = real;
     t_arr = array[1..N] of t_base;
     t_matr = array[1..M] of t_arr;
     pt_matr = ^t_matr;
     
procedure read_matr(var a: pt_matr);
  var i, j : integer;
  begin
    for i:=1 to m do begin
      for j:=1 to n do
        read(a^[i][j]);
      writeln();
    end;
  end;

function max_s (a: pt_matr):integer;
  var i,j,k:integer;
      max:real;
  begin
    k:=1;
    max:=a^[1][1];
    for i:=1 to m do begin
      for j:=1 to n do begin
        if a^[i][j]>max then begin
          max:=a^[i][j];
          k:=i;
        end;
      end;
    end;
    max_s:=k;
  end;

function min_s (a: pt_matr):integer;
var i,j,k:integer;
      min:real;
  begin
    k:=1;
    min:=a^[1][1];
    for i:=1 to m do begin
      for j:=1 to n do begin
        if a^[i][j]<=min then begin
          min:=a^[i][j];
          k:=i;
        end;
      end;
    end;
    min_s:=k;
  end;

function skal (a: pt_matr; min,max:integer):real;
  var sum :real;
      i:integer;
  begin
    sum:=0;
    for i:=1 to n do
      sum:=sum+a^[min][i]*a^[max][i];
    skal:=sum;
  end;

var min,max,i,j:integer;
    a: pt_matr;
    pow:real;
begin
    new(a);
    read_matr(a);
    max:=max_s(a);
    min:=min_s(a);
    pow:=skal(a,min,max);
    write(pow:4:4);
    dispose(a);
  readln();
end.
