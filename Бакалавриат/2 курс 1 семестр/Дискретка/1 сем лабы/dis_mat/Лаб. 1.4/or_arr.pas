Unit or_arr;

interface
const maxlen = 7;
  
type t_arr = array [1..maxlen] of byte;

procedure input(var x:t_arr; k:byte);
function sort_arr (x: t_arr; k: byte):Boolean;
procedure output (x: t_arr; k: byte);
function check_a_b (a, b: t_arr; n, m: byte): boolean;
function inclusion (a, b: t_arr; n, m:byte): boolean;
function equality (a, b: t_arr; n, m: byte): boolean;
function strict_inclusion (a, b: t_arr; n, m: byte): boolean;
function unification (a, b: t_arr; n, m: byte; var c: t_arr): byte;
function intersection (a, b: t_arr; n, m: byte; var c: t_arr): byte;
function difference (a, b: t_arr; n, m: byte; var c: t_arr): byte;
function symmetric_difference (a, b: t_arr; n, m: byte; var c: t_arr): byte;
function complement (a: t_arr; n: byte; var c: t_arr): byte;



implementation

procedure input;
  var i: byte;
  begin
    for i:=1 to k do
      read(x[i]);
  end;

function sort_arr: boolean;
  var j: byte;
  begin
    j:=2;
    while (j<=k) and (x[j]>x[j-1]) do 
      inc(j);
    sort_arr:=j>k;
  end;

procedure output;
  var i: byte;
  begin
    for i:=1 to k do 
      write(x[i], ' ');
  end;

function check_a_b: boolean;
  var i, j: byte;
  begin
    i:=1;
    j:=1;
    while (i<=n) and (j<=m)  do
      if a[i]=b[j] then
      begin
        inc(i);
        inc(j);
      end
      else inc(j);
    check_a_b:=i>n
  end;

function inclusion: boolean;
  begin
    inclusion:=(n<=m) and check_a_b(a, b, n, m);
  end;

function equality: boolean;
var i: byte;
    f: boolean;
begin
  i:=1;
  f:=n=m;
  while (i<=n)and(f) do
    begin
      f:=a[i]=b[i];
      inc(i);
    end;
  equality:=f;
end;

function strict_inclusion: boolean;
  begin
    strict_inclusion:=(n<m) and check_a_b(a, b, n, m);
  end;

function unification: byte;
  var i, k, j: byte;
  begin
    i:=1; 
    j:=1;
    k:=0;
    while (i<=n) and (j<=m) do
      begin
        inc(k);
        if a[i]=b[j] then 
          begin
            c[k]:=a[i];
            inc(i); 
            inc(j);
          end
        else 
          if a[i] > b[j] then
            begin
              c[k]:=b[j];
              inc(j);
            end
          else
            begin
              c[k]:=a[i]; 
              inc(i);
            end;
      end;
    while (i <= n) do
       begin
         inc(k);
         c[k] := a[i];
         inc(i);
       end;
    while (j <= m) do
       begin
         inc(k);
         c[k] := b[j];
         inc(j);
       end;
    unification:=k;
  end;

function intersection: byte;
  var i, j, k: byte;
  begin
    i:=1;
    j:=1;
    k:=0;
    while (i<=n) and (j<=m) do
      if a[i]=b[j] then
        begin
          inc(k);
          c[k]:=a[i];
          inc(i);
          inc(j);
        end
      else
        if a[i]>b[j] then
          inc(j)
        else 
          inc(i);
    intersection:=k;
  end;

function difference: byte;
  var i, j, k:byte;
  begin
    i:=1;
    j:=1;
    k:=0;
    while (i<=n) and (j<=m) do
      if a[i] = b[j] then
        begin
          inc(j);
          inc(i);
        end
      else 
        if a[i]>b[j] then
          inc(j)
        else
          begin
            inc(k);
            c[k]:=a[i];
            inc(i); 
          end;
      while i<=n do
        begin
          inc(k);
          c[k]:= a[i];
          inc(i);
        end;
    difference:=k;
  end;

function symmetric_difference: byte;
  var i, j, k, f, l:byte;
  begin
    i:=1; 
    j:=1;
    k:=1;
    while (i<=n) and (j<=m) do
      if a[i] = b[j] then
        begin
          inc(i);
          inc(j);
        end
      else 
        if a[i]>b[j] then
          begin
            c[k]:=b[j];
            inc(k); 
            inc(j);
          end
        else
          begin
          c[k]:=a[i];
          inc(k);
          inc(i);
        end;
    if i<=n then
      for f:=i to n do
        begin
          c[k]:=a[f];
          inc(k);
        end;
    if j<=m then 
      for l:=j to m do
        begin
          c[k]:=b[l];
          inc(k);
        end;
  symmetric_difference:=k;
end;

function complement: byte; 
  var k, i, j: byte;
  begin
    k := 0;
    i := 1;
    j := 1;
    while i <= n do
      if j = a[i] then
        begin
          inc(i);
          inc(j);
        end
   	else 
        if j > a[i] then
          inc(i)
   	else
      begin
        inc(k);
        c[k] := j;
        inc(j);
      end;
    while j <= 10 do
      begin
        inc(k);
        c[k]:= j;
        inc(j);
      end;
    complement:= k;
  end;
end.