# 環驅之鑰

![](./img/title.png)

為本人專案導向學習的主要專案之一。旨在建立以布林代數為基礎描述智能體的理論及應用框架。本項目包含了與人工智慧領域關聯較高；且涉及核心算法（或 spec）的核心項目 (core subject) ，與關聯性較低的各種應用項目的次級項目 (minor subject)。

## 動機
- [論開放世界原生智能體的發想](./core/the_idea_of_native_agents_in_a_open_world.md)
## 基礎理論

- [熵庫 (Entropy Reservoir) 假說](/@FlySkyPie/HyFHXsQ9X)
- [一種表達智能的方法](/@FlySkyPie/HJbCLuPDr)
- [布林類神經網路](/@FlySkyPie/B1J1slSLB)

## 演算法

- [一種布林拓撲進化類神經網路基因演算法](/@FlySkyPie/SkrvVy0uX)
- [一種以拓撲排序作為遞迴中止條件之方法](/@FlySkyPie/SJlrATeumN)
- [一種透過人工介入編輯網路的方法發想以及網路內化假說](/@FlySkyPie/H1WPXS0TV)

## 延伸理論

- [智能體資訊複雜度](/@FlySkyPie/SJmUYviqQ)
- [一種利用資訊熵獎勵智能體構建方塊世界(Minecraft)的方法](/@FlySkyPie/SJeX9awaQ)

## 專案的命名

一個簡單的邏輯映射關係可以用 DNF (Disjunctive normal form) 表示，這樣的映射邏輯其輸出只跟當下的輸入有關；換句話說它沒有記憶能力。

![ABC + ABC' + AB'C](./img/79939c5877f6d9ddf28719167fd946a3_simple_dnf.png)

這個映射邏輯也可以用 DAG (Directed Acyclic Graph) 描述，

![](./img/c02e0f024c944e11a2f54f462d178b8e_simple_dag.png)

為了讓它有記憶的能力，我們把它加上遞歸 (Recurrent) 的連結，

![](./img/82459a1e97d5a361429a8743f51dec07_simple_dag_recurrent.png)

此時這個映射邏輯部份的邏輯便受到這個環 (Directed cycle graph) 的支配，因此一個有學習能力的智能體其表現出「學習」的行為是受到這些環所支配的，「環驅」就是「受到圖環驅動」的意思。

![](./img/ac75791f18c9057a4178b2759ec80294_simple_dcg.png)

[![創用 CC 授權條款](https://i.creativecommons.org/l/by-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-sa/4.0/)  
Wei Ji以[創用CC 姓名標示-相同方式分享 4.0 國際 授權條款](http://creativecommons.org/licenses/by-sa/4.0/)釋出。

###### tags: `The Key Of Huanche` 
