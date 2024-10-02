public class MathOfMatr {

    public static void copy(Matr a, Matr b){
        for (int i = 0; i < a.getStr(); i++)
            for (int j = 0; j < a.getTab(); j++)
                b.set(i, j, a.get(i,j));
    } //копирование матрицы 1 в матрицу 2

    public static Matr multiplication(Matr a, Matr b){
        Matr res = new Matr(a.getStr(),a.getTab());
        int sum;
        for (int i = 0; i < a.getStr(); i++) {
            for (int j = 0; j < a.getTab(); j++) {
                sum = 0;
                for (int k = 0; k < b.getStr(); k++)
                    sum +=  a.get(i,k) * b.get(k,j);
                res.set(i,j,sum);
            }
        }
        return res;
    }//уможение

    public static Matr multiplicationOnNumb(Matr a, int value){
        Matr res = new Matr(a.getStr(),a.getTab());
        for (int i = 0; i < a.getStr(); i++)
            for (int j = 0; j < a.getTab(); j++)
                res.set(i, j, a.get(i,j) * value);
        return res;
    } //умножение на число

    public static Matr addition(Matr a, Matr b){
        Matr res = new Matr(a.getStr(),a.getTab());
        for (int i = 0; i < a.getStr(); i++)
            for (int j = 0; j < a.getTab(); j++)
                res.set(i, j, a.get(i,j) + b.get(i,j));
        return res;
    }//сложение

    public static Matr subtraction(Matr a, Matr b){
        Matr res = new Matr(a.getStr(),a.getTab());
        for (int i = 0; i < a.getStr(); i++)
            for (int j = 0; j < a.getTab(); j++)
                res.set(i, j, a.get(i,j) - b.get(i,j));
        return res;
    }//вычитание

    public static Matr Transposition(Matr a){
        Matr res = new Matr(a.getStr(),a.getTab());
        for (int i = 0; i < a.getStr(); i++) {
            for (int j = 0; j < a.getTab(); j++) {
                res.set(j, i, a.get(i,j));
            }
        }
        return res;
    }//транспонирование

    public static double[] multiplicationOnVector(Matr a, double vect[]){
        Matr matr = new Matr(a.getStr(),a.getTab());
        MathOfMatr.copy(a, matr);

        double res[] = new double[matr.getStr()];
        for (int i = 0; i < matr.getStr(); i++) {
            res[i] = 0;
            for (int j = 0; j < matr.getTab(); j++)
                res[i] += matr.get(i,j) * vect[j];
        }
        return res;
    }//умножение на вектор
}