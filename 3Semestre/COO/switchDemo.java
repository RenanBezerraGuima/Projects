 import java.util.Scanner;// Importa a classe Scanner

public class switchDemo{

    public static int getMonthNumber(String month){
        int monthNumber = 0;

        if (month == null) 
        {
            return monthNumber;
        }

        switch (month.toLowerCase())
        {
            case "january":
                monthNumber = 1;
                break;
            case "february":
                monthNumber = 2;
                break;
            case "march":
                monthNumber = 3;
                break;
            case "april":
                monthNumber = 4;
                break;
            case "may":
                monthNumber = 5;
                break;
            case "june":
                monthNumber = 6;
                break;
            case "july":
                monthNumber = 7;
                break;
            case "august":
                monthNumber = 8;
                break;
            case "september":
                monthNumber = 9;
                break;
            case "october":
                monthNumber = 10;
                break;
            case "november":
                monthNumber = 11;
                break;
            case "december":
                monthNumber = 12;
                break;
            default:
                monthNumber = 0;
                break;
        }
        return monthNumber;
    }

    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in); // Cria um objeto da classe scanner
        System.out.println("Entre com o nome em inglês de um mês:"); //Printf 
        String month = myObj.nextLine(); // Lê o input do usuario em string
        System.out.println("O número do mês é: " + getMonthNumber(month));
    }
}