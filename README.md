本仓库包含了常见的算法和数据结构。主要面向有经验的程序员，提供参考。

此 README.md 文件保存了大多数算法和数据结构的文件索引或文字说明。如果标题可以点击，即可跳转至相关文件。

文件中使用了 LaTex 公式，GitHub 上显示失效，请选择其它文本编辑器查看，比如 VScode。

- [1. 算法](#1-算法)
  - [1.1. 排序 Sort](#11-排序-sort)
  - [1.2. 全排列 Full Permutation](#12-全排列-full-permutation)
  - [1.3. 查找 Search](#13-查找-search)
    - [1.3.1. 二分查找 Binary Search](#131-二分查找-binary-search)
    - [1.3.2. 散列 Hash](#132-散列-hash)
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
- [2. 数据结构](#2-数据结构)
  - [2.1. 高精度整数 Big Integer](#21-高精度整数-big-integer)
  - [2.2. 分数 Fraction](#22-分数-fraction)

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
* 链表法：`hash(key)` 值相同的保存在相同的链上

## 1.4. [快速幂 Fast Power](./fastPower.cpp)

## 1.5. [最大公约数和最小公倍数 Greatest Common Divisor & Least Common Multiple](./gcd_lcm.cpp)

## 1.6. [素数 Prime Number](./prime.cpp)

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
* 四舍五入
  * C 函数：`Round(double x) = int(x + 0.5)`
* 上下取整的关系
  * 数学公式：$\lceil x \rceil = \lfloor x \rfloor + \Delta,\quad \Delta = 1 - \lfloor 1.0 \cdot \lfloor x + 1 \rfloor - x \rfloor$

## 1.8. 有限状态机 Finite State Machine

针对字符串处理的相关题目，可以使用 FSM 解决。首先分清楚两个概念

* 有限的状态节点
* 表示状态转移条件的有向边

在做题时，首先定义好要解决问题的字符串模式，接下来定义有穷的状态码及其内涵，最后找到所有的可状态转移条件。

> PAT B1003 “我要通过”的题解是个很好的例子，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/B1003.cpp` 中查看题解。

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

# 2. 数据结构

## 2.1. 高精度整数 Big Integer

[源码](./data_structure/BigInteger.cpp)

## 2.2. 分数 Fraction

[源码](./data_structure/Fraction.cpp)