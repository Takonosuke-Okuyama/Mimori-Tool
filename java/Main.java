import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        String name;
        int num = scanNum();

        MakeMimoriSuzuko mimorisuzuko = new MakeMimoriSuzuko();
        name = mimorisuzuko.make(num);

        System.out.println(name);
    }

    static int scanNum(){
        Scanner scanner = new Scanner(System.in);
        String input;
        int num = -1;

        while(true){
            System.out.print("何森?: ");
            input = scanner.nextLine();

            try{
                num = Integer.parseInt(input);
            }catch(NumberFormatException e){
                System.out.println("入力は 0~1000 の整数\n");
                continue ;
            }

            if(num < 0 || 1000 < num){
                System.out.println("入力は 0~1000 の整数\n");
                continue ;
            }

            scanner.close();
            break;
        }

        return num;
    }
}


// コンパイル方法
//     javaディレクトリ内で　javac -classpath .:num2_ Main.java
//     再度コンパイル時は    rm *class;cd num2_/;rm *class;cd ..;javac -classpath .:num2_ Main.java

// 実行方法
//     java Main
