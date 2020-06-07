package num2_;
import java.text.Normalizer;
public class num2suzuko extends num2_{
    private int num;
    private String hiragana;
    private String hiragana_daku;
    private String suzuko;
    
    public num2suzuko(){
        // System.out.println("Constractor: num2suzuko");
    }

    public String num2(int argnum){
        num = (argnum+9)%46 ;
        hiragana = getTable().getHiragana(num);
        hiragana_daku = Normalizer.normalize(hiragana + "\u3099", Normalizer.Form.NFC);  // Unicode正規化: NFC

        suzuko = hiragana + hiragana_daku + "こ" ;

        return suzuko;
    }

}