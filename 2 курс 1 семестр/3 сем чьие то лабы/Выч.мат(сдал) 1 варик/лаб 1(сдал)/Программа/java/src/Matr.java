import java.util.Scanner;

public class Matr {
    private double a[][];
    private int str;
    private int tab;

    Matr (int str, int tab){
        this.str = str;
        this.tab = tab;
        a = new double[str][tab];
    }

    public void input() {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < str; i++)
            for (int j = 0; j < tab; j++)
                a[i][j] = in.nextDouble();
    }//ввод матрицы

    public void output() {
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < tab; j++)
                System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }//вывод матрицы

    public double get(int i, int j) {
        return a[i][j];
    }//взятие элемента

    public void set(int i, int j, double value) {
        a[i][j] = value;
    }//изменения элемента

    public int getStr() {
        return str;
    }//количество строк

    public int getTab() {
        return tab;
    }//количество столбцов
}