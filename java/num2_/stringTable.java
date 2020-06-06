package num2_;

public class stringTable{

    private final String hiragana 	= "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん"; 
	private final String kansu 		= "零一二三四五六七八九";
	private final String kanji 		= "木林森";
	
	public String getHiragana(int num){return hiragana.substring(num,num+1);}	//0:あ ...
	public String getKansu(int num){return kansu.substring(num,num+1);}			//0~9の整数を漢字に
	public String getKanji(int num){return kansu.substring(num-1,num);} 		//1:木 2:林 3:森
}