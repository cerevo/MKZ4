

## Description

- Cerevo_MKZ4_CDS_V02 :本体にLEDとCDSを追加して、暗くなったら自動でLEDが点灯するサンプル。

- Cerevo_MKZ4_LED-light :本体にLEDを追加してPWMで点灯させるサンプル。  

- Cerevo_MKZ4_LED-light2 :本体にLEDライト（フロントのみを想定）追加して走行時明るく光らせるサンプル。

- Cerevo_MKZ4_calib :UARTからoffset,left,rightの値を修正できるコマンドを追加。

- milkcocoa_esp8266 ：milkcocoaを使うサンプル(ESP側）。  

- milkcocoa_javascript ：milkcocoaを使うサンプル(javascript側)。  

- MKZ4_example2 :スマートフォンの傾きでミニ四駆を操作するサンプル。  

- remote_led_switch_example :ブラウザからLEDをON/OFFするサンプル。  

- MKZ4_OriginalBody.stl :オリジナルボディの3DCADのデータ。  

---
### キャリブコマンドの使い方

#### 前準備

1. Cerevo_MKZ4_calib.inoを書きこむ
2. ESP8266とUARTで接続する(ボーレート:115200 , デリミタ:CR+LF)

#### コマンド

* offset角度修正コマンド:前進させた時に少し右や左に曲がってしまうのを修正する  

コマンド  
offset+space+角度[CR][LF]  

ex)  
offset 10[CR][LF] //10°右にずらす  
offset -20[CR][LF] //20°左にずらす   
  
* 左ステアリング角度修正コマンド:左に曲がる角度を修正する　デフォルト65°

コマンド  
left+space+角度[CR][LF]  

ex)  
left 60[CR][LF] //左ステアリング角度を浅くする場合  
left 70[CR][LF] //左ステアリング角度を深くする場合  
   
* 右ステアリング角度修正コマンド:右に曲がる角度を修正する　デフォルト110°  

コマンド  
right+space+角度[CR][LF]  

ex)  
right 105[CR][LF] //右ステアリング角度を浅くする場合   
right 115[CR][LF] //右ステアリング角度を深くする場合  
