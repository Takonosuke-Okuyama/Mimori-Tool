package num2_;
public class num2suzuko extends num2_{
    private int num;
    private String hiragana;
    private String suzuko;
    
    public num2suzuko(){
        // System.out.println("Constractor: num2suzuko");
    }

    public String num2(int argnum){
        num = argnum%46 + 9;
        hiragana = getTable().getHiragana(num);
        suzuko = hiragana + hiragana + "゛" + "こ";
        return suzuko;
    }
}