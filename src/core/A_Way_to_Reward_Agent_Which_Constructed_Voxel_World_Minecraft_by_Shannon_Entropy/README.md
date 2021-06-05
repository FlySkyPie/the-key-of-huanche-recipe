# 一種利用資訊熵獎勵智能體構建方塊世界(Minecraft)的方法

## 評價資源

我們能夠直觀的以資源的稀有程度去抽象的衡量資源的價值；越稀有的資源越有價值，反之亦然。但是經濟學上的價值是透過供需市場產生的，並不能作為有明確定義的綱量。我們能獲得的是資源生成在地圖上的機率，但是僅有資源機率並不能夠適當直接作為 agent 的評價手段，需要一些額外的處理。

### 夏農熵與夏農資訊 (Shannon Entropy and Information)

夏農熵本質上是對我們司空見慣的「不確定現象」的數學化度量。[^信息熵]

$$
\mathrm H (X) = \mathrm{E}[\mathrm{I}(X)] = \mathrm{E}[-\ln(\mathrm{P}(X))]
$$

其中 $I$ 為夏農資訊，被定義為：
$$
I(X) = - \log_2 \mathrm{P}(X)
$$
我們可以注意到當中的 $-\log_2 p_i$ 所描述的意義為：「事件發生的機率越低，則當該事件發生時所夾帶的資訊越大」，因此夏農熵也是對不確定的夏農資訊的期望值，亦可寫作：
$$
\mathrm H (X) = - \sum_i p_i \log_2 p_i
$$

### 合成式 (Formular of Crafting)

為了方便描述合成或其他遊戲機制使資源 (items) 發生變化的過程，我借用了化學反應式的形式來表達：
$$
aX + bY \xrightarrow[P]{} cZ
$$

$a,b,c$：原料或產物的數量
$X,Y$：原料，合成過程會被消耗的物品
$Z$：產物
$P$：合成途徑，參與合成但是不會被消耗的物品。

### 資源的資訊量 (Information of Items)

Minecraft 世界在本質上就是一團數位資料，因此將其視作一串由方塊構成的資訊，並用夏農熵或夏農資訊去衡量其資訊量是十分合理的作法。對於一個不確定狀態的方塊來說，其值為：
$$
\mathrm H (X) = \mathrm{E} ( \mathrm{I}) =  - \sum_i p_i \log_2 p_i
$$
其 中$p_i$ 為某種類型的方塊出現在地圖中的機率，換句話說我們可以得知特定種類方塊其資訊量為：
$$
I_x = -\log_2 p_x
$$

### 合成的資訊量 (Information of Crafting)

天然資源能夠以其在地圖生成的機率來計算熵，但是 Minecraft 中的大部分物品需透過合成途徑獲得，當我提到合成是指：「能夠被合成式所表示的所有遊戲機制」，這些非天然物品的熵需透過計算取得。

以一個合成為例：
$$
X + Y \xrightarrow[W]{} Z
$$
$X,Y,W$ 分別代表三種不同類型的方塊，我們可以視作三個隨機事件，而這三者出現在地圖的機率分別為 $p_X, p_Y, p_W$ 並且互為獨立事件，因此我們可以得知事件 $Z$ 發生的機率為三者的機率相乘，也就是三者資訊量的加總：
$$
\begin{align}
I_Z &= -\log_2(p_X p_Y p_W) \\
&= -\log_2 p_X -\log_2 p_Y -\log_2 p_W \\
&= I_X + I_Y + I_W
\end{align}
$$


#### 數量的變化 (The ratio between resource and product)

當原料與產物的比值不為 1 時，物品的總數量發生了變化。
$$
mX \xrightarrow[P]{} nY
$$

則：
$$
H_Y = \frac{m}{n}H_X
$$

#### 合成途徑 (Crafting Path)

作為合成途徑的物品不會被消耗，因此：

$$
\begin{array}{l}
X  \xrightarrow[W]{} Y & \Delta I = I_W
\end{array}
$$

#### 多重途徑 (Multiple Crafting Path)

當一個物品有多種取得途徑時可以視作一個並聯系統 (parallel systems)，因此該物品的資訊量可以寫作：
$$
I = -\log_2 [1 - \prod_i(1-p_i)]
$$

### 零資訊的資源 (The Items with Zero Entropy)

