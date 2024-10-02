program z_6;
  uses or_arr;
  
  var a, b, c, x, d, e, f, g: t_arr;
      n, m, k, j, y, z, w, h: byte;
      
  begin
    writeln ('Введите количество элементов множества A');
    read (n);
    writeln ('Введите элементы множества А');
    input (a, n);
    writeln ('Введите количество элементов множества B');
    read (m);
    writeln ('Введите элементы множества B');
    input (b, m);
    writeln ('Введите количество элементов множества C');
    read (k);
    writeln ('Введите элементы множества C');
    input (c, k);
    writeln ('Введите количество элементов множества X');
    read (j);
    writeln ('Введите элементы множества X');
    input (x, j);
    y := intersection (a, x, n, j, d);
    z := unification (d, b, y, m, e);
    y := difference (c, x, k, j, d);
    w := intersection (e, d, z, y, f);
    y := difference (a, x, n, j, d);
    z := intersection (d, c, y, k, e);
    h := complement (x, j, g);
    y := unification (g, e, h, z, d);
    if equality(f, d, w, y) then
      writeln('Решение верно')
    else
      writeln('Решение не верно');
  end.