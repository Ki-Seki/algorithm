本仓库包含了常见的算法和数据结构。主要面向有经验的程序员，提供参考。

此 README.md 文件保存了大多数算法和数据结构的文件索引或文字说明。如果标题可以点击，即可跳转至相关文件。

文件中使用了 LaTex 公式，GitHub 上显示失效，请选择其它文本编辑器查看。

- [算法](#算法)
  - [排序 Sort](#排序-sort)
  - [全排列 Full Permutation](#全排列-full-permutation)
  - [二分查找 Binary Search](#二分查找-binary-search)
  - [快速幂 Fast Power](#快速幂-fast-power)
  - [最大公约数和最小公倍数 Greatest Common Divisor & Least Common Multiple](#最大公约数和最小公倍数-greatest-common-divisor--least-common-multiple)
  - [素数 Prime Number](#素数-prime-number)
  - [取整与舍入 Round](#取整与舍入-round)
  - [有限状态机 Finite State Machine](#有限状态机-finite-state-machine)
  - [散列 Hash](#散列-hash)
- [数据结构](#数据结构)
  - [高精度整数 Big Integer](#高精度整数-big-integer)
  - [分数 Fraction](#分数-fraction)

# 算法

## [排序 Sort](./sort.cpp)

* 选择排序 Selection Sort
* 插入排序 Insertion Sort
* 归并排序 Merge Sort

## [全排列 Full Permutation](./full_permutation.cpp)

## [二分查找 Binary Search](./BinarySearch.cpp)

## [快速幂 Fast Power](./fastPower.cpp)

## [最大公约数和最小公倍数 Greatest Common Divisor & Least Common Multiple](./gcd_lcm.cpp)

## [素数 Prime Number](./prime.cpp)

* sqrt 优化：素数判断
* 埃氏（Eratosthenes）筛法：求素数表

## 取整与舍入 Round

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

## 有限状态机 Finite State Machine

针对字符串处理的相关题目，可以使用 FSM 解决。首先分清楚两个概念

* 有限的状态节点
* 表示状态转移条件的有向边

在做题时，首先定义好要解决问题的字符串模式，接下来定义有穷的状态码及其内涵，最后找到所有的可状态转移条件。

> PAT B1003 “我要通过”的题解是个很好的例子，[点此处](https://github.com/Ki-Seki/solutions)，并在以下目录 `solutions/solutions-PAT/B1003.cpp` 中查看题解。

## 散列 Hash

散列本质上是查找算法。常用的哈希函数 `hash(key) = key % table_size`，其中 `table_size` 尽量为素数，减少冲突（collision）。其他减少冲突的方法：

* 线性探查法（Linear Probing）：若冲突，则 `hash(key) = (key + 1) % table_size`；
* 平方探查法（Quadratic Probing）：若冲突，则 `hash(key) = (key ± n²) % table_size`；
* 链表法：`hash(key)` 值相同的保存在相同的链上

# 数据结构

## [高精度整数 Big Integer](./data_structure/BigInteger.cpp)

## [分数 Fraction](./data_structure/Fraction.cpp)