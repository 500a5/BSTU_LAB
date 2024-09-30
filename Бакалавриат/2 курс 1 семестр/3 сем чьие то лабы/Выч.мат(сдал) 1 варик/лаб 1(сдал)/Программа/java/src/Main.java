public class Main {
    public static void main(String[] args) {
        Matr matr = new Matr(3, 4);
        matr.input();
        double rez[] =  MethodGaus.SLAE(matr);
        for (int i = 0; i < matr.getTab() - 1; i++) {
            System.out.println(rez[i] + " ");
        }
    }
}
