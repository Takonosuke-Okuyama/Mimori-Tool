package num2_;
public class num2kansu extends num2_{
    private String kansu = "";
    private int digit1000;
    private int digit100;
    private int digit10;
    private int digit1;

    public num2kansu(){
        // System.out.println("Constractor: num2kansu");
    }
    
    public String num2(int num){    
        if(num==0)return getTable().getKansu(num);
    
        digit1000 = num/1000; 
        num = num%1000;

        digit100  = num/100;
        num = num%100; 

        digit10   = num/10;
        num = num%10;

        digit1    = num;

        if(digit1000==1) kansu += "千";
        else if(digit1000!=0)kansu += getTable().getKansu(digit1000) + "千";

        if(digit100 ==1) kansu += "百";
        else if(digit100 !=0)kansu += getTable().getKansu(digit100) + "百";

        if(digit10  ==1) kansu += "十";
        else if(digit10  !=0)kansu += getTable().getKansu(digit10) + "十";

        if(digit1   !=0)kansu += getTable().getKansu(digit1);

        return kansu;
    }
}