# About
MKZ4にESP32カメラを接続し、カメラの画像を見ながらラジコン操作ができるプロジェクトです。
M5 cameraXにて動作確認をしています。他のデバイスを使う場合はCameraWebServer.ino内で対象のカメラモデルを選択してください。
MKZ4との接続は以下の通りです。またCervoブログの記事も参照してみてください。（制作的なことはざっとしか書いてないです。すみません。）

## Important Note
- 電源スイッチを入れるときにEP32とUART端子が接続されているとMKZ4基板が起動しない（LEDが点灯しない）ため、UART端子を外してから電源スイッチを入れ、それからUART端子を再度接続するようにしてください。
- Arduino環境でArduino-ESP32をセットアップする場合、package_esp32_index.jsonのダウンロード先に注意してください。古い資料だと以下のURLになっていますが、ESP32 Arduino v1.0.6以降更新されていないようです。
`https://dl.espressif.com/dl/package_esp32_index.json`
Espressifのドキュメンテーションにあるとおり、以下のURLを設定する必要があります。
`https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html`
古いindex.jsonのURLが入っているとArduino-ESP32のバージョンがアップデートされず、ビルド出来なくなります。

## Build
- [Arduino-ESP32環境](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)をセットアップ
- WIFIAP_ENABLEDを有効にしていると（デフォルト）espcamのWiFiアクセスポイントが立ちあがります。自分のWiFiにつなぎたい場合はWIFIAP_ENABLEDを無効にしたうえでssid, passwordを入力してください。
- Tools > Board > ESP32 Wrover Moduleを選択
- Verify、Upload
- 追加ライブラリは特に必要ありません。
