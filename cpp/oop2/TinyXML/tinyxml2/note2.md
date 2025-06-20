1.项目整体介绍
加载并解析外部xml文件
对于节点进行各种操作（增删改查），输出xml文件
遍历xml文档
打印xml文档
错误处理（返回错误码）
介绍这几个功能，并且配上相关测试代码
2.代码框架分析
拉个表格介绍给个类及其功能
画UML图介绍核心功能类的关系：
xmlNode xmlText xmlComment xmlUnknown xmlAttribute xmlDeclaration
介绍xmlVisitor及访问者模式
简要介绍功能类（strPair，DynArray，MemPool）
3.介绍具体功能点
（1）节点操作
（2）遍历xml文档
可以介绍继承和多态
内存池，更高明的类型转换函数（运用虚函数和多态实现）


三、面向对象设计思想与方法 
1. 封装（Encapsulation）
 StrPair 的延迟处理 ： StrPair 封装了字符串的解析逻辑（如实体替换、换行归一化），但实际处理（ GetStr() ）延迟到首次访问时执行。这种“惰性求值”减少了初始解析的计算开销，提高效率。
  内存池 MemPoolT ：通过模板类封装内存分配逻辑，隐藏底层内存块管理细节，避免频繁 new/delete 带来的性能损耗。
2. 继承与多态（Inheritance & Polymorphism）
  XMLNode 基类 ：定义所有节点的通用接口（如 DeepClone() 、 Accept() 、 DeleteChildren() ），子类通过重写实现特定行为。
 XMLVisitor 访问者模式 ：通过多态实现对文档树的灵活遍历。不同 XMLVisitor 实现（如 XMLPrinter ）可按需处理节点，符合“开闭原则”。
3.  组合优于继承（Composition Over Inheritance）
- XMLDocument 管理节点 ： XMLDocument 包含 _elementPool 、 _attributePool 等内存池对象，通过组合方式管理节点生命周期，而非通过继承扩展功能。
- XMLElement 包含属性 ： XMLElement 持有 XMLAttribute 链表，通过组合关系表示元素与属性的“拥有”关系，而非继承。
-  四、设计模式应用
-   1. 访问者模式（Visitor Pattern）
- 核心类 ： XMLVisitor 接口与 XMLPrinter 实现。
- 动机 ：分离数据结构（文档树）和操作（如序列化、验证），允许为节点添加新操作而不修改节点类。
- 实现 ：
  - XMLNode 定义 Accept(XMLVisitor*) 方法，调用 visitor->Visit*() 回调。
  - XMLPrinter 实现 VisitEnter() 、 VisitExit() 等方法，生成 XML 字符串。 
  - 2. 工厂模式（Factory Pattern）
- 核心类 ： XMLDocument 中的 NewElement() 、 NewComment() 等方法。
- 动机 ：统一节点创建逻辑，隐藏具体节点类型的构造细节（如内存池分配）。
- 实现 ：
-  3. 享元模式（Flyweight Pattern）
- 核心类 ： MemPoolT 内存池模板类。
- 动机 ：减少频繁创建/销毁小对象（如 XMLAttribute 、 XMLElement ）的内存开销，提高性能。
- 实现 ：
  - 预分配内存块（ Block ），按需分配 Item 单元。
  - 回收对象时将其放回空闲链表，避免重复 new 操作。
  ```cpp
  template< size_t ITEM_SIZE >
  class MemPoolT : public MemPool {
      union Item { ... }; // 内存单元
      DynArray<Block*, 10> _blockPtrs; // 内存块列表
      Item* _root; // 空闲链表头
  };
   ```
  ```
   4. 策略模式（Strategy Pattern）
- 核心类 ： XMLUtil::SetBoolSerialization() 方法。
- 动机 ：允许用户自定义布尔值的序列化字符串（如将 true 改为 TRUE ），提高灵活性。
- 实现 ：通过静态成员变量 writeBoolTrue 和 writeBoolFalse 动态切换序列化策略。
  ```cpp
  void XMLUtil::SetBoolSerialization(const char* writeTrue, const char* writeFalse) {
      writeBoolTrue = writeTrue ? writeTrue : "true";
      writeBoolFalse = writeFalse ? writeFalse : "false";
  }
   ```
  ```
