class ParsePost {//вычисление постфиксного выражения
    private StackInt theStack;
    private String input;

    public ParsePost(String s) {
        input = s;
    }

    public int doParse() {
        theStack = new StackInt(20); // Создание объекта стека
        char ch;
        int j;
        int num1 = 0, num2, interAns;
        for(j = 0; j < input.length(); j++) { // Для каждого символа
            ch = input.charAt(j); // Чтение символа
            //theStack.displayStack(ch + " "); // *диагностика*
            if(ch >= '0' && ch <= '9') // Если это цифра
                theStack.push( (ch-'0') ); // Занести в стек
            else  { // Если это оператор
                num2 = theStack.pop(); // Извлечение операндов
                if(!theStack.isEmpty())
                    num1 = theStack.pop();
                switch(ch) // Выполнение арифметической
                { // операции
                    case '+':
                        if (num1 + num2 > 0)
                            interAns = 1;
                        else
                            interAns = 0;
                        break;
                    case '!':
                        if (num2 == 0)
                            interAns = 1;
                        else
                            interAns = 0;
                        break;
                    case '*':
                        if (num1 * num2 != 0)
                            interAns = 1;
                        else
                            interAns = 0;
                        break;
                    default:
                        interAns = 0;
                }
                // Занесение промежуточного
                // результата в стек
                theStack.push(interAns);
            }
        }
        interAns = theStack.pop(); // Получение результата
        return interAns;
    }
}