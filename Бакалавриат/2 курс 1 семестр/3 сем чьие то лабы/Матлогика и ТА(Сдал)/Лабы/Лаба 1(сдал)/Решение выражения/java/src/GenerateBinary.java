import java.io.IOException;
import java.util.Scanner;

class GenerateBinary {
    private static int[] arr;
    private static String str;
    private static int n;

    public GenerateBinary(String in) throws IOException {
        str = in;
        System.out.print("Input n = ");
        n = getInt();
        arr = new int[n];

    }

    public void rec(int i){
        for (int x = 0; x <= 1; x++) {


            if (i == (n)) {
                test(arr);
                break;
            } else
                {
                    arr[i] = x;
                    rec(i + 1);
                }
        }
    }

    public static void test(int[] arr){
        /*Заменяем буквы цифрами*/
        String out = new String();
        out = str;
        int k = 0;
        char c = 0, ch = 0;
        for (int i = 0; i < out.length(); i++) {
            String path = new String();
            c = out.charAt(i);
            if ( c >= 'A' && c <= 'Z') {
                String a = Integer.toString(arr[k++]);
                for (int j = 0; j < out.length(); j++) {
                    ch = out.charAt(j);
                    if ( c == ch)
                        path += a;
                    else
                        path += ch;

                }
                out = path;
            }
        }


        /*Решаем уравнение*/
        ParsePost aParser = new ParsePost(out);
        int output = aParser.doParse();

        for (int i = 0; i < n; i++) {
            System.out.print(' ');
            System.out.print(arr[i]);
        }
        System.out.println("= " + output);

    }

    public static int getInt() throws IOException {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        return a;
    }

}