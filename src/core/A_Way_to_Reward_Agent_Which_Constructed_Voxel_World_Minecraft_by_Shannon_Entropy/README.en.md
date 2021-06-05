A Way to Reward Agent Which Constructed Voxel World (Minecraft) by Shannon Entropy
===

## Evaluate resources
We can evaluate scarcity of resources intuitively; the more rare it is, the more value it is. But scarcity of economics are measured by supply and demand, it can't be a unit which had clearly definition. We can get probability of resources generated on map, but the probability wasn't enough to measured agent, it needed been processed additionally.

### Shannon Entropy and Shannon Information
The nature of Shannon entropy is mathematics quantity which well known "uncertainty of phenomenon".[^信息熵]

$$
\mathrm H (X) = \mathrm{E}[\mathrm{I}(X)] = \mathrm{E}[-\ln(\mathrm{P}(X))]
$$


and $I$ is Shannon Information, it be defined as:

$$
I(X) = - \log_2 \mathrm{P}(X)
$$

We can noted the meaning of $-\log_2 p_i$ is "the lower the probability of an event, the greater the information carried when the event occurs", so Shannon entropy is expected value of Shannon information, can be express by:

$$
\mathrm H (X) = - \sum_i p_i \log_2 p_i
$$

### Formula of Crafting
To describe pattern of items changes easily, which caused by crafting or another mechanism in the game, I borrow the form of chemical equation:

$$
aX + bY \xrightarrow[P]{} cZ
$$

$a,b,c$：amount of materials or products
$X,Y$：materials, items would vanished after crafting process
$Z$：products
$P$：the path of crafting, item(s) won't vanished after crafting process

### Information of Items
The nature of Minecraft World are a bunch of digital data, so were reasonably considered it as a string of information, and quantify it as Shannon Entropy or Information. For a block which status was uncertain, the value is:

$$
\mathrm H (X) = \mathrm{E} ( \mathrm{I}) =  - \sum_i p_i \log_2 p_i
$$

and $p_i$ is probability of (some type of) block generated in map, therefore we can get information of block of certain type by:

$$
I_x = -\log_2 p_x
$$

### Information of Crafting
It could calculation entropy of nature resources by probability of generated in the map, but most of items are obtained by crafting in Minecraft, when I mention "crafting" are meaning "the mechanism can be expressed by formula of crafting in the game". Need to gain entropy of non-nature items through calculation.

Let do a crafting example:

$$
X + Y \xrightarrow[W]{} Z
$$

$X,Y,W$ represents three different types of blocks, can be treated as three randomly independently event, and their probability of exists in map are $p_X, p_Y, p_W$, so we can get probability of event $Z$ happened was multiplied by probabilities, also was summing by information of probabilities:

$$
\begin{align}
I_Z &= -\log_2(p_X p_Y p_W) \\
&= -\log_2 p_X -\log_2 p_Y -\log_2 p_W \\
&= I_X + I_Y + I_W
\end{align}
$$


#### The Ratio Between Material(s) and Product(s)
When the ratio isn't 1, total number of items would changed.

$$
mX \xrightarrow[P]{} nY
$$

and:

$$
H_Y = \frac{m}{n}H_X
$$

#### Crafting Path
The item(s) won't vanished as crafting path in the process, so:

$$
\begin{array}{l}
X  \xrightarrow[W]{} Y & \Delta I = I_W
\end{array}
$$

#### Multiple Crafting Path
When there are multiple path to gain item(s), it can been treats as a parallel system, therefore, the information of products can be expressed by:

$$
I = -\log_2 [1 - \prod_i(1-p_i)]
$$

### The Items with Zero Entropy
The probability of items dropped by monster, are affected by probability of monster generation, and its not related space, but time, so:

$$
H |_{\Delta t = 0}= -\lim_{p \rightarrow0^+} p\log p = 0
$$

or consider it could been generated in infinity time, the probability of generation is 1, therefor:

$$
H |_{t \rightarrow \infty} = -\log(1) = 0
$$

### Information of Environment
We must define "system", when quantified information of system, so need to defined a range of space and how many blocks or items contained in the space.There are 3 kind of definition of system which common been used under below:

1. Complete System
    - Blocks, items in inventory block, item entity dropped and items in player inventory, which contained in a limited space.