怪物掉落物仰賴怪物的生成，但是怪物生成的機率並不是與空間關聯，而是與時間關聯的，以空間機率考慮：
$$
H |_{\Delta t = 0}= -\lim_{p \rightarrow0^+} p\log p = 0
$$

若或是考慮其在無窮的時間中能夠被無限生成，事件發生的機率為 1，因此：
$$
H |_{t \rightarrow \infty} = -\log(1) = 0
$$

### 環境的資訊量 (Information of Environment)

當我們要量化系統的資訊量時，必須先界定所謂的「系統」。要定義一個系統，我們要給定一個範圍（空間大小）以及具體包含了多少方塊或物品。以下有三種定義應該是我們比較常用的系統類型：
1. 完整系統
    - 在一劃定的範圍內，所包含的方塊、收納方塊內容物、掉落物與玩家物品欄（裝備欄）內容物。
3. 方塊系統
    - 在一劃定的範圍內，所包含的方塊與收納方塊內容物。
5. 玩家系統
    - 玩家物品欄（裝備欄）內容物。

透過到目前為止建立的規則，我們可以量化一個系統的熵，而該值能透過統計地圖中的方塊與實體取得。隨著 agent 在環境中活動，我們可以預期環境的熵會因此發生改變，這個變化量便可做為評量 agent 的指標之一。

## 資訊量表 (Table of Items Information)

以下的資訊量評估值僅供參考，過程並不嚴謹並且沒有對所有的物品進行計算。目的只是透過實做示範如何實踐本文建構的理論，有興趣的人可以自行用更嚴謹的方式建構完整的遊戲物件資訊量表。

### 天然資源 (Natual Resource)

使用 Cuberite 1.7.X-linux64[^Cuberite-release] 生成地圖並搭配插件[^statistics-plugin]統計方塊數量。總共抽樣 10 次，每次都會將地圖檔案刪除以生成新的種子。為了簡化數據，將紅花與黃花視為同樣的東西，並將流動水、流動岩漿、鵝卵石、火把、火焰、生怪磚、箱子與枯萎灌木移除並用空氣取代。統計資料如下表：

| 方塊             | 數量      | 生成機率  | 資訊量     | 熵        |
| ---------------- | --------- | --------- | ---------- | --------- |
| Air              | 151464079 | 0.7506049 | 0.4138744  | 0.3106562 |
| Bedrock          | 788224    | 0.0039062 | 8.0000287  | 0.0312495 |
| Brown Mushroom   | 648       | 0.0000032 | 18.2484248 | 0.0000586 |
| Cactus           | 11        | 0.0000001 | 24.1288432 | 0.0000013 |
| Clay             | 8790      | 0.0000436 | 14.4866274 | 0.0006310 |
| Coal Ore         | 345962    | 0.0017145 | 9.1880208  | 0.0157526 |
| Cobweb           | 1998      | 0.0000099 | 16.6239340 | 0.0001646 |
| Diamond Ore      | 19629     | 0.0000973 | 13.3275758 | 0.0012964 |
| Dirt             | 2347857   | 0.0116352 | 6.4253617  | 0.0747603 |
| Double Plant     | 14242     | 0.0000706 | 13.7904107 | 0.0009733 |
| Fence            | 8543      | 0.0000423 | 14.5277478 | 0.0006151 |
| Flower           | 4014      | 0.0000199 | 15.6174499 | 0.0003107 |
| Gold Ore         | 43697     | 0.0002165 | 12.1730282 | 0.0026360 |
| Grass            | 471646    | 0.0023373 | 8.7409299  | 0.0204303 |
| Gravel           | 534501    | 0.0026488 | 8.5604417  | 0.0226750 |
| Iron Ore         | 395336    | 0.0019592 | 8.9955550  | 0.0176237 |
| Lapis Lazuli Ore | 17690     | 0.0000877 | 13.4776284 | 0.0011815 |
| Leaves           | 382779    | 0.0018969 | 9.0421227  | 0.0171522 |
| Lily Pad         | 122       | 0.0000006 | 20.6575375 | 0.0000125 |
| Obsidian         | 2390      | 0.0000118 | 16.3654799 | 0.0001938 |
| Rail             | 2528      | 0.0000125 | 16.2844941 | 0.0002040 |
| Red Mushroom     | 974       | 0.0000048 | 17.6604969 | 0.0000852 |
| Redstone Ore     | 160117    | 0.0007935 | 10.2995079 | 0.0081725 |
| Sand             | 272220    | 0.0013490 | 9.5338613  | 0.0128615 |
| Sandstone        | 109888    | 0.0005446 | 10.8426005 | 0.0059045 |
| Snow             | 3033      | 0.0000150 | 16.0217451 | 0.0002408 |
| Still Lava       | 158088    | 0.0007834 | 10.3179065 | 0.0080834 |
| Still Water      | 3281908   | 0.0162640 | 5.9421715  | 0.0966437 |
| Stone            | 40812030  | 0.2022507 | 2.3057837  | 0.4663463 |
| Sugar Canes      | 41        | 0.0000002 | 22.2307228 | 0.0000045 |
| Tallgrass        | 66818     | 0.0003311 | 11.5603257 | 0.0038279 |
| Vines            | 1179      | 0.0000058 | 17.3849268 | 0.0001016 |
| Wood Plank       | 12762     | 0.0000632 | 13.9487080 | 0.0008822 |
| Wood             | 55614     | 0.0002756 | 11.8251144 | 0.0032591 |



