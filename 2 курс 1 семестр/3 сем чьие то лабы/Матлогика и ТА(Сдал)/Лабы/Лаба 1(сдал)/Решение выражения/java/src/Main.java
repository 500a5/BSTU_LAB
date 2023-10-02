import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {

    public static void main(String[] args) throws IOException {
        String input;
        int output;
        while(true) {
            System.out.print("Enter infix: ");
            System.out.flush();
            input = getString(); // Ввод строки с клавиатуры
            if( input.equals("") ) // Завершение, если нажата клавиша
                break; // [Enter]
            // Создание объекта-преобразователя
            InToPost theTrans = new InToPost(input);
            input = theTrans.doTrans(); // Преобразование
            System.out.println("Postfix: " + input);
            GenerateBinary end = new GenerateBinary(input);
            end.rec(0);

        }



    }

    public static String getString() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        return s;
    }

}
