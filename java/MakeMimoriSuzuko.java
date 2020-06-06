import num2_.num2kansu;
import num2_.num2mori;
import num2_.num2suzuko;

public class MakeMimoriSuzuko{
    private String kansu;
    private String mori;
    private String suzuko;

    num2kansu num2kansu = new num2kansu();
    num2mori num2mori = new num2mori();
    num2suzuko num2suzuko = new num2suzuko();
    
    MakeMimoriSuzuko(){
        // System.out.println("Constractor: MakeMimoriSuzuko");
    }

    public String make(int num){
        kansu  = num2kansu.num2(num);
        mori   = num2mori.num2(num);
        suzuko = num2suzuko.num2(num);

        return kansu + mori + suzuko;
    }
}