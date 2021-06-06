# TKOH - Gym 項目

為了驗證一些關於布林類神經網路以及基因演算法的假設，必須將該演算法置於增強式學習訓練環境進行迭代以評估演算法效益，訓練環境使用 [gym](https://gym.openai.com/) ，以 python 撰寫，但是為了兼顧運算效能以及撰寫經驗，關鍵演算法我想透過 c++ 實現，所以需要透過 IPC( Inter-process communication ) 達成兩者之間的溝通，暫時選定使用 ZeroMQ 達成程式之間的溝通。

## 子系統

### Hakoniwa 

日語「箱庭」的拼音，是真正執行 py-gym 的系統。

> 日本人概念中的箱庭更強調「微縮景觀」和「精緻的玩具」這兩條，一定要有一種玩具感。你用玻璃做個箱子，裡面放沙子、石頭、植物、營造出好像小庭院的感覺，然後裡面養小動物，這就是箱庭了。它是對自然的模仿，但是必須一眼就能看出是假的，如果你覺得像真的，那就錯了。
> 美國人的沙箱則完全是衝著還原現實世界去的，與日本人的思路180度相反。[^Hakoniwa]

### Primordial Soup

基因庫伺服器，用於生成和變異染色體的資料庫伺服器。 Hakoniwa 雖然會有 policy 的索引資料，但是染色體實際上是被儲存在這裡。項目命名源自米勒-尤里實驗（Miller-Urey experiment) 對地球早期狀態與生命起源假設的「太古濃湯」。

### Monkey

用來生成 BNN 的程式單元，啟動後實際上作為 RL 中的 Agent ，與 Hakoniwa 之間使用 IPC 通訊。項目命名源自 "Infinite monkey theorem"。

## [綜合工具包 (BNN Tools)](./BNN_Tools/README.md)

創造、修改、編碼、解碼和觀察染色體的基本工具包，並且將功能拆分成數個可單獨執行的程式供執行機器學習演算法的程式調用。

## 雜項

- [2020-03-22 圖形編碼傳輸測試](./Test_of_Image_Transfer_with_Different_Decode/README.md)