### 加工品 (Products)

#### 木板

$$
\text{Wood} \xrightarrow[]{} 4 \text{ Wood Plank}
$$

$$
\begin{align}
I_{WP} &= \frac1{4} I_{W} = 0.25 \cdot 11.8\\
&= 2.95
\end{align}
$$

#### 工作台

$$
4 \text{ Wood Plank} \xrightarrow[]{}  \text{Crafting Table}
$$

$$
\begin{align}
I_{CT} &= 4 I_{WP} = 4 \cdot 2.95 \\
&= 11.8
\end{align}
$$

#### 木棒

$$
2 \text{ Wood Plank} \xrightarrow[]{} 4  \text{ Stick}
$$

$$
\begin{align}
I_{S} &= \frac{2}{4} I_{WP} = 0.5 \cdot 2.95 \\
&= 1.475
\end{align}
$$

#### 木鎬

$$
3  \text{ Wood Plank}  + 2 \text{ Stick}
\xrightarrow[\text{Crafting Table}]{} 
\text{ Wooden Pickaxe}
$$

$$
\begin{align}
I_{\text{WPickaxe}}
&= 3 I_{\text{WPlank}} + 2 I_{S}  + I_{CT}\\
&= 3 \cdot 2.95 + 2 \cdot 1.475 + 11.8\\
&= 23.6
\end{align}
$$

#### 鵝卵石

為了簡化計算，下列過程不考慮其他材質的鎬挖掘的情況。

$$
\text{ Stone }
\xrightarrow[\text{Wooden Pickaxe}]{} 
\text{ Cobblestone}
$$

$$
\begin{align}
I_{C}
&= I_{S} + I_{WP} \\
&= 2.31 + 23.6 \\
&= 25.91
\end{align}
$$

#### 熔爐

$$
8\text{ Cobblestone }
\xrightarrow[\text{Crafting Table}]{} 
\text{ Furnace}
$$

$$
\begin{align}
I_{F}
&= 8I_{C} + I_{CT} \\
&= 8 \cdot 25.91 + 11.8 \\
&= 219.08
\end{align}
$$

#### 石鎬

$$
3 \text{ Cobblestone}  + 2 \text{ Stick}
\xrightarrow[\text{Crafting Table}]{} 
\text{ Stone Pickaxe}
$$

$$
\begin{align}
I_{\text{SP}}
&= 3 I_{\text{C}} + 2 I_{S}  + I_{CT}\\
&= 3 \cdot 25.91 + 2 \cdot 1.475 + 11.8\\
&= 92.48
\end{align}
$$

#### 鐵礦

為了簡化計算，下列過程不考慮其他材質的鎬挖掘的情況。

$$
\text{ Iron Ore }
\xrightarrow[\text{Stone Pickaxe}]{} 
\text{ Iron Ore Item}
$$

$$
\begin{align}
I_{IOI}
&= I_{IO} + I_{SP} \\
&= 9.00 + 92.48 \\
&= 101.48
\end{align}
$$

#### 煤

為了示範並聯系統的計算，以下僅考慮木鎬與石鎬的挖掘途徑。

$$
\text{ Coal Ore }
\xrightarrow[\text{Wooden(Stone) Pickaxe}]{} 
\text{ Coal}
$$

