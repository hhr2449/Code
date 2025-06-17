## 3.尝试实现XML解析器



### （1）API设计与实现

#### XML文档的格式

* 节点（node）或者说是元素（element）

  ```xml
  <?xml version="1.0" encoding="utf-8"?>
  <students>
  	<student id="1" class="101">
  		<name>大明</name>
  		<age>14</age>
  		<gender>male</gender>
  	</student>
  	<student id="2" class="102">
  		<name>玲玲</name>
  		<age>15</age>
  		<gender>female</gender>
  	</student>
  	<student id="3" class="103">
  		<name>汤姆</name>
  		<age>16</age>
  		<gender>male</gender>
  	</student>
  </students>
  ```

xml的结构是一个树状的结构，以这个为例：

* students是一个根节点
* 根节点一下有三个student子节点
* 每个student节点又有name,age,gender三个子节点
* student节点有id和class两个属性

#### API设计

设计类：Xml（就是Xml中的节点）,最后我们会将Xml文件解析为一个Xml类，方便使用

成员变量：每个节点有名称，内容，属性，可能会有子节点

名称和内容一定会有，可以使用string来表示

属性可有可无，而且其是由属性名和属性内容构成的，所以可以使用键值对map来表示

子节点可以使用list来维护

考虑效率问题，如果简单的使用string等值方式来储存数据，那么进行数据的拷贝的时候会出现深度拷贝从而降低效率，所以使用指针来维护数据

1. 构造函数：包含四种构造方式

直接构造，传入name构造（包含string和char *两种），拷贝构造

2. name相关操作

   * getName()获取节点的名称（没有设置名称则返回空字符串）
   * setName()设置节点的名称（注意如果不是空指针，则应该先delete再new

3. content相关操作

   * 和name类似，get和set

4. attribute相关操作

   * getAttri():传入属性名key，获取key对应的属性值，注意如果没有则返回空
   * setAttri():传入key和value，建立一个新的属性
   * rmAttri():根据key删除key对应的那条属性

5. child相关操作

   * 仍然是访问，设置，删除的思路

   * 访问：重载[]运算符

     1. 通过下标访问：先验证范围，超出范围抛出错误，然后使用迭代器获取对应下标的子节点
     2. 通过名称访问：遍历所有子节点，返回第一个符合名称的子节点，注意这里如果找不到节点则新建一个

   * 加入节点：addChild()函数：传入一个Xml对象，直接push_back即可

   * 删除节点：

     1. 这里要特别注意，我们是使用指针来管理相关数据的，所以在清除的时候要清除指针指向的内存

     2. 成员函数clear():用于清除节点，其中name,content,attribute好清理，直接delete然后置空即可，但是要注意child，这个是一个储存了Xml类型数据的list，所以清除节点的时候要遍历child，递归清除子节点

        clear()的使用要注意，很容易产生重复delete的错误（因为清除节点后如果该节点是子节点，那么它的空指针任然存在于某个节点的child list里），必须保证：要么直接清除根节点，要么清除节点的同时把list中的对应节点清除

     3. rmChild()：根据索引或者名称清除节点，只需要找到对应节点，然后调用clear并且erase list中对应部分即可

   * 为了实现类似其他容器的操作，实现了begin(),end(),erase(),size()函数，只需要调用child中相关函数即可实现

6. 格式化输出

   * 维护一个sstream，将各种元素按照Xml文件的相关格式排列进去即可

### （2）paser的实现

![image-20250617235524355](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250617235524355.png)

![image-20250617235553197](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250617235553197.png)

### (3)测试

* test.cpp是测试程序，其中test1()对Xml类的各种功能进行了测试，test2()和test3()对Parser进行了测试，测试文件为test1.xml,test2.xml，其中对test2.xml的解析进行了时间测试，10000次解析大约耗时2450ms.