# About
MKZ4にESP32カメラを接続し、カメラの画像を見ながらラジコン操作ができるプロジェクトです。
M5 cameraXにて動作確認をしています。他のデバイスを使う場合はCameraWebServer.ino内で対象のカメラモデルを選択してください。

MKZ4との接続は以下の通りです。また[Cervoブログの記事](https://tech-blog.cerevo.com/)も参照してみてください。（制作的なことはざっくりとしか書いていないです。すみません。）

![Office Circuit](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/OfficeRace.gif)

![View from above](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/Above.jpg)

## System
![System](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/System.png)

## Important Note
- 電源スイッチを入れるときにEP32とUART端子が接続されているとMKZ4基板が起動しない（LEDが点灯しない）ため、UART端子を外してから電源スイッチを入れ、それからUART端子を再度接続するようにしてください。
- Arduino環境でArduino-ESP32をセットアップする場合、package_esp32_index.jsonのダウンロード先に注意してください。古い資料だと以下のURLになっていますが、ESP32 Arduino v1.0.6以降更新されていないようです。
`https://dl.espressif.com/dl/package_esp32_index.json`
Espressifのドキュメンテーションにあるとおり、以下のURLを設定する必要があります。
`https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html`
古いindex.jsonのURLが入っているとArduino-ESP32のバージョンがアップデートされず、ビルド出来なくなります。

## Building Project
- MKZ4(ESP8266)のプロジェクト（Cerevo_MKZ4_UARTまたはCerevo_MKZ4_UART_platformio）をビルドする。
- ESP32カメラのプロジェクトをビルドする（CameraWebServerまたはMKZ4_Camera_ESP32_platformio)
- ビルド方法はそれぞれのフォルダ内のReadme参照

## Wiring
ESP32カメラ（Grobeコネクタ）とMKZ4を以下のように接続します。
| ESP32カメラ(Grobe)   | MKZ4  |
| ------------------- |-------|
| Pin1(Yellow)        | TDX   |
| Pin2(White)         | RDX   |
| Pin3(Black)         | GND   |
| Pin4(Red)           | Batt+ |

![Top](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/Top.jpg)
![Wiring](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/Wiring.jpg)


## セットアップ起動手順
- 上記Wiringを済ませ配線したらMKZ4側のUART端子を外しておく
- 電池ボックスの電源を入れる
- MKZ4基板上のLED点灯を確認する。
- UART端子を接続
- AP接続の場合mkz4camというWiFiアクセスポイントがスマートフォンから見えるはずなので接続する。PW不要、インターネットに接続されていないと警告が出るかもしれませんが無視します。
- Webブラウザを立ち上げ、**192.168.4.1** と入力すると操作画面が見えます。
- Settingsタブを開き、一番下のStartStreamボタンを押すとESP32Cameraの画像が見えます。
- 画面下部の十字エリア中心部をタッチし（指を離さないまま）上の方にスライドします。MKZ4のモーターが回りましたか？
- 同様に左右方向に指をスライドさせるとステアリングが動きます。
- 下方向にスライドさせるとモーターが反転して回ります。
![From Ipad](https://raw.githubusercontent.com/cerevo/MKZ4/master/Pics/ControlFromIpad.gif)


## 技術情報
[M5 cameraX pinout](https://docs.m5stack.com/en/unit/m5camera_x)

今回参照したカメラウェブサーバのサンプルです。ESP32版もあります。
[Official CameraWebServer.ino sample](https://github.com/espressif/arduino-esp32/tree/master/libraries/ESP32/examples/Camera/CameraWebServer)

[ESP-IDFでのWebsocket実装情報](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_http_server.html#websocket-server)
