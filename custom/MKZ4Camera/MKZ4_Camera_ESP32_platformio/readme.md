# About
MKZ4にESP32カメラを接続し、カメラの画像を見ながらラジコン操作ができるプロジェクトです。
M5 cameraXにて動作確認をしています。他のデバイスを使う場合はCameraWebServer.ino内で対象のカメラモデルを選択してください。
MKZ4との接続は以下の通りです。またCervoブログの記事も参照してみてください。（制作的なことはざっとしか書いてないです。すみません。）

## Important Note
- 電源スイッチを入れるときにEP32とUART端子が接続されているとMKZ4基板が起動しない（LEDが点灯しない）ため、UART端子を外してから電源スイッチを入れ、それからUART端子を再度接続するようにしてください。

## Build
- VSCodeからPlatformioをインストールしてください。
- PlatformIO: Buildでビルド
- PlatformIO: Upload
- 追加ライブラリは特に必要ありません。
