package num2_;
public class num2mori extends num2_{
    private String mori = "";
    private int num_mori=0,num_hayashi=0;

    public num2mori(){
        // System.out.println("Constractor: num2mori");
    }

    public String num2(int num){
        if(num==0) return mori;
        else if(num == 1) return "木";

        num_mori = num/3;
        num = num%3;

        if(num==1){
            num_mori --;
            num_hayashi = 2;
        }else if(num==2){
            num_hayashi  = 1;
        }

        for(int i=0; i<num_mori; i++) mori += "森";
        for(int i=0; i<num_hayashi; i++) mori += "林";

        return mori;
    }
}