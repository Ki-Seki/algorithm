本仓库包含了常见的算法和数据结构。主要面向有经验的程序员，提供参考。

此 README.md 文件保存了大多数算法和数据结构的文件索引或文字说明。如果标题可以点击，即可跳转至相关文件。

文件中使用了 LaTex 公式，GitHub 上显示失效，请选择其它文本编辑器查看，比如 VScode。

- [1. 算法](#1-算法)
  - [1.1. 排序 Sort](#11-排序-sort)
  - [1.2. 全排列 Full Permutation](#12-全排列-full-permutation)
  - [1.3. 查找 Search](#13-查找-search)
    - [1.3.1. 二分查找 Binary Search](#131-二分查找-binary-search)
    - [1.3.2. 散列 Hash](#132-散列-hash)
    - [1.3.3. 深度优先搜索 Depth First Search](#133-深度优先搜索-depth-first-search)
    - [1.3.4. 广度优先搜索 Breath First Search](#134-广度优先搜索-breath-first-search)
  - [1.4. 快速幂 Fast Power](#14-快速幂-fast-power)
  - [1.5. 最大公约数和最小公倍数 Greatest Common Divisor & Least Common Multiple](#15-最大公约数和最小公倍数-greatest-common-divisor--least-common-multiple)
  - [1.6. 素数 Prime Number](#16-素数-prime-number)
  - [1.7. 取整与舍入 Round](#17-取整与舍入-round)
  - [1.8. 有限状态机 Finite State Machine](#18-有限状态机-finite-state-machine)
  - [1.9. 扩展欧几里得算法 Extended Euclidean algorithm](#19-扩展欧几里得算法-extended-euclidean-algorithm)
    - [1.9.1. 问题 1：ax + by = gcd(a, b) 的整数解？](#191-问题-1ax--by--gcda-b-的整数解)
    - [1.9.2. 问题 2：ax + by = c 的整数解？](#192-问题-2ax--by--c-的整数解)
    - [1.9.3. 问题 3：同余式 ax ≡ c(mod m) 的整数解？](#193-问题-3同余式-ax--cmod-m-的整数解)
    - [1.9.4. 问题 4：ax ≡ 1 中 a 逆元的求解？](#194-问题-4ax--1-中-a-逆元的求解)
    - [1.9.5. 问题 5：(b / a) % m 的值计算？](#195-问题-5b--a--m-的值计算)
  - [1.10. 组合数 Combination](#110-组合数-combination)
    - [1.10.1. 问题 1：n! 中质因子的数量](#1101-问题-1n-中质因子的数量)
    - [1.10.2. 问题 2：$C^m_n$ 的计算](#1102-问题-2cm_n-的计算)
    - [1.10.3. 问题 3：$C^m_n \% p$ 的计算](#1103-问题-3cm_n--p-的计算)
  - [1.11. 基姆拉尔森公式 Kim Larson Formula](#111-基姆拉尔森公式-kim-larson-formula)
- [2. 数据结构](#2-数据结构)
  - [2.1. 高精度整数 Big Integer](#21-高精度整数-big-integer)
  - [2.2. 分数 Fraction](#22-分数-fraction)
  - [2.3. 链表 Linked List](#23-链表-linked-list)
    - [2.3.1. 动态链表 Dynamic Linked List](#231-动态链表-dynamic-linked-list)
    - [2.3.2. 静态链表 Static Linked List](#232-静态链表-static-linked-list)
  - [2.4. 树 Tree](#24-树-tree)
    - [2.4.1. 二叉树 Binary Tree](#241-二叉树-binary-tree)
      - [2.4.1.1. 一般二叉树 General Binary Tree](#2411-一般二叉树-general-binary-tree)
      - [2.4.1.2. 二叉查找树 Binary Search Tree](#2412-二叉查找树-binary-search-tree)
      - [2.4.1.3. 平衡二叉树 AVL Tree](#2413-平衡二叉树-avl-tree)
      - [2.4.1.4. 堆 Heap](#2414-堆-heap)
      - [2.4.1.5. 哈夫曼树 Huffman Tree](#2415-哈夫曼树-huffman-tree)
    - [2.4.2. 普通的树 Normal Tree](#242-普通的树-normal-tree)
      - [2.4.2.1. 一般的树 General Tree](#2421-一般的树-general-tree)
      - [2.4.2.2. 并查集 Union-find Set](#2422-并查集-union-find-set)
  - [图 Graph](#图-graph)

# 1. 算法

## 1.1. 排序 Sort

[源码](./sort.cpp)

包括以下排序算法的实现：

* 选择排序 Selection Sort
* 插入排序 Insertion Sort
* 归并排序 Merge Sort

## 1.2. [全排列 Full Permutation](./full_permutation.cpp)

## 1.3. 查找 Search

### 1.3.1. 二分查找 Binary Search

[源码](./BinarySearch.cpp)

### 1.3.2. 散列 Hash

散列本质上是查找算法。常用的哈希函数 `hash(key) = key % table_size`，其中 `table_size` 尽量为素数，减少冲突（collision）。其他处理冲突的方法：

* 线性探查法（Linear Probing）：若冲突，则 `hash(key) = (key + 1) % table_size`；
* 平方探查法（Quadratic Probing）：若冲突，则 `hash(key) = (key ± n²) % table_size`；
* 链表法：`hash(key)` 值相同的保存在相同的链表节点上

### 1.3.3. 深度优先搜索 Depth First Search

```cpp
// 使用递归实现 DFS 的模板
dfs(some_values_indicating_status)
{
  // 递归边界
  if (boundary_case)
    some_statements;
  
  // 分岔口
  // 第一种分岔口：取或不取，eg. 元素是否入栈
  // 第二种分岔口：循环，eg. 迷宫的四个方向
}
```

> DFS 例题
> 
> PAT A1103 “Integer Factorization”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/A1103.cpp` 中查看题解。

### 1.3.4. 广度优先搜索 Breath First Search

关键点：

* Node 结构体
* 标识数组，如 in_queue，is_visisted，map 变量，set 变量
* bfs
  * 参数：首元素
  * 首元素入队，首元素进行一般性操作
  * 循环：通过首元素找下一层元素

```cpp
// 使用队列 + 循环实现的 BFS 模板

// Node 结构体应该保存一个唯一能标识一个状态的一些变量的组合
// 正确定义 Node 是使用 BFS 的前提
// 访问唯一状态应当用索引，而不是用 Node 本身
struct Node {
  some_attributions;
} all_elements[];

// 记录元素是否已入过队
// 不能改成 is_visited，因为存在未被访问但已在队列中的元素，有可能导致重复入队
// 也可以对原始数据使用染色法，而不单独设置标记数组，如 in_queue 或 is_visited
// 也可以使用 map STL 来标识
bool in_queue[] = {};

void bfs(int s)  // 用 s 作索引，而非 Node 本身
{
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    Node front = all_elements[q.front()];
    q.pop();
    for (each in next_layer_of_front)
    {
      q.push(each);
      in_queue[each] = true;
    }
  }
}
```

> BFS 例题
> 
> PAT A1091 “Acute Stroke”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/A1091.cpp` 中查看题解。
> 
> CODEUP 100000609-03 “【宽搜入门】魔板”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-CODEUP/100000609-03.cpp` 中查看题解。

## 1.4. [快速幂 Fast Power](./fastPower.cpp)

## 1.5. [最大公约数和最小公倍数 Greatest Common Divisor & Least Common Multiple](./gcd_lcm.cpp)

## 1.6. 素数 Prime Number

[源码](./prime.cpp)

* sqrt 优化：素数判断
* 埃氏（Eratosthenes）筛法：求素数表

## 1.7. 取整与舍入 Round

* 向下取整
  * C 函数：`Rounded_down(double x) = int(x)`
* 向上取整
  * 数学公式：$Ru(x) = \lfloor x \rfloor + 1 - \lfloor 1.0 \cdot \lfloor x + 1 \rfloor - x \rfloor$
  * C 函数：`Rounded_up(double x) = int(x) + 1 - int(1.0*int(x+1)-x)`
* 向上取整的整除
  * C 函数：`Rounded_up(int a, int b) = (a - 1) / b + 1;`
  * 或 `Rounded_up(int a, int b) = (a + b - 1) / b`，其中 `b - 1` 是偏置量（biasing），这种方法常见于对负数算术右移的舍入中
* 四舍五入
  * C 函数：`Round(double x) = int(x + 0.5)`
* 上下取整的关系
  * 数学公式：$\lceil x \rceil = \lfloor x \rfloor + \Delta,\quad \Delta = 1 - \lfloor 1.0 \cdot \lfloor x + 1 \rfloor - x \rfloor$

## 1.8. 有限状态机 Finite State Machine

针对字符串处理的相关题目，可以使用 FSM 解决。首先分清楚两个概念

* 有限的状态节点
* 表示状态转移条件的有向边

在做题时，首先定义好要解决问题的字符串模式，接下来定义有穷的状态码及其内涵，最后找到所有的可状态转移条件。

> 例子
> 
> PAT B1003 “我要通过”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/B1003.cpp` 中查看题解。
> 
> PAT A1060 “Are They Equal”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/A1060.cpp` 中查看题解。

## 1.9. 扩展欧几里得算法 Extended Euclidean algorithm

扩展欧几里得算法以 gcd 算法为基础，解决以下几个问题

### 1.9.1. 问题 1：ax + by = gcd(a, b) 的整数解？

[源码](./exGcd.cpp)

1. 求解其中一组解：联立 $a \% b = a - (a / b) * b$ 与 $ax_0 + by_0 = bx_1 + (a\%b)y_2$
2. 求解全部解：联立 $ax + by = gcd(a, b)$ 与 $a(x + s_1) + b(y - s_2) = gcd(a, b)$
3. 求解最小正整数 x' 的解：$x' = (x \% \frac{b}{gcd} + \frac{b}{gcd}) \% \frac{b}{gcd}$

### 1.9.2. 问题 2：ax + by = c 的整数解？

若 $c \% gcd = 0$，则可以将问题转化 $ax + by = gcd \leftrightarrow a \frac{cx'}{gcd} + b \frac{cy'}{gcd} = c$

若 $c \% gcd ≠ 0$，则无解

### 1.9.3. 问题 3：同余式 ax ≡ c(mod m) 的整数解？

$ax ≡ c(mod \ m)$ 等价于 $(ax - c) \% m = 0$ 等价于求解 $ax + my = c$ 中 x 的值

若 $c \% gcd(a, m) = 0$，则同余式恰好有 gcd(a, m) 个模 m 意义下不相同的解

若 $c \% gcd(a, m) ≠ 0$，则无解

### 1.9.4. 问题 4：ax ≡ 1 中 a 逆元的求解？

> **模运算下的乘法逆元**：若 $m > 1, ab ≡ 1(mod \ m)$，则 a 与 b 互为模运算下的乘法逆元。

ps. 找逆元主要是找到最小的正整数 x。

若 $gcd(a, m) = 1$，则 $ax ≡ 1(mod \ m)$ 在 (0, m) 上有唯一解；

若 $gcd(a, m) ≠ 1$，则无解。

### 1.9.5. 问题 5：(b / a) % m 的值计算？

方法一：利用逆元

$\quad (b / a) \% m$

$\leftrightarrow (b * a') \% m$

$\leftrightarrow (b \% m) * (a \% m) \% m$

方法二：利用费马小定理

> **费马小定理**：若 m 为素数且 a % m ≠ 0，则 $a^{m - 1} ≡ 1(mod \ m)$

易知，$a * a ^ {m - 2} ≡ 1(mod \ m)$，所以 $a ^ {m - 2}$ 即为逆元。通过快速幂即可求出。

方法三：硬求解

$\quad (b / a) \% m = x$

$\leftrightarrow b / a = km + x$

$\leftrightarrow b \% (am) / a = x$

## 1.10. 组合数 Combination

[源码](./combination.cpp)

组合数的计算问题与快速幂，素数筛选，阶乘质因子分解，扩展欧几里得算法等相关。组合数算法是这些算法的综合应用。

### 1.10.1. 问题 1：n! 中质因子的数量

不断除以 p 来找到规律。可以使用递推或递归求解。

### 1.10.2. 问题 2：$C^m_n$ 的计算

> 方法一：递推公式 $C^m_n = C^{m-1}_{n-1} + C^m_{n-1}$

> 方法二：公式变形，边乘边除

### 1.10.3. 问题 3：$C^m_n \% p$ 的计算

> 方法一：递推公式
> 
> $C^m_n = (C^{m-1}_{n-1} + C^m_{n-1}) \% p$

> 方法二：定义式 + 组合中各阶乘的质因子分解
> 
> 计算出 $C^m_n = \frac{n!}{m!(n-m)!}$ 中，即 n!， m!， (n-m)! 中每个的 $P_i$ 的个数，然后快速幂求解

> 方法三：m < p, p 是素数时，
> 
> 利用逆元求解
> 
> 找到分母中每一个的逆元

> 方法四：m 任意，p 是素数时，
> 
> 去除分子分母中多余素数 p + 边乘边除 + 逆元求解
> 
> 去除多余 p 归一，然后用方法三

> 方法五：m，p 均任意时，
> 
> ① 对 p 进行质因子分解；
> 
> ② 对分子分母中每一项都进行质因子分解
> 
> 分解 p 归一，然后用方法四

> 方法六：Lucas 定理
> 
> 计算 $C^m_n \% p$ 时，若 p 为素数，将 m 和 n 表示为 p 进制：
> 
> $m = m_kp^k+m_{k-1}p^{k-1}+...+m_0$
> 
> $n = n_kp^k+n_{k-1}p^{k-1}+...+n_0$
> 
> 则 $C^m_n \% p \equiv C_{n_k}^{m_k}  C_{n_{k-1}}^{m_{k-1}} ... C_{n_0}^{m_0} \% p$

## 1.11. 基姆拉尔森公式 Kim Larson Formula

是日期到星期的转换公式

```cpp
// 返回值从 0，1 ~ 7，分别代表周日，周一到周六
int kim_larson(int y, int m, int d)
{
    if (m < 3)
    {
        m += 12;
        y--;
    }
    return (1 + d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
}
```

# 2. 数据结构

## 2.1. 高精度整数 Big Integer

[源码](./data_structure/BigInteger.cpp)

## 2.2. 分数 Fraction

[源码](./data_structure/Fraction.cpp)

## 2.3. 链表 Linked List

部分线性表之间的关系

* 线性表
  * 顺序表 - 数组
  * 链表
    * 动态链表
    * 静态链表

### 2.3.1. 动态链表 Dynamic Linked List

链表内存空间在使用过程中动态生成与消灭

**步骤一：定义节点**

```cpp
struct Node {
  typename data;
  Node* next;
};
```

**步骤二：内存空间管理**

```cpp
// 使用 malloc 函数的方法
#include<cstdlib>

// 内存分配函数，若申请失败，返回空指针，NULL
Node* p = (Node*) malloc(sizeof(Node));

// 内存释放函数，释放 p 所指空间，并使其指向 NULL
free(p)
```

```cpp
// 使用 new 运算符的方法

// 内存分配运算符，若申请失败，报错
Node* p = new Node;

// 内存释放运算符，释放 p 所指空间
delete(p)
```

### 2.3.2. 静态链表 Static Linked List

因为问题规模确定且较小，实现分配好空间的链表。这类题目有较为一般的解题步骤：

*Define -> Initialize -> Purge -> Sort -> Output*

**Step 1: Define**

```cpp
struct Node {
  int addr,  // 节点地址
      data,  // 节点数据
      next;  // 节点所指
  typename xyz;  // 根据具体问题所设定的变量
} list[MAXN];
```

**Step 2: Initialize**

```cpp
for (int i = 0; i < MAXN; i++)
  list[i].xyz = a_specific_value;
```

**Step 3: Purge**

```cpp
// 从链表头一直遍历完毕，剔除无效数据
int p = begin, cnt = 0;
while (p != -1)
{
  list[p].xyz = another_specific_value;
  cnt++;
  p = list[p].next;
}
```

**Step 4: Sort**

```cpp
// 根据具体问题编写 cmp 函数
int cmp(Node a, Node b)
{
  return cmp;
}

// 将 list 排序
sort(list, list + cnt, cmp);
```

**Step 5: Output**

```cpp
// 根据具体问题，按要求输出
```

> 静态链表例题
> 
> PAT B1025 “反转链表”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/B1025.cpp` 中查看题解。
> 
> PAT A1097 “Deduplication on a Linked List”，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/A1097.cpp` 中查看题解。

## 2.4. 树 Tree

**树形态上的分类**

* 树 Tree
  * 二叉树 Binary Tree
    * 完全二叉树 Complete Binary Tree
      * 满二叉树
    * Full Binary Tree

> ps. 满二叉树和 Full Binary Tree 含义并不相同，中外间有歧义。中文语境下使用满二叉树概念即可。

**树实现上的分类**

* 动态的树：节点指针域使用地址索引，随时创建节点
  * 含数据域的节点
  * 另外包含层次号 `layer` 或 `level` 的节点
* 静态的树：节点指针域使用下标索引，创建固定大小的树
  * 普通的静态树
  * 二维化的树：对于完全二叉树来说，若从 1 开始层次化顺次索引，则任一节点 n 的左子节点为 2n，右子节点为 2n+1


### 2.4.1. 二叉树 Binary Tree

#### 2.4.1.1. 一般二叉树 General Binary Tree

[源码](./data_structure/BinaryTree.cpp)

二叉树是指节点度不超过 2 的树。有以下关键点必须掌握：

* 定义节点：`struct Node` 节点 = 数据 + 左孩子 + 右孩子 (+ 层次号)
* 新建节点：`Node* new_node(int val)` 记得初始化指针域
* 插入新节点：`void insert(Node* &root, int data)` 碰到创建新节点的地方，都要用引用
* 四种遍历：如 `void preorder(Node* root)`
* 复原二叉树：如 `Node* create_by_pre_in` 中序遍历和其他三种遍历结合都可以复原一棵二叉树

> ps. 预设二叉树一般不含重复值的节点

#### 2.4.1.2. 二叉查找树 Binary Search Tree

[源码](./data_structure/BinarySearchTree.cpp)

二叉查找树是有序的二叉树。在一般二叉树的基础上，还要掌握：

* 插入新节点：加入分支判断使二叉树满足有序的性质
* 删除元素：`void delete_node(Node* &root, int x)` 重点是保证删除后仍满足有序的性质。最简单的实现包括三层任务
  1. 递归地找到节点 x
  2. 找前、后驱（如果都没有，直接删除即可），要用到两个辅助函数，如
      * `Node* find_min(Node* root)`：寻找以 root 为根节点的树中最小权值节点
  3. 复制前驱值到当前节点，递归删除前驱节点

#### 2.4.1.3. 平衡二叉树 AVL Tree

[源码](./data_structure/AVLTree.cpp)

AVL 树加速 BST 查找速度。在 BST 的基础上，要掌握插入新节点的方法：

* 定义节点：加入 height 参数，以便计算平衡因子
* 两个获取参数的函数：
  * `int get_height(Node* root)`
  * `int get_balance_factor(Node* root)`
* 一个更新函数，应对插入后高度的变化：`void update_height(Node* root)`
* 两个旋转树的函数，以降低 root 的平衡因子：
  * `void left_rotation(Node* &root)`
  * `void right_rotation(Node* &root)`
* insert 函数：通过平衡因子，判断 LL、LR、RR、RL 四种插入情形进行旋转

#### 2.4.1.4. 堆 Heap

[源码](./data_structure/Heap.cpp)

堆的本质是一颗有序的 CBT。其应用包括优先队列、堆排序等。主要应掌握以下内容：

* 定义堆：一般是二维化的完全二叉树式的实现形式
  * 定义堆的数组、堆的大小（一般采用全局变量）
  * 堆数组下标从 1 开始计数
  * 明确是大顶堆还是小顶堆
* 辅助的调整函数
  * 包括 `void down_adjust(int low, int high)` 和 `void up_adjust(int low, int high)`
  * 包括递归和迭代两种实现方法，其中递归的要注意好递归边界的定义
  * 只用微改调整函数，就可以切换大顶堆 or 小顶堆
* 建堆：假设数组中已有初值，从最后一个非叶子节点向前进行 `down_adjust`
* 删除堆顶元素：末尾元素置顶，长度减一，`down_adjust`
* 添加元素：元素缀于末尾，`up_adjust`

堆的两个性质，实质上就是 CBT 的性质：

* $CBT 节点数 = 叶子节点数 + 非叶子节点数 = \lceil \frac{n}{2} \rceil + \lfloor \frac{n}{2} \rfloor$
* 二维化的 CBT 恰是层序遍历的结果

#### 2.4.1.5. 哈夫曼树 Huffman Tree

[源码](./data_structure/HuffmanTree.cpp)

首先应了解以下内容：

* 问题背景：合并果子问题，最短前缀编码问题
* 一些概念：
  * 路径长度：从根节点出发到该节点所经过的边数
  * 带权路径长度（Weighted Path Length）：节点权值与路径长度的乘积
  * 前缀编码：为给定的确定字符串中的字符编码时，任一个字符的编码都不是其他编码的前缀的编码形式；在哈夫曼树中，令左边为 0，右边为 1 可生成任一叶子节点的前缀编码
  * 最优二叉树：也就是哈夫曼树，因其满足前缀最短，所以称最优
* 哈夫曼树的性质：
  * 不存在度为 1 的节点
  * 权值越高的节点越靠近根节点
  * 任何一个叶子节点的编码都是唯一的，也即，满足前缀编码要求

实现方面，如果从零开始实现，代码量较大，可以根据具体问题选择部分实现哈夫曼编码的功能。以下实现方法从简单到困难递增。

* 方法一：使用 priority_queue
  * 特点：并为实现树的结构，只是求出了根节点的权值
  * 适用问题：“合并果子”
  * 具体实现：用 STL 构建小数优先的优先队列，按照 BFS 的思想逐渐合并即可
* 方法二：使用 priority_queue + binary_tree_node
  * 特点：既能实现哈夫曼树的所有功能，编码又相对简单
  * 适用问题：前缀编码
  * 具体实现：
* 方法三：使用 heap + binary_tree_node
  * 特点：可以从 0 完整的实现哈夫曼树，但编码困难
  * 适用问题：前缀编码
  * 具体实现：用 STL 构建小数优先的优先队列，

### 2.4.2. 普通的树 Normal Tree

#### 2.4.2.1. 一般的树 General Tree

[源码](./data_structure/Tree.cpp)

树这一类的题往往联系四种遍历和 DFS 与 BFS。只要掌握好这些遍历和搜索即可轻松应对。

#### 2.4.2.2. 并查集 Union-find Set

[源码](./data_structure/UnionFindSet.cpp)

并查集实质上是由数组实现的一种树。其数据结构 `set[x] = y` 表示节点 `x` 的父节点为 `y`，当且仅当 `x == y` 时，`x` 或 `y` 是根节点。应掌握：

* `int find(int x)`：包括迭代和递归两种实现
* `void union(int a, int b)`：合并 `a` 和 `b` 所在的两个集合
* 路径优化：将所有节点都指向根节点，将查找速度优化到 O(1)。包括迭代和递归两种实现

## 图 Graph