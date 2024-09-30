//модуль, реализующий метод Гауса MethodGaus.java
public class MethodGaus {

    public static double[] SLAE(Matr matr){
        Matr a = new Matr(matr.getStr(),matr.getTab());
        MathOfMatr.copy(matr, a);
        double vect[] = new double[matr.getStr()];
        double m,t;
        int k,j,i;
        for (k = 1; k < a.getStr(); k++) { //прямой ход
            for (j = k; j < a.getStr(); j++) {
                m = a.get(j, k - 1) / a.get(k -1, k - 1);
                for (i = 0; i < a.getTab(); i++) {
                    t = a.get(j, i) - (m * a.get(k - 1, i));
                    a.set(j, i, t);
                }
            }
        }
        for (i = a.getStr() - 1; i >=  0; i--) {//обратный ход
            vect[i] = a.get(i,a.getStr()) / a.get(i,i);
            for (j = a.getStr() - 1; j > i ; j--)
                vect[i] = vect[i] - a.get(i,j) * vect[j] / a.get(i,i);
        }
        return vect;
    }//решение системы линейных уравнений методом гауса

    public static Matr toTriangularMatrices(Matr matr) {
        Matr a = new Matr(matr.getStr(),matr.getTab());
        MathOfMatr.copy(matr,a);
        double m,t;
        int k,j,i;
        for (k = 1; k < a.getStr(); k++) {
            for (j = k; j < a.getStr(); j++) {
                m = a.get(j, k - 1) / a.get(k -1, k - 1);
                for (i = 0; i < a.getTab(); i++) {
                    t = a.get(j, i) - (m * a.get(k - 1, i));
                    a.set(j, i, t);
                }
            }
        }
        return a;
    }// приведение матрицы к тругольному виду методом гауса

    public static double determinant(Matr a){
        double res = 1;
        Matr matr = toTriangularMatrices(a);
        for (int i = 0; i < a.getStr(); i++)
            res *= matr.get(i,i);
        return res;
    }//нахождение определителя матрицы любого порядка

    public static Matr getUnitMatrix(int n){
        Matr unit = new Matr(n,n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (i == j)
                    unit.set(i,j,1);
                else
                    unit.set(i,j,0);
        }
        return unit;
    }//создание единичной матрицы нужного порядка
}
