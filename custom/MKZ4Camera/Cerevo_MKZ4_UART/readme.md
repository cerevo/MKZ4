# Cerevo MKZ4 controller with UART
こちらのスケッチはMKZ4をESP32カメラから操作するためのものです。このプログラムはUART経由で制御が可能です。

## Important Note
電源スイッチを入れるときにUART端子が接続されているとMKZ4基板が起動しない（LEDが点灯しない）ため、UART端子を外してから電源スイッチを入れ、それからUART端子を再度接続するようにしてください。

## How to build
オリジナルのMKZ4と同じくボードマネージャからESP8266を選択してVerifyしたあと、Uploadしてください。特に追加のライブラリは必要ありません。