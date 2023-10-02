// Преобразование инфиксных арифметических выражений в постфиксные
import java.io.*; // Для ввода/вывода

class InToPost { // Преобразование инфиксной записи в постфиксную
    private StackChar theStack;
    private String input;
    private String output = "";

    public InToPost(String in) { // Конструктор
        input = in;
        int stackSize = input.length();
        theStack = new StackChar(stackSize);
    }

    public String doTrans() { // Преобразование в постфиксную форму
        for (int j = 0; j < input.length(); j++) {
            char ch = input.charAt(j);
            //theStack.displayStack("For " + ch + " "); // *диагностика*
            switch (ch) {
                case '+': // дизюнкция
                    gotOper(ch, 1); // Извлечение операторов
                    break; // (приоритет 1)
                case '*': // конъюнкция
                    gotOper(ch, 2); // Извлечение операторов
                    break; // (приоритет 2)
                case '!':
                    gotOper(ch, 3);
                    break;//(приоритет 3)

                case '(': // Открывающая круглая скобка
                    theStack.push(ch); // Занести в стек
                    break;
                case ')': // Закрывающая круглая скобка
                    gotParen(ch); // Извлечение операторов
                    break;
                default: // Остается операнд
                    output = output + ch; // Записать в выходную строку
                    break;
            }
        }
        while (!theStack.isEmpty()) { // Извлечение оставшихся операторов
            //theStack.displayStack("While "); // *диагностика*
            output = output + theStack.pop(); // write to output
        }
        //theStack.displayStack("End "); // *диагностика*
        return output; // Возвращение постфиксного выражения
    }

    public void gotOper(char opThis, int prec1) { // Чтение оператора из входной строки
        while (!theStack.isEmpty()) {
            char opTop = theStack.pop();
            //System.out.print((char) opTop);
            if (opTop == '(') { // Если это '('
                theStack.push(opTop); // Вернуть '('
                break;
            } else { // Оператор
                int prec2; // Приоритет нового оператора
                if (opTop == '+') // Определение приоритета
                    prec2 = 1;
                else if(opTop == '*')
                    prec2 = 2;
                else
                    prec2 = 3;

                if (prec2 < prec1) { //Если приоритет нового оператора меньше приоритета старого
                    theStack.push(opTop); // Сохранить новый оператор
                    break;
                } else // Приоритет нового оператора
                    output = output + opTop; // не меньше приоритета старого
            }
        }
        theStack.push(opThis); // Занесение в стек нового оператора
    }

    public void gotParen(char ch) { // Прочитана закрывающая скобка
        while (!theStack.isEmpty()) {
            char chx = theStack.pop();
            if (chx == '(') // Если извлечен элемент ‘(‘
                break; // Прервать выполнение
            else // Если извлечен оператор
                output = output + chx; // Вывести в постфиксную строку
        }
    }
}