3. Block System
    - Blocks and items in inventory block, which contained in a limited space.
5. Player System
    - Items in the player inventory.

We can quantify entropy of system through rules has been created, and intervening variables can been gain by making statistics on map. We can expect the entropy of environment would changed through behavior of agent, therefore those changes could be one of index of evaluated the agent.

## Table of Items Information
The following information evaluation value is for reference only, there are not included every items in the game, and process are not very rigorous. The goal is demonstrated the theory of this article, anyone are interested can finished the table by self.

### Natual Resource
Using Cuberite 1.7.X-linux64[^Cuberite-release] to generate map and making statistics by plugin[^statistics-plugin]. There were sampling 10 times, and remove map file to generate new seed every time. To simplify data, I merged yellow flower and red flower, removed flowing water, flowing lava, cobblestone, torch, flame, monster spawner, chest and dead bush, replace them by air.

| Block        | Count     | Probability    | Information     | Entropy        |
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



### Products
#### Wood Plank
$$
\text{Wood} \xrightarrow[]{} 4 \text{ Wood Plank}
$$

$$
\begin{align}
I_{WP} &= \frac1{4} I_{W} = 0.25 \cdot 11.8\\
&= 2.95
\end{align}
$$

#### Crafting Table
$$
4 \text{ Wood Plank} \xrightarrow[]{}  \text{Crafting Table}
$$

$$
\begin{align}
I_{CT} &= 4 I_{WP} = 4 \cdot 2.95 \\
&= 11.8
\end{align}
$$

#### Stick
$$
2 \text{ Wood Plank} \xrightarrow[]{} 4  \text{ Stick}
$$

$$
\begin{align}
I_{S} &= \frac{2}{4} I_{WP} = 0.5 \cdot 2.95 \\
&= 1.475
\end{align}
$$

#### Wooden Pickaxe
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

#### Cobblestone
To simplify calculation, there's not consider crafting path with another type of pickaxe except wooden one.

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

#### Furnace
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

#### Stone Pickaxe
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

#### Iron Ore Item
To simplify calculation, there's not consider crafting path with another type of pickaxe except stone one.

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

#### Coal
To demonstrate calculation of parallel system, there's consider crafting path with wooden and stone pickaxe.

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
p_1 = 2^{-I_1} = 2^{-32.78} = 1.35592835311 \cdot 10^{-10} \\
p_2 = 2^{-I_2} = 2^{-101.66} = 2.49626473127 \cdot 10^{-31} \\
p = 1 - (1-p_1)(1-p_2) = 1.355928702651 \cdot 10^{-10}
$$

$$
I_C = -\log_2 p = 32.78
$$

#### Iron Ingot
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

### The Table
It is summary those value are calculated or mention in this article, and just as I said, this article didn't calculated all information of items in the game, therefore the table are unfinished:


| Block/Item     | Information (bit) | Block/Item         | Information (bit) |
| -------------- | ------ | ---------------- | ------ |
| Iron Ingot     | 324.66 | Lapis Lazuli Ore | 13.48  |
| Furnace        | 219.08 | Diamond Ore    | 13.33  |
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

## Conclusion
Just like James Lovelock said[^James-Lovelock]:

> I’d look for an entropy reduction, since this must be a general characteristic of life.

We can quantify extropy which agent created by reform the environment, to measue the policy:

$$
\Delta H_{\pi,t}  = H_o - H_{\pi,t} \\
\pi^* = \arg \min_{\pi} \Delta H_{\pi,t}
$$

[^信息熵]: 信息熵是什么？ - 知乎. (返朴). Retrieved 2020-05-31, from https://www.zhihu.com/question/22178202/answer/667876061

[^Cuberite-release]: Releases · cuberite/cuberite. (cuberite). Retrieved 2020-05-31, from https://github.com/cuberite/cuberite/releases/download/1.7EOL/Cuberite-linux64.tar.gz

[^statistics-plugin]: FlySkyPie/cuberite-block-counter: To make statistics of blocks. Retrieved 2020-05-31, from https://github.com/FlySkyPie/cuberite-block-counter

[^James-Lovelock]: Lovelock, James (1979). GAIA – A New Look at Life on Earth. Oxford University Press. ISBN 978-0-19-286218-1.

###### tags: `The Key Of Huanche`