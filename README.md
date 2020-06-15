# Mimori-Tool
三森すずこ変換ツールです.

## 使い方
実行すると
```
何森?:
```
と聞かれますので, 作りたい三森すずこの数値(0~1000)を入力してください.
```
何森?: 3
```
結果が表示されます.
```
何森?: 3
三森すずこ
```
```
何森?: 4
四林林せぜこ
```

## LINEBot
LINEBotになりました.  
ID: `@664dxnan`  
QR:  
<img src="https://github.com/Masaki-Okuyama/Mimori-Tool/blob/images/LINEQR.png" alt="drawing" width="200"/>

## C
### コンパイル
cフォルダの`mimori-tool.c`か`mimori-tool2.c`をgccでコンパイルしてください.
### 無印と2の違い
出力結果は同じですが, 実装方法が違います.

## Python
`MimoriTool.cpython-37m-darwin.so`は三森すずこ生成ライブラリです. `main.py`で使用しています.
## docker
dockerイメージになりました.
- c言語版: ```docker run -it --rm watanabesota/mimori-tool-c```
- Python版: ```docker run -it --rm watanabesota/mimori-tool-python```
- Java版: ```docker run -it --rm watanabesota/mimori-tool-java```
