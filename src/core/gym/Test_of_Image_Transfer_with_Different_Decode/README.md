# 圖形編碼傳輸測試

- 實驗日期
  - 2020-03-22
- 實驗內容
  - 同樣使用 opencv 的函式庫，但是控制變因如下：
    1. 直接傳輸 bitmap，並建立 cv::Mat
    2. 傳輸 png 再解碼建立 cv::Mat

## 實驗結果

```
Connecting to opencv server with bitmap…
average time during:  0.0010088205337524414
Connecting to opencv server with png…
average time during:  0.008921647071838379
```

## 實驗結論

推測：
- 資料轉換成 `std::vector<char>` 與解碼的過程花費多餘的時間
- 測試發生在本地，網路傳輸的成本本來就比較低，在網路瓶頸的環境表現出的優劣可能會不太一樣

有一個討論串跟我的問題相同，並且在當中提到，png 編碼與解碼本身就會花費不少時間，資料傳輸方式的選擇還是要根據環境的硬體設備情況去做調整[^encode]。


[^encode]: https://answers.opencv.org/question/207286