$$
\begin{align}
I_{C1}
&= I_{CO} + I_{WP} \\
&= 9.18 + 23.6 \\
&= 32.78
\end{align}
$$

$$
\begin{align}
I_{C2}
&= I_{CO} + I_{SP} \\
&= 9.18 + 92.48 \\
&= 101.66
\end{align}
$$

$$
\begin{align}
p_1 = 2^{-I_1} = 2^{-32.78} = 1.35592835311 \cdot 10^{-10} \\
p_2 = 2^{-I_2} = 2^{-101.66} = 2.49626473127 \cdot 10^{-31} \\
p = 1 - (1-p_1)(1-p_2) = 1.355928702651 \cdot 10^{-10}
\end{align}
$$

$$
I_C = -\log_2 p = 32.78
$$

#### 鐵錠

$$
\text{ Iron Ore Item} + \frac1{8} \text{ Coal}
\xrightarrow[\text{Furnace}]{} 
\text{ Iron Ingot}
$$

$$
\begin{align}
I_{II}
&= I_{IOI} + \frac1{8} I_{C} + I_{F} \\
&= 101.48 +  0.125 \cdot  32.78 + 219.08\\
&= 324.6575
\end{align}
$$

### 資訊量總表 (The Table)

正如我提過得，本文並沒有計算所有物品的資訊量，僅是將先前統計或計算得到的數值做個整理，因此這個表並不完整。

| 方塊/物品      | 資訊量 | 方塊/物品        | 資訊量 |
| -------------- | ------ | ---------------- | ------ |
| Iron Ingot     | 324.66 | Lapis Lazuli Ore | 13.48  |
| Furnace        | 219.08 | Diamond Ore      | 13.33  |
| Iron Ore Item  | 101.48 | Gold Ore         | 12.17  |
| Stone Pickaxe  | 92.48  | Wood             | 11.83  |
| Coal           | 32.78  | Crafting Table   | 11.80  |
| Cobblestone    | 25.91  | Tallgrass        | 11.56  |
| Cactus         | 24.13  | Sandstone        | 10.84  |
| Wooden Pickaxe | 23.60  | Still Lava       | 10.32  |
| Sugar Canes    | 22.23  | Redstone Ore     | 10.30  |
| Lily Pad       | 20.66  | Sand             | 9.53   |
| Brown Mushroom | 18.25  | Coal Ore         | 9.19   |
| Red Mushroom   | 17.66  | Leaves           | 9.04   |
| Vines          | 17.38  | Iron Ore         | 9.00   |
| Cobweb         | 16.62  | Grass            | 8.74   |
| Obsidian       | 16.37  | Gravel           | 8.56   |
| Rail           | 16.28  | Bedrock          | 8.00   |
| Snow           | 16.02  | Dirt             | 6.43   |
| Flower         | 15.62  | Still Water      | 5.94   |
| Fence          | 14.53  | Wood Plank       | 2.95   |
| Clay           | 14.49  | Stone            | 2.31   |
| Wood Plank     | 13.95  | Stick            | 1.48   |
| Double Plant   | 13.79  | Air              | 0.41   |

## 結語

就如像詹姆斯·拉夫洛克(James Lovelock)所說的[^James-Lovelock]：
> I’d look for an entropy reduction, since this must be a general characteristic of life.

我們可以透過 agent 對環境進行改造從而造成的熵減量，作為衡量策略的方法：
$$
\Delta S_{\pi,t}  = S_o - S_{\pi,t} \\
\pi^* = \arg \min_{\pi} \Delta S_{\pi,t}
$$



[^信息熵]: 信息熵是什么？ - 知乎. (返朴). Retrieved 2020-05-31, from https://www.zhihu.com/question/22178202/answer/667876061

[^Cuberite-release]: Releases · cuberite/cuberite. (cuberite). Retrieved 2020-05-31, from https://github.com/cuberite/cuberite/releases/download/1.7EOL/Cuberite-linux64.tar.gz

[^statistics-plugin]: FlySkyPie/cuberite-block-counter: To make statistics of blocks. Retrieved 2020-05-31, from https://github.com/FlySkyPie/cuberite-block-counter

[^James-Lovelock]: Lovelock, James (1979). GAIA – A New Look at Life on Earth. Oxford University Press. ISBN 978-0-19-286218-1.

###### tags: `The Key Of Huanche`
